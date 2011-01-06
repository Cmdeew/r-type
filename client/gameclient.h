#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#define FILESERVER "fileserver.txt"
#include "udpnetwork.h"
#include "Element.h"
#include "AbstractWindow.h"
#include "AbstractMusic.h"
#include "ElementFactory.h"
#include "MainWindow.h"
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <list>

#define MINX 0
#define MAXX 48
#define MINY 0
#define MAXY 36

class gameClient
{
 private:
  int			_idPlayer;
  unsigned char	        _game;
  int			_score;
  AbstractWindow	_window;
  AbstractMusic		_music;
  ElementFactory	_factory;
  MainWindow		_mainWindow;
  int			_weapondispo;
  int			_weaponloop;
 protected:
  udpNetwork	*_network;
 public:
  std::list<Element*>	_object;
  gameClient();
  ~gameClient();
  void		cleanexplosion();
  void		readServer(void *userData);
  void		loopClient();
  int		mainClient();
  int		keyEvent();
  void		fillnetwork(udpNetwork*);
  void		requestConnect(unsigned char nb);
  void		requestPing();
  void		requestDisconnect();
  void		requestMove(int nb);
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
