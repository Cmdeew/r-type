#ifndef _MONSTERSEVEN_H_
# define _MONSTERSEVEN_H_
#include "Object.h"

class	MonsterSeven : public Object
{
 private:
  char    m_id;
  char    m_x;
  char    m_y;
  char    m_type;
 public:
  MonsterSeven(char id, char x, char y, char type = 17);
  void	move();
  ~MonsterSeven();
};

#endif // _MONSTERSEVEN_H_
