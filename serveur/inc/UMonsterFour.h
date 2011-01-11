#ifndef _MONSTERFOUR_H_
# define _MONSTERFOUR_H_

#include "../Session.h"

class	MonsterFour : public Object
{
 public:
  MonsterFour(char id, char x, char y, char type = 11);
  void	move(Session *s);
  ~MonsterFour();
  char getType();
};

typedef MonsterFour *(*maker_monster)(char id, char x, char y);

#endif // _MONSTERONE_H_
