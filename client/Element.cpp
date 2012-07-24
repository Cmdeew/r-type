#include <iostream>
#include "Element.h"

Element::Element()
{
  _posX = 0;
  _posY = 0;
  _life = 1;
  _ID = 0;
  _type = 0;
}

Element::Element(unsigned char x, unsigned char y, unsigned char life, unsigned char id, unsigned char type)
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

void		Element::setSprite(const std::list<sf::Texture> &list)
{
  sf::Sprite	sprite;
  std::list<sf::Texture>::const_iterator	it;

  it = list.begin();
  while (it != list.end())
    {
      sprite.setTexture(*it);
      _lSprite.push_back(sprite);
      it++;
    }
}

void			Element::setPosSprite(sf::Sprite &sprite)
{
  sprite.setPosition((int)_posX * 16, (int)_posY * 16);
}	

std::list<sf::Sprite>	&Element::getSprite()
{
  return _lSprite;
}
