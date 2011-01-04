#include <iostream>
#include <fstream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "gameclient.h"


void                    gameClient::findCommand(char buffer[NBOCTETS])
{
  if (buffer[0] == 0)
    {      
      switch(buffer[2])
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
	    std::cout << "Error: Commande introuvable ou pas a traiter" << std::endl;
	  }
	}
    }
}

void			gameClient::requestPing()
{
  char			buffer[NBOCTETS];

  buffer[0] = 1;
  buffer[1] = _idPlayer;
  buffer[2] = 2;
  for(int i=3;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void                    gameClient::requestConnect()
{
  char                  buffer[NBOCTETS];

  buffer[0] = 1;
  for(int i=1;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void			gameClient::requestDisconnect()
{
  char                  buffer[NBOCTETS];

  buffer[0] = 1;
  buffer[1] = _idPlayer;
  buffer[2] = 1;
  for(int i=3;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void			gameClient::requestMove(int nb)
{
  char                  buffer[NBOCTETS];
  Element		*temp;
  std::list<Element *>::iterator lit;

  buffer[0] = 1;
  buffer[1] = _idPlayer;
  buffer[2] = 3;
  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == _idPlayer)
	{
	  buffer[3] = temp->getPosX();
	  buffer[4] = temp->getPosY();
	  break;
	}
    }
  if (nb == 1)
    buffer[4] -= 1;
  if (nb == 4)
    buffer[4] += 1;
  if (nb == 2)
    buffer[3] += 1;
  if (nb == 8)
    buffer[3] -= 1;
  if (nb == 3)
    {
      buffer[4] -=1;
      buffer[3] += 1;
    }
  if (nb == 9)
    {
      buffer[4] -=1;
      buffer[3] -= 1;
    }
  if (nb == 6)
    {
      buffer[4] +=1;
      buffer[3] += 1;
    }
  if (nb == 12)
    {
      buffer[4] +=1;
      buffer[3] -= 1;
    }
  temp->setPosX(buffer[3]);
  temp->setPosY(buffer[4]);
  for(int i=5;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void			gameClient::requestShoot()
{
  char                  buffer[NBOCTETS];
  Element		*temp;
  std::list<Element *>::iterator lit;

  buffer[0] = 1;
  buffer[1] = _idPlayer;
  buffer[2] = 4;
  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == _idPlayer)
	{
	  buffer[3] = temp->getPosX();
	  buffer[4] = temp->getPosY();
	  break;
	}
    }
  for(int i=5;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

bool                    gameClient::replyConnect(char buffer[NBOCTETS])
{
  Element	*nElem;

  if(buffer[2] != 0)
    return(false);
  if(buffer[3] != 1 && buffer[3] != 2 && buffer[3] != 3 && buffer[3] != 4)
    return(false);
  if(buffer[3] == 1)
    _idPlayer = 1;
  else if (buffer[3] == 2)
    _idPlayer = 2;
  else if (buffer[3] == 3)
    _idPlayer = 3;
  else if (buffer[3] == 4)
    _idPlayer = 4;
  nElem = _factory.FactoryMethod(_idPlayer, _idPlayer, buffer[4], buffer[5]);
  if (nElem != NULL)
  _object.push_back(nElem);
  return(true);
}

void			gameClient::replyDisconnect(char buffer[NBOCTETS])
{
  if(buffer[1] == _idPlayer && buffer[3] == 0 && buffer[4] == 0 && buffer[5] == 0 && buffer[6] == 0)
    {
      std::cout << "On va exit le game" <<std::endl;
      exit(0);
    }
}

void			gameClient::replyPing(char buffer[NBOCTETS])
{
  if(buffer[1] == _idPlayer)
    {
      std::cout << "ping" << std::endl;
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
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == buffer[5])
	{
	  temp->setPosX(buffer[3]);
	  temp->setPosY(buffer[4]);
	  flag = 1;
	}
    }
  if (flag == 0)
    {
      nElem = _factory.FactoryMethod(buffer[6], buffer[5], buffer[3], buffer[4]);
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
      if(temp->getID() == buffer[1])
	temp->setLife(buffer[3]);
    }
}

void			gameClient::replyScore(char buffer[NBOCTETS])
{
  char			score[3];

  score[0] = buffer[3];
  score[1] = buffer[4];
  score[2] = '\0';
  _score = atoi(score);
}

void			gameClient::replyDestroy(char buffer[NBOCTETS])
{
  Element		*temp;
  std::list<Element *>::iterator lit;
  unsigned char			posx;
  unsigned char			posy;
  Element		*nElem;

  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == buffer[3])
	{
	  posx = temp->getPosX();
	  posy = temp->getPosY();
	  _object.erase(lit);
	  delete temp;
	  break;
	}
    }
  if (buffer[4] != 0)
    {
      lit = _object.begin();
      for(;lit!=_object.end();++lit)
	{
	  temp = *lit;
	  if(temp->getID() == buffer[4])
	    {
	      _object.erase(lit);
	      delete temp;
	      break;
	    }
	}
      nElem = _factory.FactoryMethod(24, 0, posx, posy);
      if (nElem != NULL)
	_object.push_back(nElem);
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
