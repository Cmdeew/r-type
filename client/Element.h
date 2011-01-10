#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <list>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Element
{
 private:
  unsigned char		_posX;
  unsigned char		_posY;
  unsigned char		_life;
  unsigned char		_ID;
  unsigned char		_type;
  std::list<sf::Sprite>	_lSprite;
  Element();
 public:
  std::list<sf::Sprite>::iterator _iter;
  Element(unsigned char x, unsigned char y, unsigned char life,
	  unsigned char id, unsigned char type);
  ~Element();
  void			setPosX(unsigned char);
  void			setPosY(unsigned char);
  void			setLife(unsigned char);
  void			setID(unsigned char);
  void			setType(unsigned char);
  void			setSprite(const std::list<sf::Image> &list);
  void			setPosSprite(sf::Sprite &sprite);
  unsigned char&	getPosX();
  unsigned char&	getPosY();
  unsigned char&	getLife();
  unsigned char&	getID();
  unsigned char&	getType();
  std::list<sf::Sprite>	&getSprite();
};

#endif
