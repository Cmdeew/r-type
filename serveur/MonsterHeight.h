#ifndef _MONSTERHEIGHT_H_
# define _MONSTERHEIGHT_H_

#include "Object.h"

class	MonsterHeight : public Object
{
 public:
  MonsterHeight(char id, char x, char y);
  void	move();
  ~MonsterHeight();
};

#endif // _MONSTERHEIGHT_H_
