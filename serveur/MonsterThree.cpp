#include <stdlib.h>
#include <iostream>
#include "Object.h"
#include "./inc/UMonsterThree.h"

MonsterThree::MonsterThree(char id, char x, char y, char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = 13;
  m_lim = 0;
}

MonsterThree::~MonsterThree()
{

}

void MonsterThree::move()
{
  m_x--;
  m_y++;
}

extern "C"
{
  Object *Create(char id, char x, char y)
  {
    Object *save;

    save = new MonsterThree(id, x, y, 11);
    return (save);
  }
}
