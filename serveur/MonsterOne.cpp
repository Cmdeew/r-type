#include <stdlib.h>
#include <iostream>
#include "Object.h"
#include "./inc/UMonsterOne.h"

MonsterOne::MonsterOne(char id, char x, char y, char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = 11;
  m_lim = 0;
}

MonsterOne::~MonsterOne()
{

}

void MonsterOne::move()
{
  std::cout << "Mouvement du type monstre 1" << std::endl;
  m_x--;
}

extern "C"
{
  Object *Create(char id, char x, char y)
  {
    Object *save;

    save = new MonsterOne(id, x, y, 11);
    return (save);
  }
}
