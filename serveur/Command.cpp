#include "Command.h"

Command::Command()
{
  threadObjFlag = 0;
}


Command::~Command()
{

}

int	Command::sendConnect(Player *player, AbsUDPNetwork *p)
{  
  std::cout << "sendConnect OK " << std::endl;
  buffer[0] = SERVER;
  buffer[1] = 0;
  buffer[2] = SERVER_CMD_CONNECT;
  buffer[3] = player->getId();
  buffer[4] = 0;
  buffer[5] = 0;
  buffer[6] = 0;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendDisconnect(Player *player, AbsUDPNetwork *p)
{
  buffer[0] = SERVER;
  buffer[1] = player->getId();
  buffer[2] = SERVER_CMD_DISCONNECT;
  buffer[3] = 0;
  buffer[4] = 0;
  buffer[5] = 0;
  buffer[6] = 0;
  return p->Send(buffer, CMD_SIZE);
}


int	Command::sendPing(Player *player, AbsUDPNetwork *p)
{
  buffer[0] = SERVER;
  buffer[1] = player->getId();
  buffer[2] = SERVER_CMD_PING;
  buffer[3] = 0;
  buffer[4] = 0;
  buffer[5] = 0;
  buffer[6] = 0;
  std::cout << "PING for player " << (int)player->getId() << std::endl;
  return p->Send(buffer, CMD_SIZE);
}


int	Command::sendMove(Player *player, AbsUDPNetwork *p)
{
  buffer[0] = SERVER;
  buffer[1] = 5;
  buffer[2] = SERVER_CMD_MOVE;
  buffer[3] = player->getPosx();
  buffer[4] = player->getPosy();
  buffer[5] = player->getId();
  buffer[6] = player->getId();
  std::cout << "Send move player " << (int)player->getId() << " to all client" << std::endl;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendLife(Player *player, AbsUDPNetwork *p)
{
  buffer[0] = SERVER;
  buffer[1] = player->getId();
  buffer[2] = SERVER_CMD_LIFE;
  buffer[3] = player->getLife();
  buffer[4] = 0;
  buffer[5] = 0;
  buffer[6] = 0;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendScore(Player *player, AbsUDPNetwork *p)
{
  buffer[0] = SERVER;
  buffer[1] = 5;
  buffer[2] = SERVER_CMD_SCORE;
  buffer[3] = 0; // TODO
  buffer[4] = 0;
  buffer[5] = 0;
  buffer[6] = 0;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::sendNoSession(AbsUDPNetwork *p)
{
  buffer[0] = SERVER;
  buffer[1] = 0;
  buffer[2] = SERVER_CMD_CONNECT;
  buffer[3] = 0;
  buffer[4] = 0;
  buffer[5] = 0;
  buffer[6] = 0;
  return p->Send(buffer, CMD_SIZE);
}


int	Command::sendObjMove(Object *o, AbsUDPNetwork *p)
{
  buffer[0] = SERVER;
  buffer[1] = 5;
  buffer[2] = SERVER_CMD_MOVE;
  buffer[3] = o->getX();
  buffer[4] = o->getY();
  buffer[5] = o->getId();
  buffer[6] = o->getType();
  std::cout << "Send move ennemy " << (int)o->getId() << " type(" << (int)o->getType() << ") to all client" << std::endl;
  return p->Send(buffer, CMD_SIZE);
}

int	Command::receiveFromClient(Session *session, AbsUDPNetwork *p)
{
  int	cc;
  unsigned char playerId;
  int i;

  for (i = 0; i < CMD_SIZE; i++)
    buffer[i] = 0;
  cc = p->Receive(buffer);
  //  std::cout << "size cc:" << cc << std::endl;
  //  std::cout << "buffer[0]:" << (int)buffer[0] << std::endl;
  if (cc == CMD_SIZE && buffer[0] == CLIENT)
    {
      playerId = buffer[1];
      if (playerId == 0 && buffer[2] == CLIENT_CMD_CONNECT && buffer[3] == 0 && buffer[4] == 0 && buffer[5] == 0 && buffer[6] == 0)
	receiveConnect(session);
      else if (playerId > 0 && playerId < 5 && buffer[2] == CLIENT_CMD_DISCONNECT && buffer[3] == 0 && buffer[4] == 0 && buffer[5] == 0 && buffer[6] == 0)
	receiveDisconnect(session, playerId);
      else if (playerId > 0 && playerId < 5 && buffer[2] == CLIENT_CMD_PING && buffer[3] == 0 && buffer[4] == 0 && buffer[5] == 0 && buffer[6] == 0)
	receivePing(session, playerId);
      else if (playerId > 0 && playerId < 5 && buffer[2] == CLIENT_CMD_MOVE)
		{
		  /*
			m->DisplayCase(buffer[3], buffer[4]);
			m->UpdateMap(session->_tabPlayer[playerId - 1]->getPosx(),
						session->_tabPlayer[playerId - 1]->getPosy(),
						buffer[3], buffer[4], playerId);
		  */
			receiveMove(session, playerId, buffer[3], buffer[4]);
		}
      /*else if (playerId > 0 && playerId < 5 && buffer[2] == CLIENT_CMD_SHOOT)
	{
	  //TODO
	}
      */
      else
	std::cout << "Bad command..." << std::endl;
    }
  /*else 
    {
      std::cout << "Bad command (size)..." << std::endl;
    }*/
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
    std::cout << "No session available..." << std::endl;
  return (0);
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
  /*
  if (posy > 0)
    posy = 0;
  if (posy > 150)
    posy = 150;
  */
  session->_tabPlayer[playerId - 1]->setPosx(posx);
  session->_tabPlayer[playerId - 1]->setPosy(posy);
  std::cout << "receiveMove for player " << (int)playerId << ". New position is " << (int)posx << " "<< (int)posy  << std::endl;
  return (0);
}
