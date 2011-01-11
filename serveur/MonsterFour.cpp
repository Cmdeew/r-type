#include <stdlib.h>
#include <iostream>
#include "Object.h"
#include "./inc/UMonsterFour.h"

MonsterFour::MonsterFour(char id, char x, char y, char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = 14;
  m_lim = 0;
}

MonsterFour::~MonsterFour()
{

}

extern "C"
{
  Object *Create(char id, char x, char y)
  {
    Object *save;

    save = new MonsterFour(id, x, y, 11);
    return (save);
  }
}
