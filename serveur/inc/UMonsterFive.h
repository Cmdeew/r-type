#ifndef _MONSTERFIVE_H_
# define _MONSTERFIVE_H_

#include "../Object.h"

class	MonsterFive : public Object
{
 public:
  MonsterFive(char id, char x, char y, char type = 11);
  void	move();
  ~MonsterFive();
};

typedef MonsterFive *(*maker_monster)(char id, char x, char y);

#endif // _MONSTERFIVE_H_
