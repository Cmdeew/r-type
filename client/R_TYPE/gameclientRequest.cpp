#include <iostream>
#include <fstream>
#include "SFML/include/Network.hpp"
#include "SFML/include/System.hpp"
#include "gameclient.h"


void                    gameClient::findCommand(char buffer[NBOCTETS])
{
  switch(buffer[1])
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
      std::cout << "Error: Commande introuvable ou pas a traiter" << std::endl;
    }
}

void			gameClient::requestPing()
{
  char			buffer[NBOCTETS];

  buffer[0] = _idPlayer;
  buffer[1] = 2;
  for(int i=2;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void                    gameClient::requestConnect()
{
  char                  buffer[NBOCTETS];

  for(int i=0;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void			gameClient::requestDisconnect()
{
  char                  buffer[NBOCTETS];

  buffer[0] = _idPlayer;
  buffer[1] = 1;
  for(int i=2;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void			gameClient::requestMove()
{
  char                  buffer[NBOCTETS];
  Element		*temp;
  std::list<Element *>::iterator lit;

  buffer[0] = _idPlayer;
  buffer[1] = 3;
  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == _idPlayer)
	{
	  buffer[2] = temp->getPosX();
	  buffer[3] = temp->getPosY();
	  break;
	}
    }
  //on modifie celon la direction du deplacement
  /*
    if(haut)
    buffer[3] += 1;
    else if(bas)
    buffer[3] -= 1;
    else if(gauche)
    buffer[2]-=1;
    else if(droite)
    buffer[2] += 1;
   */
  for(int i=4;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

void			gameClient::requestShoot()
{
  char                  buffer[NBOCTETS];
  Element		*temp;
  std::list<Element *>::iterator lit;

  buffer[0] = _idPlayer;
  buffer[1] = 4;
  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == _idPlayer)
	{
	  buffer[2] = temp->getPosX();
	  buffer[3] = temp->getPosY();
	  break;
	}
    }
  for(int i=4;i<NBOCTETS;i++)
    buffer[i] = 0;
  this->_network->sendMessage(buffer);
}

bool                    gameClient::replyConnect(char buffer[NBOCTETS])
{
  if(buffer[1] != 0)
    return(false);
  if(buffer[2] != 1 && buffer[2] != 2 && buffer[2] != 3 && buffer[2] != 4)
    return(false);
  if(buffer[2] == 1)
    _idPlayer = 1;
  else if (buffer[2] == 2)
    _idPlayer = 2;
  else if (buffer[2] == 3)
    _idPlayer = 3;
  else if (buffer[2] == 4)
    _idPlayer = 4;
  /*recuperer les valeur x et y en envoyer a la factory*/
  return(true);
}

void			gameClient::replyDisconnect(char buffer[NBOCTETS])
{
  if(buffer[0] == _idPlayer)
    {
      std::cout << "On va exit le game" <<std::endl;
      exit(0);
    }
}

void			gameClient::replyPing(char buffer[NBOCTETS])
{
  if(buffer[0] == _idPlayer)
      requestPing();
}

void			gameClient::replyMove(char buffer[NBOCTETS])
{
  Element		*temp;
  std::list<Element *>::iterator lit;
  int			flag = 0;

  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == buffer[4])
	{
	  temp->setPosX(buffer[2]);
	  temp->setPosY(buffer[3]);
	  flag = 1;
	}
    }
  if (flag == 0)
    {
      //on ajoute lelement dans la liste en appelant la factory
      //_object.push_back(factory);
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
      if(temp->getID() == buffer[0])
	temp->setLife(buffer[2]);
    }
}

void			gameClient::replyScore(char buffer[NBOCTETS])
{
  char			score[3];

  score[0] = buffer[2];
  score[1] = buffer[3];
  score[2] = '\0';
  _score = atoi(score);
}

void			gameClient::replyDestroy(char buffer[NBOCTETS])
{
  Element		*temp;
  std::list<Element *>::iterator lit;
  unsigned char			posx;
  unsigned char			posy;

  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == buffer[2])
	{
	  posx = temp->getPosX();
	  posy = temp->getPosY();
	  _object.erase(lit);
	  break;
	}
    }
  lit = _object.begin();
  for(;lit!=_object.end();++lit)
    {
      temp = *lit;
      if(temp->getID() == buffer[3])
	{
	  _object.erase(lit);
	  break;
	}
    }
  //_object.push_back(factory;)
  //on ajoute un objet a la liste
}
