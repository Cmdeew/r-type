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

void MonsterOne::move(Session *s)
{
}
  /*Object *obj;

  static int k = 0;

  

  if (k % 25 == 0)
    {
      std::cout << "SHOOT" << std::endl;
      obj = new Object(s->mob_id++, m_x - 3, m_y, 6);
      s->_listObj.push_back(obj);
      if (s->mob_id > 127)
	s->mob_id = 11;
      obj = new Object(s->mob_id++, m_x - 3, m_y, 8);
      s->_listObj.push_back(obj);
    }
  if (s->mob_id > 127)
    s->mob_id = 11;
  m_x--;
  if (k == 50000)
    k = 0;
    k++;
  }/*

  char MonsterOne::getType()
{
  return (m_type);
}

char MonsterOne::getType()
{
  return (m_type);
}
  */

  
char MonsterOne::getType()
{
  return (m_type);
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
