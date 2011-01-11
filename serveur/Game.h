#ifndef GAMERTYPE_H_
# define GAMERTYPE_H_

#include "Session.h"
#include "Factory.h"
#include "AbsThread.h"

class	Game
{
 private:
  int		id;
 public:
  Factory	*f;
  AbsThread	*th;
  AbsMutex	*mt;
  AbsUDPNetwork *p;
  Session	**s;
  hand		handles[4];
  thread	threads[4];
  Game(Factory *_f, char **argv);
  ~Game();
  static void		*startMultiGame(Game *g);
  void			startGame(int id);
  void			setId(int _id);
};

#endif // GAMERTYPE_H_
