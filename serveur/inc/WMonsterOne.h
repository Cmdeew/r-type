#ifndef MONSTERONE_H
# define MONSTERONE_H

#include "Object.h"

class	MonsterOne : public Object
{
 private:
  char    m_id;
  char    m_x;
  char    m_y;
  char    m_type;
 public:
  MonsterOne(char id, char x, char y, char type = 11);
  void	move();
  ~MonsterOne();
};

typedef MonsterOne *(*maker_monster)(char id, char x, char y);

# endif // MONSTERONE_H
