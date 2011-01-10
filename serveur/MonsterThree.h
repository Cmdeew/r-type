#ifndef _MONSTERTHREE_H_
# define _MONSTERTHREE_H_
#include "Object.h"

class	MonsterThree : public Object
{
 private:
  char    m_id;
  char    m_x;
  char    m_y;
  char    m_type;
 public:
  MonsterThree(char id, char x, char y, char type = 13);
  void	move();
  ~MonsterThree();
};

#endif // _MONSTERTHREE_H_
