#ifndef _MONSTERONE_H_
# define _MONSTERONE_H_

#include "Object.h"

class	MonsterOne : public Object
{
 public:
  MonsterOne(char id, char x, char y);
  void	move();
  ~MonsterOne();
};

#endif // _MONSTERONE_H_
