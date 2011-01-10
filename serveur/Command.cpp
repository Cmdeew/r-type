#include "Command.h"

Command::Command(int _id_game)
{
  threadObjFlag = 0;
  id_game = (unsigned char)_id_game;
}


Command::~Command()
{

}

int	Command::sendConnect(Player *player, AbsUDPNetwork *p)
{  
  std::cout << "sendConnect OK " << std::endl;
  std::cout << "ID PARTY : " << (int)id_game << std::endl;
  buffer[0] = id_game;
  buffer[1] = SERVER;
  buffer[2] = 0;
  buffer[3] = SERVER_CMD_CONNECT;
  buffer[4] = player->getId();
  buffer[5] = 0;
  buffer[6] = 0;
  buffer[7] = 0;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendDisconnect(Player *player, AbsUDPNetwork *p)
{
  buffer[0] = id_game;
  buffer[1] = SERVER;
  buffer[2] = player->getId();
  buffer[3] = SERVER_CMD_DISCONNECT;
  buffer[4] = 0;
  buffer[5] = 0;
  buffer[6] = 0;
  buffer[7] = 0;
  return p->Send(buffer, CMD_SIZE);
}


int	Command::sendPing(Player *player, AbsUDPNetwork *p)
{
  buffer[0] = id_game;
  buffer[1] = SERVER;
  buffer[2] = player->getId();
  buffer[3] = SERVER_CMD_PING;
  buffer[4] = 0;
  buffer[5] = 0;
  buffer[6] = 0;
  buffer[7] = 0;
  //std::cout << "PING for player " << (int)player->getId() << std::endl;
  return p->Send(buffer, CMD_SIZE);
}


int	Command::sendMove(Player *player, AbsUDPNetwork *p)
{
  buffer[0] = id_game;

  std::cout << "ID PARTY : " << (int)id_game << std::endl;

  buffer[1] = SERVER;
  buffer[2] = 5;
  buffer[3] = SERVER_CMD_MOVE;
  buffer[4] = player->getPosx();
  buffer[5] = player->getPosy();
  buffer[6] = player->getId();
  buffer[7] = player->getId();
  std::cout << "Send move player " << (int)player->getId() << " to all client" << std::endl;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendLife(Player *player, AbsUDPNetwork *p)
{
  buffer[0] = id_game;
  buffer[1] = SERVER;
  buffer[2] = player->getId();
  buffer[3] = SERVER_CMD_LIFE;
  buffer[4] = player->getLife();
  buffer[5] = 0;
  buffer[6] = 0;
  buffer[7] = 0;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendScore(short score, AbsUDPNetwork *p)
{
  unsigned char score_part_one;
  unsigned char score_part_two;

  score_part_one = score;
  score_part_two = score >> 8;
  buffer[0] = id_game;
  buffer[1] = SERVER;
  buffer[2] = 5;
  buffer[3] = SERVER_CMD_SCORE;
  buffer[4] = score_part_one;
  buffer[5] = score_part_two;
  buffer[6] = 0;
  buffer[7] = 0;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendNoSession(AbsUDPNetwork *p)
{
  buffer[0] = id_game;
  buffer[1] = SERVER;
  buffer[2] = 0;
  buffer[3] = SERVER_CMD_CONNECT;
  buffer[4] = 0;
  buffer[5] = 0;
  buffer[6] = 0;
  buffer[7] = 0;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendDestroy(unsigned char id_one, unsigned char id_two, AbsUDPNetwork *p)
{
  buffer[0] = id_game;
  buffer[1] = SERVER;
  buffer[2] = 5;
  buffer[3] = SERVER_CMD_DESTROY;
  buffer[4] = id_one;
  buffer[5] = id_two;
  buffer[6] = 0;
  buffer[7] = 0;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendObjMove(Object *o, AbsUDPNetwork *p)
{
  buffer[0] = id_game;
  buffer[1] = SERVER;
  buffer[2] = 5;
  buffer[3] = SERVER_CMD_MOVE;
  buffer[4] = o->getX();
  buffer[5] = o->getY();
  buffer[6] = o->getId();
  buffer[7] = o->getType();


  
  //std::cout << "Send move ennemy " << (int)o->getId() << " type(" << (int)o->getType() << ") in position (" << (int)o->getX() << " " << (int)o->getY() << ") to all client" << std::endl;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::receiveFromClient(Session *session, AbsUDPNetwork *p)
{
  int	cc;
  unsigned char playerId;
  int i;
  int game;

  for (i = 0; i < CMD_SIZE; i++)
    buffer[i] = 0;
  cc = p->Receive(buffer);
  if (cc == CMD_SIZE && buffer[1] == CLIENT)
    {
      std::cout << "Entree dans la condition 1" << std::endl;
      game = buffer[0];
      playerId = buffer[2];
      std::cout << game << std::endl;
      std::cout << session->_game_n << std::endl;
      std::cout << "Entree dans la condition 2" << std::endl;
      if (playerId == 0 && buffer[3] == CLIENT_CMD_CONNECT && buffer[4] == 0 &&
	  buffer[5] == 0 && buffer[6] == 0 && buffer[7] == 0)
	receiveConnect(session);
      else if (playerId > 0 && playerId < 5 &&
	       buffer[3] == CLIENT_CMD_DISCONNECT && buffer[4] == 0 &&
	       buffer[5] == 0 &&
	       buffer[6] == 0 && buffer[7] == 0)
	receiveDisconnect(session, playerId);
      else if (playerId > 0 && playerId < 5 &&
	       buffer[3] == CLIENT_CMD_PING && buffer[4] == 0 &&
	       buffer[5] == 0 && buffer[6] == 0 && buffer[7] == 0)
	receivePing(session, playerId);
      else if (playerId > 0 && playerId < 5 &&
	       buffer[3] == CLIENT_CMD_MOVE)
	receiveMove(session, playerId, buffer[4], buffer[5]);
      else if (playerId > 0 && playerId < 5 &&
	       buffer[3] == CLIENT_CMD_SHOOT)
	receiveShoot(session, playerId);
      //else
      //std::cout << "Bad command..." << std::endl;
    }
/*else 
  {
  std::cout << "Bad command (size)..." << std::endl;
  }*/
  return (0);
}

int	Command::receiveShoot(Session *session, unsigned char playerId)
{
  Object *o;
  static int id = 51; //TO CHANGE

  if (!(session->_tabPlayer[playerId - 1]))
    return (1);

  o = new Object(id, session->_tabPlayer[playerId - 1]->getPosx() + 1, session->_tabPlayer[playerId - 1]->getPosy() + 1, 5);

  session->_listObj.push_back(o);

  if (o)
    session->_listObj.push_back(o);

  id++;
  if (id > 127)
    id = 51;
  return (0);
}

int	Command::receiveConnect(Session *session)
{
  int	i = 0;
  std::cout << "receiving connect" << std::endl;

  if (threadObjFlag == 0)
    {
      std::cout << "*** Lauching elements thread (monsters, edges, ...) ***" << std::endl;
      i = 4;
      session->_session_n = i;
      session->_th->ACreateThread(&session->threads[i], NULL, (typefunc)session->sessionthreadElemsInit, session);
      threadObjFlag = 1;
    }
  i = 0;
  while (i < 4)
    {
      if (session->_pingTime[i] == 0)
	{
	  std::cout << "Assign on " << i << "." << std::endl;
	  session->_session_n = i;
	  session->handles[i] = session->_th->ACreateThread(&session->threads[i], NULL, (typefunc)session->sessionthreadInit, session);
	  break;
	}
      i++;
    }
  if (i == 4)
    {
      std::cout << "No session available..." << std::endl;
      return (0);
    }
  return (1);
}

int	Command::receiveDisconnect(Session *session, unsigned char playerId)
{
  if (!(session->_tabPlayer[playerId - 1]))
    return (1);
  session->_pingTime[playerId - 1] = 0;
  std::cout << "Disconnecting player " << (int)playerId << std::endl;
  return (0);
}


int	Command::receivePing(Session *session, unsigned char playerId)
{
  if (!(session->_tabPlayer[playerId - 1]))
    return (1);
  session->_pingTime[playerId - 1] = MAX_PING_TIME;
  std::cout << "Fill pingTime["<<playerId - 1 << "]" << std::endl;
  std::cout << "receive ping" << std::endl;
  return (0);
}

int	Command::receiveMove(Session *session, unsigned char playerId, unsigned char posx, unsigned char posy)
{
  if (!(session->_tabPlayer[playerId - 1]))
    return (1);
 
  session->_tabPlayer[playerId - 1]->setPosx(posx);
  session->_tabPlayer[playerId - 1]->setPosy(posy);
  //std::cout << "receiveMove for player " << (int)playerId << ". New position is " << (int)posx << " "<< (int)posy  << std::endl;
  return (0);
}
