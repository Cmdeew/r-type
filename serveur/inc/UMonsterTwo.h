#ifndef _MONSTERTWO_H_
# define _MONSTERTWO_H_
#include "../Object.h"

class	MonsterTwo : public Object
{
 public:
  MonsterTwo(char id, char x, char y, char type = 11);
  void	move();
  ~MonsterTwo();
};

typedef MonsterTwo *(*maker_monster)(char id, char x, char y);

#endif // _MONSTERTWO_H_
