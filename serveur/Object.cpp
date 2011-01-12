#include <stdlib.h>
#include <iostream>
#include "Object.h"

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
