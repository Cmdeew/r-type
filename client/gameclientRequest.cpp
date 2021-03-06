#include <iostream>
#include <fstream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "gameclient.h"


void                    gameClient::findCommand(char buffer[NBOCTETS])
{
  if (buffer[1] == 0)
    {      
      switch(buffer[3])
	{
	case 1:
	  {
	    replyDisconnect(buffer);
	    break;
	  }
	case 2:
	  {
	    replyPing(buffer);
	    break;
	  }
	case 3:
	  {
	    replyMove(buffer);
	    break;
	  }
	case 4:
	  {
	    replyLife(buffer);
	    break;
	  }
	case 5:
	  {
	    replyScore(buffer);
	    break;
	  }
	case 6:
	  {
	    replyDestroy(buffer);
	    break;
	  }
	default:
	  {
	    ;
	  }
	}
    }
}

void			gameClient::requestPing()
{
  char			buffer[NBOCTETS];

  buffer[0] = _game;
  buffer[1] = 1;
  buffer[2] = _idPlayer;
  buffer[3] = 2;
  for(int i=4;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void                    gameClient::requestConnect(unsigned char nb)
{
  char                  buffer[NBOCTETS];

  buffer[0] = nb;
  buffer[1] = 1;
  for(int i=2;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void			gameClient::requestDisconnect()
{
  char                  buffer[NBOCTETS];

  buffer[0] = _game;
  buffer[1] = 1;
  buffer[2] = _idPlayer;
  buffer[3] = 1;
  for(int i=4;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void			gameClient::requestMove(int nb)
{
  char                  buffer[NBOCTETS];
  Element		*temp;
  std::list<Element *>::iterator lit;

  buffer[0] = _game;
  buffer[1] = 1;
  buffer[2] = _idPlayer;
  buffer[3] = 3;
  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == _idPlayer)
	{
	  buffer[4] = temp->getPosX();
	  buffer[5] = temp->getPosY();
	  break;
	}
    }
  if (nb == 1)
    buffer[5] -= 1;
  if (nb == 4)
    buffer[5] += 1;
  if (nb == 2)
    buffer[4] += 1;
  if (nb == 8)
    buffer[4] -= 1;
  if (nb == 3)
    {
      buffer[5] -=1;
      buffer[4] += 1;
    }
  if (nb == 9)
    {
      buffer[5] -=1;
      buffer[4] -= 1;
    }
  if (nb == 6)
    {
      buffer[5] +=1;
      buffer[4] += 1;
    }
  if (nb == 12)
    {
      buffer[5] +=1;
      buffer[4] -= 1;
    }
  if (buffer[4] >= MINX && buffer[4] <= MAXX && buffer[5] >= MINY && buffer[5] <= MAXY)
    {
      temp->setPosX(buffer[4]);
      temp->setPosY(buffer[5]);
      for(int i=6;i<NBOCTETS;i++)
	buffer[i] = 0;
      this->_network->sendMessage(buffer);
    }
}

void			gameClient::requestShoot()
{
  char                  buffer[NBOCTETS];
  Element		*temp;
  std::list<Element *>::iterator lit;

  buffer[0] = _game;
  buffer[1] = 1;
  buffer[2] = _idPlayer;
  buffer[3] = 4;
  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == _idPlayer)
	{
	  buffer[4] = temp->getPosX();
	  buffer[5] = temp->getPosY();
	  break;
	}
    }
  for(int i=6;i<NBOCTETS;i++)
    buffer[i] = 0;
  _shoot.play();
  this->_network->sendMessage(buffer);
}

bool                    gameClient::replyConnect(char buffer[NBOCTETS])
{
  Element	*nElem;

  if(buffer[0] == 0)
    return (false);
  if(buffer[3] != 0)
    return(false);
  if(buffer[4] != 1 && buffer[4] != 2 && buffer[4] != 3 && buffer[4] != 4)
    return(false);
  if(buffer[4] == 1)
    _idPlayer = 1;
  else if (buffer[4] == 2)
    _idPlayer = 2;
  else if (buffer[4] == 3)
    _idPlayer = 3;
  else if (buffer[4] == 4)
    _idPlayer = 4;
  nElem = _factory.FactoryMethod(_idPlayer, _idPlayer, buffer[4], buffer[5]);
  if (nElem != NULL)
  _object.push_back(nElem);
  _game = buffer[0];
  return(true);
}

void			gameClient::replyDisconnect(char buffer[NBOCTETS])
{
  if(buffer[2] == _idPlayer && buffer[4] == 0 && buffer[5] == 0 && buffer[6] == 0
     && buffer[7] == 0)
    {
      _exit = 1;
    }
}

void			gameClient::replyPing(char buffer[NBOCTETS])
{
  if(buffer[2] == _idPlayer)
    {
      requestPing();
    }
}

void			gameClient::replyMove(char buffer[NBOCTETS])
{
  Element		*temp;
  Element		*nElem;
  std::list<Element *>::iterator lit;
  int			flag = 0;

  lit = _object.begin();
  for(;lit!=_object.end();lit++)
    {
      temp = *lit;
      if(temp->getID() == buffer[6])
	{
	  temp->setPosX(buffer[4]);
	  temp->setPosY(buffer[5]);
	  flag = 1;
	  if (buffer[6] != 1 && buffer[6] != 2 && buffer[6] != 3 &&
	      buffer[6] != 4)
	    {
	      if (temp->_iter == temp->getSprite().end())
	      	temp->_iter = temp->getSprite().begin();
	      else
		temp->_iter++;
    	      if (temp->_iter == temp->getSprite().end())
	      	temp->_iter = temp->getSprite().begin();
	    } 
	} 
    }
  if (flag == 0)
    {
      if (buffer[7] == 5)
	{
	  if (_arme == 1)
	    nElem = _factory.FactoryMethod(buffer[7], buffer[6], buffer[4], buffer[5]);
	  else if (_arme == 2)
	    nElem = _factory.FactoryMethod(10, buffer[6], buffer[4], buffer[5]);
	  else
	    nElem = _factory.FactoryMethod(32, buffer[6], buffer[4], buffer[5]);
	}
      else
	nElem = _factory.FactoryMethod(buffer[7], buffer[6], buffer[4], buffer[5]);
      if (nElem != NULL)      
	_object.push_back(nElem);
    }
}

void			gameClient::replyLife(char buffer[NBOCTETS])
{
  Element		*temp;
  std::list<Element *>::iterator lit;

  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == buffer[2])
	temp->setLife(buffer[4]);
    }
  if (buffer[2] == _idPlayer)
  _life = buffer[4];
}

