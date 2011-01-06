#ifndef __SESSION_H_
#define __SESSION_H_

#include <iostream>
#include <vector>
#include <list>
#include "AbsUDPNetwork.h"
#include "AbsThread.h"
#include "Player.h"
#include "Object.h"

#define MAX_PING_TIME 30000
#define MID_PING_TIME 20000
#define WARN_PING_TIME 10000

class	Session
{
 private:
 public:
  AbsUDPNetwork		*_p;
  AbsThread			*_th;
  thread			threads[4];
  hand				handles[4];
  std::vector<Player *>	_tabPlayer;
  //  Command		_cmd;
  int				_pingTime[4];
  int				_session_n;
  std::list<Object *>	_listObj;
  int				_game_n;

  Session(AbsUDPNetwork *, AbsThread *);
  ~Session();
  void sessionthread();
  static void    *sessionthreadInit(Session *sess);

  void sessionthreadElems();
  static void    *sessionthreadElemsInit(Session *sess);
};

#include "Command.h"

#endif
