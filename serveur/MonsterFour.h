#ifndef _MONSTERFOUR_H_
# define _MONSTERFOUR_H_

#include "Object.h"

class	MonsterFour : public Object
{
 public:
  MonsterFour(char id, char x, char y);
  void	move();
  ~MonsterFour();
};

#endif // _MONSTERFOUR_H_
