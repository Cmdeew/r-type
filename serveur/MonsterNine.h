#ifndef _MONSTERNINE_H_
# define _MONSTERNINE_H_

#include "Object.h"

class	MonsterNine : public Object
{
 public:
  MonsterNine(char id, char x, char y);
  void	move();
  ~MonsterNine();
};

#endif // _MONSTERSEVEN_H_