void			gameClient::replyScore(char buffer[NBOCTETS])
{
  unsigned char temp1, temp2;
  unsigned short result;

  temp1 = buffer[5];
  temp2 = buffer[4];  
  result = (((unsigned short)temp1) <<8) | temp2;
  _score = (int)result;
}

void			gameClient::bossExplosion(unsigned char posx, unsigned char posy)
{
  unsigned char		l;
  unsigned char		c;
  Element		*nElem;

  for(l=posx-4;l<=(posx+4);l+=4)
    {
      for(c=posy-10;c<=(posy+10);c+=4)
	{
	  nElem = _factory.FactoryMethod(27, 0, l, c);
	  if (nElem != NULL)
	    _object.push_back(nElem);
	}
    }
  _dieBoss.play();
}

void			gameClient::replyDestroy(char buffer[NBOCTETS])
{
  Element		*temp;
  unsigned char		type;
  unsigned char		type2;
  std::list<Element *>::iterator lit;
  unsigned char			posx;
  unsigned char			posy;
  Element			*nElem;
  bool				boss;
  
  boss = 0;
  type = type2 = 0;
  if (buffer[4] == _idPlayer || buffer[5] == _idPlayer)
    _life -= 1;
  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == buffer[4])
	{
	  posx = temp->getPosX();
	  posy = temp->getPosY();
	  type = temp->getType();
	  if (temp->getType() == 21 || temp->getType() == 22 ||
	      temp->getType() == 23 || temp->getType() == 24)
	    boss = 1;
	  _object.erase(lit);
	  delete temp;
	  break;
	}
    }
  if (buffer[5] != 0)
    {
      lit = _object.begin();
      for (;lit!=_object.end();++lit)
	{
	  temp = *lit;
	  if (temp->getID() == buffer[5])
	    {
	      type2 = temp->getType();
	      if (boss == 0 && (temp->getType() == 21 || temp->getType() == 22 ||
				temp->getType() == 23 || temp->getType() == 24))
		boss = 1;
	      _object.erase(lit);
	      delete temp;
	      break;
	    }
	}
      _score += 10;
    }
  //    if (buffer[5] != 0 && posx != 0 && posy != 0)
  if (posx != 0 && posy != 0 && posx != 26 && posy != 26)
    {
      nElem = _factory.FactoryMethod(27, 0, posx, posy);
      if (nElem != NULL)
	_object.push_back(nElem);
    }
  if((type == 0 && type2 != 0) || (type !=0 && type2 == 0))
    {
      //nosound
    }
  else
    {
      if (type == 11 || type2 == 11)
	_die1.play();
      else if (type == 12 || type2 == 12)
	_die2.play();
      else if (type == 13 || type2 == 13)
	_die3.play();
      else if (type == 14 || type2 == 14)
	_die4.play();
    }
  if (boss == 1)
    bossExplosion(posx, posy);
}

void			gameClient::cleanexplosion()
{
int			flag;
  Element		*temp;
  std::list<Element *>::iterator lit;

  flag = 1;
  while (flag == 1)
    {
      flag = 0;
      lit = _object.begin();
      for(;lit!=_object.end() && flag != 1;++lit)
	{
	  temp = *lit;
	  if (temp->getID() == 0)
	    {
	      if (temp->_iter == temp->getSprite().end())
		{
		  _object.erase(lit);
		  flag = 1;
		  delete temp;
		}
	      else
		{
		  temp->_iter++;
		  if (temp->_iter == temp->getSprite().end())
		    {
		      _object.erase(lit);
		      flag = 1;
		      delete temp;
		    }
		}
	    }
	}
    }  
}

void		gameClient::cleanListe()
{
  int			flag;
  Element		*temp;
  std::list<Element *>::iterator lit;

  flag = 1;
  while (flag == 1)
    {
      flag = 0;
      lit = _object.begin();
      for(;lit!=_object.end() && flag != 1;++lit)
	{
	  temp = *lit;
	  if (temp->getID() != 0 && temp->getID() != 1 && temp->getID() != 2 && temp->getID() != 3 && temp->getID() != 4)
	    {
	      _object.erase(lit);
	      flag = 1;
	      delete temp;
	    }
	}
    }
}
