#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class	MainWindow
{
 private:
  sf::RenderWindow	_mainWindow;
  sf::Font	_menuFont;
  sf::Event	_event;
  sf::Texture	_Ibackground;
  sf::Texture	_Icredits;
  sf::Sprite	_background;
  sf::Sprite	_credit;
  sf::Text	_tPlay;
  sf::Text	_tCredits;
  sf::Text	_tExit;
  sf::Text	_tItems;
 public:
  MainWindow();
  ~MainWindow();
  void	InitMenu();
  void	InitCredits();
  void	InitGameList();

  unsigned char	MainMenuLoop();
  unsigned char	GameListLoop();
  int	CreditsLoop();

  void	DrawAll();
  bool	IsOpened();
  bool	GetEvent();
  bool	CloseEvent();
  void	Clear();
  void	Close();
  void	Display();
};

#endif //!MAINWINDOW_H
