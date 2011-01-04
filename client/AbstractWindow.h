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
  sf::Event		_event;
  sf::RenderWindow	_App;

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
  void	MoveBackground();
};

#endif //!ABSTRACTWINDOW_H
