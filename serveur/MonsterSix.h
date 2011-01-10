#ifndef _MONSTERSIX_H_
# define _MONSTERSIX_H_
#include "Object.h"

class	MonsterSix : public Object
{
 private:
  char    m_id;
  char    m_x;
  char    m_y;
  char    m_type;
 public:
  MonsterSix(char id, char x, char y, char type = 16);
  void	move();
  ~MonsterSix();
};

#endif // _MONSTERSIX_H_
