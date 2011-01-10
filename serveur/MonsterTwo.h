#ifndef _MONSTERTWO_H_
# define _MONSTERTWO_H_
#include "Object.h"

class	MonsterTwo : public Object
{
 private:
  char    m_id;
  char    m_x;
  char    m_y;
  char    m_type;
 public:
  MonsterTwo(char id, char x, char y, char type = 12);
  void	move();
  ~MonsterTwo();
};

#endif // _MONSTERTWO_H_
