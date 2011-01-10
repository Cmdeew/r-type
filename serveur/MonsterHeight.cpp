#include <stdlib.h>
#include <iostream>
#include "MonsterHeight.h"

MonsterHeight::MonsterHeight(const char id, const char x, const char y, const char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = type;
}

MonsterHeight::~MonsterHeight()
{

}

void MonsterHeight::move()
{

}
