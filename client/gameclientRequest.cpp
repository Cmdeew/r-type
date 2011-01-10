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
	      buffer[6] != 4 && buffer[7] != 9)
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

void			gameClient::replyDestroy(char buffer[NBOCTETS])
{
  Element		*temp;
  std::list<Element *>::iterator lit;
  unsigned char			posx;
  unsigned char			posy;
  Element		*nElem;

  
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
	  _object.erase(lit);
	  delete temp;
	  break;
	}
    }
  if (buffer[5] != 0)
    {
      lit = _object.begin();
      for(;lit!=_object.end();++lit)
	{
	  temp = *lit;
	  if(temp->getID() == buffer[5])
	    {
	      _object.erase(lit);
	      delete temp;
	      break;
	    }
	}
      if (posx != 0 && posy != 0)
	{
	  nElem = _factory.FactoryMethod(27, 0, posx, posy);
	  if (nElem != NULL)
	    _object.push_back(nElem);
	  _score += 10;
	}
    }
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
	      _object.erase(lit);
	      flag = 1;
	      delete temp;
	    }
	}
    }
}
