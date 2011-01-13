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
  b2x = 0;
  b2y = 0;
  b3x = 0;
  b3y = 0;
}

Elem::~Elem()
{

}

void Elem::move()
{
  if (m_type == 5)
    m_x++;
  else if (m_type == 7)
    {
      m_x--;
      if (rand()%4 == 0)
	m_y++;
      else
	m_y--;
    }
  else if (m_type == 6 || m_type == 9)
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
  else if (m_type == 22) //Boss 2
    {
      if (m_x > 40)
	b2x = 0;
      if (m_x <= 25)
	b2x = 1;

      if (b2x == 0)
	m_x--;
      if (b2x == 1)
	m_x++;

      if (b2y == 0)
	m_y += 2;
      else if (b2y == 1)
	m_y -= 2;

      if (m_y <= 3)
	b2y = 0;
     if (m_y >= 28)
	b2y = 1;
    }
  else if (m_type == 24) //Boss 3
    {
      if (m_x > 40)
	b3x = 0;
      if (m_x <= 25)
	b3x = 1;

      if (b3x == 0)
	m_x--;
      if (b3x == 1)
	m_x++;

      if (b3y == 0)
	m_y += 2;
      else if (b3y == 1)
	m_y -= 2;

      if (m_y <= 3)
	b3y = 0;
     if (m_y >= 28)
	b3y = 1;
    }
}
