#ifndef _MONSTERONE_H_
# define _MONSTERONE_H_

#include "../Session.h"

class	MonsterThree : public Object
{
 public:
  MonsterThree(char id, char x, char y, char type = 11);
  void	move(Session *s);
  ~MonsterThree();
  char getType();
};

typedef MonsterThree *(*maker_monster)(char id, char x, char y);

#endif // _MONSTERONE_H_
