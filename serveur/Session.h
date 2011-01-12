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
#include "LoadLib.h"

#define MAX_PING_TIME 30000
#define MID_PING_TIME 20000
#define WARN_PING_TIME 10000


#define LEVEL1 2500
#define LEVEL_BOSS1 2000
#define LEVEL2 6000
#define LEVEL_BOSS2 4500
#define LEVEL3 10000
#define LEVEL_BOSS3 8500

#define MAXRAND 35

class	Session
{
 private:
 public:
  LoadLib			*lib;
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
  void		Create_Boss(int i);

  void		collision_playermissile_mob();

  unsigned char mob_id;

  void		spawnPlayer(Player *);

  void		*launchMissile(Object *obj);
};

#include "Command.h"

#endif
