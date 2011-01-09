#ifndef ABSTRACTWINDOW_H
#define ABSTRACTWINDOW_H

#include <iostream>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Element.h"

class	AbstractWindow
{
 private:
  sf::Image		_backgroundImg;
  sf::Sprite		_background;
  sf::Image		_interfaceImg;
  sf::Sprite		_interface;
  sf::Image		_lifeImg;
  sf::Sprite		_lifeSprite;
  sf::Event		_event;
  sf::RenderWindow	_App;
  sf::Font		_font;
  sf::String		_score;
  sf::String		_life;
  sf::String		_id;
  sf::Sprite		_player;

 public:

  AbstractWindow();
  void	Clear();
  void	Draw(const std::list<Element *> &list);
  void	Display();
  bool	Quit();
  bool	IsAnEvent();
  bool	IsLaunch();
  bool	IsKeyUp();
  bool	IsKeyDown();
  bool	IsKeyLeft();
  bool	IsKeyRight();
  bool	IsShooting();
  void	MoveBackground();
  void	SetText(int score, int life, int id);
  void	setPlayer(sf::Sprite sprite);
};

#endif //!ABSTRACTWINDOW_H
