#ifndef _MONSTERFIVE_H_
# define _MONSTERFIVE_H_
#include "Object.h"

class	MonsterFive : public Object
{
 private:
  char    m_id;
  char    m_x;
  char    m_y;
  char    m_type;
 public:
  MonsterFive(char id, char x, char y, char type = 15);
  void	move();
  ~MonsterFive();
};

#endif // _MONSTERFIVE_H_
