#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#define FILESERVER "fileserver.txt"
#include "udpnetwork.h"
#include "element.h"
#include "SFML/include/System.hpp"
#include <list>

class gameClient
{
 private:
  int			_idPlayer;
  int			_score;
 protected:
  udpNetwork	*_network;
 public:
  std::list<Element*>	_object;
  gameClient();
  ~gameClient();
  void		readServer(void *userData);
  void		loopClient();
  void		mainClient();
  void		fillnetwork(udpNetwork*);
  void		requestConnect();
  void		requestPing();
  void		requestDisconnect();
  void		requestMove();
  void		requestShoot();
  void		findCommand(char buffer[NBOCTETS]);
  bool		replyConnect(char buffer[NBOCTETS]);
  void		replyDisconnect(char buffer[NBOCTETS]);
  void		replyPing(char buffer[NBOCTETS]);
  void		replyMove(char buffer[NBOCTETS]);
  void		replyLife(char buffer[NBOCTETS]);
  void		replyScore(char buffer[NBOCTETS]);
  void		replyDestroy(char buffer[NBOCTETS]);
};


#endif
