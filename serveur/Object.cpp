#include <stdlib.h>
#include <iostream>
#include "Object.h"

Object::Object(const char id, const char x, const char y, const char type)
{
	m_id = id;
	m_x = x;
	m_y = y;
	m_type = type;
}

Object::~Object()
{

}

void Object::move()
{
	int	nb;

	if (m_type == 11 || m_type == 12 || m_type == 13 || m_type == 14)
	{
		nb = rand();
		if (nb % 2 == 0)
			m_y++;
		else
			m_y--;
		if (m_y > 34)
			m_y = 34;
		if (m_y <= 3)
			m_y = 3;
		m_x--;

		//Respawn de TEST
		if (m_x == 0)
		  {
		    m_x = 46;
		  }
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

