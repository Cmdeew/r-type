#ifndef GAMERTYPE_H_
#define GAMERTYPE_H_

#include "Factory.h"
#include "AbsThread.h"

class	Game
{
 private:
  int		id;
 public:
  Factory	*f;
  AbsThread	*th;
  AbsUDPNetwork *p;
  hand		handles[3];
  thread	threads[3];
  Game(Factory *_f, char **argv);
  ~Game();
  static void		*startMultiGame(Game *g);
  void			startGame(int id);
  void			setId(int _id);
};

#endif // GAMERTYPE_H_
