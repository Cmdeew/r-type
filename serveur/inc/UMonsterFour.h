#ifndef _MONSTERFOUR_H_
# define _MONSTERFOUR_H_

#include "../Object.h"

class	MonsterFour : public Object
{
 public:
  MonsterFour(char id, char x, char y, char type = 11);
  void	move();
  ~MonsterFour();
};

typedef MonsterFour *(*maker_monster)(char id, char x, char y);

#endif // _MONSTERFOUR_H_
