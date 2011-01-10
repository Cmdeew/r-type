#ifndef _MONSTERHEIGHT_H_
# define _MONSTERHEIGHT_H_
#include "Object.h"

class	MonsterHeight : public Object
{
 private:
  char    m_id;
  char    m_x;
  char    m_y;
  char    m_type;
 public:
  MonsterHeight(char id, char x, char y, char type = 18);
  void	move();
  ~MonsterHeight();
};

#endif // _MONSTERHEIGHT_H_
