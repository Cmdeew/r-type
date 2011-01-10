#ifndef _MONSTERSIX_H_
# define _MONSTERSIX_H_

#include "Object.h"

class	MonsterSix : public Object
{
 public:
  MonsterSix(char id, char x, char y);
  void	move();
  ~MonsterSix();
};

#endif // _MONSTERSIX_H_
