#ifndef _MONSTERFOUR_H_
# define _MONSTERFOUR_H_
#include "Object.h"

class	MonsterFour : public Object
{
 private:
  char    m_id;
  char    m_x;
  char    m_y;
  char    m_type;
 public:
  MonsterFour(char id, char x, char y, char type = 14);
  void	move();
  ~MonsterFour();
};

#endif // _MONSTERFOUR_H_
