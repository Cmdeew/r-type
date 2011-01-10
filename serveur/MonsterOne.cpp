#include <stdlib.h>
#include <iostream>
#include "MonsterOne.h"

MonsterOne::MonsterOne(const char id, const char x, const char y, const char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = type;
}

MonsterOne::~MonsterOne()
{

}

void MonsterOne::move()
{

}

extern "C"
{
  MonsterOne *Create(char id, char x, char y)
  {
    return new MonsterOne(id, x, y);
  }
}
