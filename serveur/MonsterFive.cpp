#include <stdlib.h>
#include <iostream>
#include "Object.h"
#include "./inc/UMonsterFive.h"

MonsterFive::MonsterFive(char id, char x, char y, char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = 15;
  m_lim = 0;
}

MonsterFive::~MonsterFive()
{

}


void MonsterFive::move()
{
  m_x--;
  m_y--;
}

extern "C"
{
  Object *Create(char id, char x, char y)
  {
    Object *save;

    save = new MonsterFive(id, x, y, 11);
    return (save);
  }
}
