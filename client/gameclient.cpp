#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "gameclient.h"

gameClient::gameClient()
{
  if (_shootBuf.LoadFromFile("sound/SpaceGun04.wav"))
    _shoot.SetBuffer(_shootBuf);
  if (_die1Buf.LoadFromFile("sound/enemy_dies1.wav"))
    _die1.SetBuffer(_die1Buf);
  if (_die2Buf.LoadFromFile("sound/enemy_dies2.wav"))
    _die2.SetBuffer(_die2Buf);
  if (_die3Buf.LoadFromFile("sound/enemy_dies3.wav"))
    _die3.SetBuffer(_die3Buf);
  if (_die4Buf.LoadFromFile("sound/enemy_dies4.wav"))
    _die4.SetBuffer(_die4Buf);
  if (_dieBossBuf.LoadFromFile("sound/boss_dies.wav"))
    _dieBoss.SetBuffer(_dieBossBuf);
}

gameClient::~gameClient()
{

}

void		gameClient::setLife(unsigned char nb)
{
  _life = nb;
}

unsigned char	gameClient::getLife()
{
  return (_life);
}

unsigned char	gameClient::getGame()
{
  return(_game);
}

int		gameClient::getId()
{
  return _idPlayer;
}

int		gameClient::getLevel()
{
  return (_level);
}

void		gameClient::setLevel(int level)
{
  _level = level;
}

void		gameClient::findLevel(int score)
{
  //level
  if (score >= 6000)
    this->setLevel(4);
  if (score >= 4000)
    this->setLevel(3);
  else if (score >= 2000)
    this->setLevel(2);
  else
    this->setLevel(1);
  //type arme
  if (getLevel() == 2)
    _arme = 2;
}

sf::Sprite	gameClient::getSprite()
{
  std::list<Element *>::iterator	lit;
  Element				*elem;
  std::list<sf::Sprite>::iterator       iter;

  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      elem = *lit;
      if(elem->getID() == _idPlayer)
        {
	  iter = elem->getSprite().begin();
	  return *iter;
        }
    }
  return *iter;
}

void		gameClient::fillnetwork(udpNetwork* network)
{
  std::ifstream	stream;
  std::string	buffer;
  char		temp[256];
  int		port;

  stream.open(FILESERVER);
  if(stream.is_open())
    {
      stream.getline(temp, 256, ':');
      buffer = temp;
      network->setIP(buffer);
      stream.getline(temp, 256);
      port = atoi(temp);
      network->setPort(port);
      stream.close();
    }
  else
    std::cout << "Error: can't open file!"<< std::endl;
}

void		gameClient::choosePort(int nb)
{
  if (nb == 2)
    _network->setPort(_network->getPort() + 1);
  else if (nb == 3)
    _network->setPort(_network->getPort() + 2);
}

void		gameClient::loopClient()
{
  std::size_t           received;
  sf::IPAddress         sender;
  unsigned short        port;
  char			buffer[NBOCTETS];
  int			flag = 0;
  int			temp;
  int			nb;

  this->_network = new udpNetwork();
  this->fillnetwork(_network);

  while(1)
    {
      if (!(temp = _mainWindow.MainMenuLoop()))
	{
	  _mainWindow.Close();
	  exit(0);
	}
      choosePort(temp);
      if (!(_network->getSocket().Bind(_network->getPort())))
	{
	  std::cout << "Error: Socket Listen! You must change the port." << std::endl;
	  exit(0);
	}
      this->requestConnect(temp);
      this->_network->getSocket().SetBlocking(false);
      nb = 0;
      std::cout << "Awaiting connection to the server..." <<std::endl;
      while(flag == 0 && nb <= WAITINGTIME)
	{
	  if(this->_network->getSocket().Receive(buffer, NBOCTETS,
						received, sender, port) == sf::Socket::Done)
	    {
	      if (buffer[3] == 0 && buffer[1] == 0)
		{
		  if (!(flag = replyConnect(buffer)))
		    {
		      std::cout << "Error: Server full" << std::endl;
		      break;
		    }
		}
	    }
	  nb++;
	}
      if (flag != 0)
	break;
    }
  _mainWindow.Close();
  mainClient();
}

int		gameClient::keyEvent()
{
  int		nb;

  nb = 0;
  while (_window.IsAnEvent())
    {
      if (_window.IsKeyUp())
	nb +=1;
      if (_window.IsKeyDown())
	nb +=4;
      if (_window.IsKeyLeft())
	nb +=8;
      if (_window.IsKeyRight())
	nb +=2;
      if (nb != 0)
	{
	  _mutex.Lock();
	  requestMove(nb);
	  _mutex.Unlock();
	}
      if (_window.IsShooting() && _weapondispo == 1)
	{
	  _weapondispo = 0;
	  _mutex.Lock();
	  requestShoot();
	  _mutex.Unlock();
	}
      if (_window.Quit())
	{
	  requestDisconnect();
	  return 0;
	}
    }
  return (1);
}

void		socketLoop(void * UserData)
{
  std::size_t           received;
  sf::IPAddress         sender;
  unsigned short        port;
  char			buffer[NBOCTETS];
  int			i;
  gameClient* Object = static_cast<gameClient*>(UserData);
  
  while(true)
    {
      for (i = 0; i != NBOCTETS; i++)
	buffer[i] = 0;
      if (Object->_network->getSocket().Receive(buffer, NBOCTETS, received,
						sender, port) == sf::Socket::Done)
	{
	  Object->_mutex.Lock();
	  if (received == NBOCTETS && buffer[0] == Object->getGame())
	    Object->findCommand(buffer);
	  Object->_mutex.Unlock();
	}
    }
}

int		gameClient::mainClient()
{
  sf::Thread		Thread(&socketLoop, this);
  int			loop = 0;

  _score = 0;
  _weapondispo = 0;
  _weaponloop = 0;
  _arme = 1;
  _life = 3;
  _exit = 0;
  setLevel(1);
  _music.LoadMusic();
  Thread.Launch();
  _window.setPlayer(getSprite(), getId());
  while (_window.IsLaunch())
    {
      if (loop >= 10000)
	{
	  cleanListe();
	  loop = 0;
	}
      if (_weaponloop >= 10)
	{
	  _weapondispo = 1;
	  _weaponloop = 0;
	  cleanexplosion();
	}
      findLevel(_score);
      if (!(keyEvent()))
	break;
      _music.PlayMusic();
      _window.Clear();
      _window.MoveBackground();
      _window.SetText(_score, getLife(), getId(), getLevel());
      _mutex.Lock();
      _window.Draw(_object, _exit);
      _mutex.Unlock();
      _window.Display();
      _weaponloop++;
      loop++;
    }
  Thread.Terminate();
  return 0;
}
