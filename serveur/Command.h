#ifndef COMMANDRTYPE_H_
#define COMMANDRTYPE_H_

#define CMD_SIZE 7
#define SERVER_CMD_CONNECT 0
#define SERVER_CMD_DISCONNECT 1
#define SERVER_CMD_PING 2
#define SERVER_CMD_MOVE 3
#define SERVER_CMD_LIFE 4
#define SERVER_CMD_SCORE 5
#define SERVER_CMD_DESTROY 6

#define CLIENT_CMD_CONNECT 0
#define CLIENT_CMD_DISCONNECT 1
#define CLIENT_CMD_PING 2
#define CLIENT_CMD_MOVE 3
#define CLIENT_CMD_SHOOT 4

#define	SERVER 0
#define	CLIENT 1

#include "AbsUDPNetwork.h"
#include "Player.h"
#include "Session.h"

class	Command
{
 private:
  char			buffer[CMD_SIZE];
  int			threadObjFlag;
  unsigned char		id_game;
 public:
  Command(int _id_game);
  ~Command();
  int	sendConnect(Player *, AbsUDPNetwork *);
  int	sendDisconnect(Player *, AbsUDPNetwork *);
  int	sendPing(Player *, AbsUDPNetwork *);
  int	sendMove(Player *, AbsUDPNetwork *);
  int	sendLife(Player *, AbsUDPNetwork *);
  int	sendScore(Player *, AbsUDPNetwork *);
  int	sendNoSession(AbsUDPNetwork *);
  int	sendDestroy(unsigned char id_one, unsigned char id_two, AbsUDPNetwork *p);
  int	sendObjMove(Object *o, AbsUDPNetwork *p);


  int	receiveFromClient(Session *session, AbsUDPNetwork *);
  int	receiveConnect(Session *session);
  int	receiveDisconnect(Session *session, unsigned char playerId);
  int	receivePing(Session *session, unsigned char playerId);
  int	receiveMove(Session *session, unsigned char playerId,unsigned char posx
, unsigned char posy);
  int	receiveShoot(Session *session, unsigned char PlayerId);
};

#endif
