#include <stdlib.h>
#include <iostream>
#include "Object.h"
#include "Session.h"

Object::Object()
{

}

Object::Object(const char id, const char x, const char y, const char type)
{
	m_id = id;
	m_x = x;
	m_y = y;
	m_type = type;
	m_lim = 0;
}

Object::~Object()
{

}

void Object::move()
{
  Object *obj;

  if (m_type == 12)
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
  else if (m_type == 11)
    m_x--;
  else if (m_type == 13)
    {
      m_x--;
      m_y++;
    }
  else if (m_type == 15)
    {
      m_x++;
      m_y--;
    }
  else if (m_type == 5)
    m_x++;
  else if (m_type == 6 || m_type == 14 || m_type == 7 || m_type == 9)
    m_x--;
  else if (m_type == 8)
    {
      m_x--;
      m_y--;
    }
  else if (m_type == 21) //Boss 1
    {
      if (m_x > 40)
	m_x--;
      if (m_y >=0 && m_y <= 3)
	m_y++;
      else if (m_y <= 6)
	m_y--;
    }
}

char Object::getId()
{
  return (m_id);
}

char Object::getX()
{
  return (m_x);
}

char Object::getY()
{
  return (m_y);
}

char Object::getType()
{
  return (m_type);
}
