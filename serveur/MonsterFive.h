#ifndef _MONSTERFIVE_H_
# define _MONSTERFIVE_H_

#include "Object.h"

class	MonsterFive : public Object
{
 public:
  MonsterFive(char id, char x, char y);
  void	move();
  ~MonsterFive();
};

#endif // _MONSTERFIVE_H_
