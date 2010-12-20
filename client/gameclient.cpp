#include <iostream>
#include <fstream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "gameclient.h"

gameClient::gameClient()
{
  ;
}

gameClient::~gameClient()
{
  ;
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

void		gameClient::loopClient()
{
  std::size_t           received;
  sf::IPAddress         sender;
  unsigned short        port;
  char			buffer[NBOCTETS];
  int			flag = 0;

  this->_network = new udpNetwork();
  this->fillnetwork(_network);
  if (!(_network->getSocket().Bind(_network->getPort())))
    {
      std::cout << "Error: Socket Listen!" << std::endl;
      exit(0);
    }
  this->requestConnect();
  while(flag == 0 &&
	this->_network->getSocket().Receive(buffer, NBOCTETS, received,
					    sender, port) == sf::Socket::Done)
    {
      std::cout << "Awaiting connection to the server..." <<std::endl;
      if (buffer[2] == 0 && buffer[0] == 0)
	{
	  if (!(flag = replyConnect(buffer)))
	    {
	      std::cout << "Error: Server full" << std::endl;
	      exit(0);
	    }
	}
    }
  this->_network->getSocket().SetBlocking(false);
  mainClient();
}

void		gameClient::mainClient()
{
  std::size_t           received;
  sf::IPAddress         sender;
  unsigned short        port;
  char			buffer[NBOCTETS];
  int			i;
  int			nb;

  std::cout << "id:" << (int)_idPlayer << std::endl;
  _score = 0;
  _music.LoadMusic();
  while (_window.IsLaunch())
    {
      _music.PlayMusic();
      for (i = 0; i != NBOCTETS; i++)
	buffer[i] = 0;
      if (this->_network->getSocket().Receive(buffer, NBOCTETS, received,
                                              sender, port) == sf::Socket::Done)
	{
	  std::cout << "Commande recu: ";
	  for (i = 0; i != NBOCTETS; i++)
	    std::cout << (int)buffer[i];
	  std::cout << std::endl;
	  findCommand(buffer);
	}
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
	    requestMove(nb);
	}
      _window.Clear();
      _window.MoveBackground();
      _window.Draw(_object);
      _window.Display();
    }
}
