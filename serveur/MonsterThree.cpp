#include <stdlib.h>
#include <iostream>
#include "MonsterThree.h"

MonsterThree::MonsterThree(const char id, const char x, const char y, const char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = type;
}

MonsterThree::~MonsterThree()
{

}

void MonsterThree::move()
{

}
