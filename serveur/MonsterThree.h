#ifndef _MONSTERTHREE_H_
# define _MONSTERTHREE_H_

#include "Object.h"

class	MonsterThree : public Object
{
 public:
  MonsterThree(char id, char x, char y);
  ~MonsterThree();
   void	move();
};

#endif // _MONSTERTHREE_H_
