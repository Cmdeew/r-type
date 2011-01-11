#ifndef ABSTRACTWINDOW_H
#define ABSTRACTWINDOW_H

#include <iostream>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Element.h"

class	AbstractWindow
{
 private:
  sf::Image		_portraitImg;
  sf::Sprite		_portrait;
  sf::Image		_backgroundImg;
  sf::Sprite		_background;
  sf::Image		_background2Img;
  sf::Sprite		_background2;
  sf::Image		_background3Img;
  sf::Sprite		_background3;
  sf::Image		_background4Img;
  sf::Sprite		_background4;
  sf::Image		_interfaceImg;
  sf::Sprite		_interface;
  sf::Image		_lifeImg;
  sf::Sprite		_lifeSprite;
  sf::Event		_event;
  sf::RenderWindow	_App;
  sf::Font		_font;
  sf::String		_level;
  sf::String		_score;
  sf::String		_life;
  sf::String		_id;
  sf::Sprite		_player;
  sf::Image		_gameOverImg;
  sf::Sprite		_gameOver;

 public:

  AbstractWindow();
  void	Clear();
  void	Draw(const std::list<Element *> &list, int mode, int level);
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
  void	SetText(int score, int life, int id, int level);
  void	setPlayer(sf::Sprite sprite, int id);
  void	Close();
};

#endif //!ABSTRACTWINDOW_H
