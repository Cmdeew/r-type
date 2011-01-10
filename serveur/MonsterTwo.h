#ifndef _MONSTERTWO_H_
# define _MONSTERTWO_H_

#include "Object.h"

class	MonsterTwo : public Object
{
 public:
  MonsterTwo(char id, char x, char y);
  void	move();
  ~MonsterTwo();
};

#endif // _MONSTERTWO_H_
