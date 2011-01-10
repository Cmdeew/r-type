#ifndef _MONSTERNINE_H_
# define _MONSTERNINE_H_
#include "Object.h"

class	MonsterNine : public Object
{
 private:
  char    m_id;
  char    m_x;
  char    m_y;
  char    m_type;
 public:
  MonsterNine(char id, char x, char y, char type = 19);
  void	move();
  ~MonsterNine();
};

#endif // _MONSTERONE_H_
