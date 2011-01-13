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

#define MIN_MOB_ID 25

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
  int				_pingTime[4];
  int				_session_n;
  int				_game_n;
  short				_score;
  int				_flagLoad;
  int				a;
  int				b;
  int				t;
  int				e;
  int				boss1;
  int				boss2;
  int				boss3;
  int				m;
  int				b1;
  int				b2;
  int				b3;
  unsigned char			mob_id;
  std::vector<Player *>		_tabPlayer;
  std::list<Object *>		_listObj;
  //  Command		_cmd;

  Session();
  Session(AbsUDPNetwork *, AbsThread *, AbsMutex *, int);
  ~Session();
  static void	*sessionthreadElemsInit(Session *sess);
  static void	*sessionthreadInit(Session *sess);
  void		sessionthread();
  void		sessionthreadElems();
  void		Create_Mob(int i);
  void		Create_Boss(int i);
  void		collision_playermissile_mob();
  void		move_missile();
  void		collision_player_mob();
  void		spawnPlayer(Player *);
  void		*launchMissile(Object *obj);
  void		collision_playermissile_boss(unsigned char boss_type,
					     short level_boss, short level,
					     int limit_x_plus,
					     int limit_x_minus,
					     int limit_y_plus,
					     int limit_y_minus);

  
};

#include "Command.h"

#endif
