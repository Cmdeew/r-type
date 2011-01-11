#ifndef __SESSION_H_
#define __SESSION_H_

#include <iostream>
#include <vector>
#include <list>
#include "AbsUDPNetwork.h"
#include "AbsThread.h"
#include "AbsMutex.h"
#include "Player.h"
#include "CUAbsDynamicLib.h"
#include "Object.h"

#define MAX_PING_TIME 30000
#define MID_PING_TIME 20000
#define WARN_PING_TIME 10000

#define LEVEL1 2000

#define MAXRAND 35

class	Session
{
 private:
 public:
  AbsUDPNetwork			*_p;
  AbsThread			*_th;
  AbsMutex			*_mt;
  thread			threads[4];
  hand				handles[4];
  std::vector<Player *>	_tabPlayer;
  //  Command		_cmd;
  int				_pingTime[4];
  int				_session_n;
  std::list<Object *>	_listObj;
  int				_game_n;
  short				_score;

  Session();
  Session(AbsUDPNetwork *, AbsThread *, AbsMutex *, int);
  ~Session();
  void sessionthread();
  static void    *sessionthreadInit(Session *sess);

  void sessionthreadElems();
  static void    *sessionthreadElemsInit(Session *sess);
  void		Create_Mob(int i);

  unsigned char mob_id;

  void		spawnPlayer(Player *);

};

#include "Command.h"

#endif
