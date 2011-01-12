#include <stdlib.h>
#include <iostream>
#include "Object.h"
#include "./inc/UMonsterTwo.h"

MonsterTwo::MonsterTwo(char id, char x, char y, char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = 12;
  m_lim = 0;
}

MonsterTwo::~MonsterTwo()
{

}

void MonsterTwo::move()
{
  m_x--;
  if (m_lim < 5)
    m_y++;
  else
    m_y--;
  if (m_lim == 10)
    m_lim = 0;
  else
    m_lim++;
}

extern "C"
{
  Object *Create(char id, char x, char y)
  {
    Object *save;

    save = new MonsterTwo(id, x, y, 11);
    return (save);
  }
}

