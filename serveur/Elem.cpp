#include <stdlib.h>
#include <iostream>
#include "Elem.h"

Elem::Elem()
{

}

Elem::Elem(const char id, const char x, const char y, const char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = type;
  m_lim = 0;
}

Elem::~Elem()
{

}

void Elem::move()
{
  if (m_type == 5)
    m_x++;
  else if (m_type == 6 || m_type == 7)
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
