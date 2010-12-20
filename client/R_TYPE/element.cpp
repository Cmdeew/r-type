#include <iostream>
#include "element.h"

Element::Element()
{
  _posX = 0;
  _posY = 0;
  _life = 1;
  _ID = 0;
  _type = 0;
}

Element::Element(unsigned char x, unsigned char y, unsigned char life,
		 unsigned char id, unsigned char type)
{
  _posX = x;
  _posY = y;
  _life = life;
  _ID = id;
  _type = type;
}

Element::~Element()
{
  ;
}

void		Element::setPosX(unsigned char x)
{
  _posX = x;
}

void		Element::setPosY(unsigned char y)
{
  _posY = y;
}

void		Element::setLife(unsigned char life)
{
  _life = life;
}

void		Element::setID(unsigned char id)
{
  _ID = id;
}

void		Element::setType(unsigned char type)
{
  _type = type;
}

unsigned char		&Element::getPosX()
{
  return (_posX);
}

unsigned char		&Element::getPosY()
{
  return (_posY);
}

unsigned char	&Element::getLife()
{
  return (_life);
}

unsigned char	&Element::getID()
{
  return (_ID);
}

unsigned char	&Element::getType()
{
  return (_type);
}
