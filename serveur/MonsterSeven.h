#ifndef _MONSTERSEVEN_H_
# define _MONSTERSEVEN_H_

#include "Object.h"

class	MonsterSeven : public Object
{
 public:
  MonsterSeven(char id, char x, char y);
  void	move();
  ~MonsterSeven();
};

#endif // _MONSTERSEVEN_H_
