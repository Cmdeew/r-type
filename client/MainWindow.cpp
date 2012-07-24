#include "MainWindow.h"

MainWindow::MainWindow()
{
  _mainWindow.create(sf::VideoMode(800, 600, 32), "Best R-Type ever!!");
  _mainWindow.setFramerateLimit(60);
}

MainWindow::~MainWindow()
{
}

void	MainWindow::InitMenu()
{
  if (!_Ibackground.loadFromFile("./img/background_menu.jpg"))
    {
      std::cerr << "Error: LoadFromFile img/background_menu.jpg failed!" 
		<< std::endl;
    }
  _background.setTexture(_Ibackground);
  _background.setPosition(0, 0);
  //_background.scale(800, 600);

  if (!_menuFont.loadFromFile("font/menuFont.ttf"))
    {
      std::cerr << "Error: LoadFromFile font/menuFont.ttf failed!" 
		<< std::endl;
    }
  else
    {
      /*_tPlay.SetFont(_menuFont);
      _tCredits.SetFont(_menuFont);
      _tItems.SetFont(_menuFont);
      _tExit.SetFont(_menuFont);*/
    }
  _tPlay.setString("1 : Launch game!");
  _tCredits.setString("2 : Credits");
  _tItems.setString("3 : Exit!");
  _tExit.setString("");
  _tPlay.setCharacterSize(25);
  _tCredits.setCharacterSize(25);
  _tItems.setCharacterSize(25);
  _tExit.setCharacterSize(25);
  _tPlay.setColor(sf::Color(0, 0, 0));
  _tCredits.setColor(sf::Color(0, 0, 0));
  _tItems.setColor(sf::Color(0, 0, 0));
  _tExit.setColor(sf::Color(0, 0, 0));
  _tPlay.setPosition(325, 250);
  _tCredits.setPosition(275, 350);
  _tItems.setPosition(225, 450);
  _tExit.setPosition(175, 550);
}

void	MainWindow::InitGameList()
{
  if (!_Ibackground.loadFromFile("./img/background_menu.jpg"))
    {
      std::cerr << "Error: LoadFromFile img/background_menu.jpg failed!" 
		<< std::endl;
    }
  _background.setTexture(_Ibackground);
  _background.setPosition(0, 0);
  //_background.scale(800, 600);

  _tPlay.setString("1 : Join Game 1");
  _tCredits.setString("2 : Join Game 2");
  _tItems.setString("3 : Join Game 3");
  _tExit.setString("4 : Menu");
  _tPlay.setPosition(325, 250);
  _tCredits.setPosition(275, 350);
  _tItems.setPosition(225, 450);
  _tExit.setPosition(175, 550);
}

void	MainWindow::InitCredits()
{
 if (!_Ibackground.loadFromFile("./img/credits.jpg"))
    {
      std::cerr << "Error: LoadFromFile img/background_menu.jpg failed!" 
		<< std::endl;
    }
  _background.setTexture(_Ibackground);
  _background.setPosition(0, 0);
  //_background.scale(800, 600);

  _tPlay.setString("1 : Menu");
  _tCredits.setString("");
  _tItems.setString("");
  _tExit.setString("");
  _tPlay.setPosition(600, 500);
}

void	MainWindow::DrawAll()
{
  _mainWindow.draw(_background);
  _mainWindow.draw(_tPlay);
  _mainWindow.draw(_tCredits);
  _mainWindow.draw(_tItems);
  _mainWindow.draw(_tExit);
}

bool	MainWindow::IsOpened()
{
  return _mainWindow.isOpen();
}

bool	MainWindow::GetEvent()
{
  if (_mainWindow.pollEvent(_event))
    return true;
  else
    return false;
}

bool	MainWindow::CloseEvent()
{
  if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  else
    return false;
}

void	MainWindow::Close()
{
  _mainWindow.close();
}

void	MainWindow::Clear()
{
  _mainWindow.clear(sf::Color(0, 0, 0));
}

void	MainWindow::Display()
{
  _mainWindow.display();
}

unsigned char	MainWindow::MainMenuLoop()
{
  unsigned char	tmp;

  InitMenu();
  while (_mainWindow.isOpen())
    {
      while (_mainWindow.pollEvent(_event))
	{
	  if (CloseEvent() || 
	      (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)))
	    Close();
	  if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	    {
	      tmp = GameListLoop();
	      if (tmp != 0)
		return tmp;
	    }
	  if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	    CreditsLoop();
	}
      Clear();
      DrawAll();
      Display();      
    }
  return 0;
}

unsigned char  MainWindow::GameListLoop()
{
  while (_mainWindow.isOpen())
    {
      InitGameList();
      while (_mainWindow.pollEvent(_event))
	{
	  if (CloseEvent())
	    Close();
	  if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	    return 1;
	  if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	    return 2;
	  if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	    return 3;
	  if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	    return 0;
	}
      Clear();
      DrawAll();
      Display();
    }
  return 0;
}

int	MainWindow::CreditsLoop()
{
  while (_mainWindow.isOpen())
    {
      InitCredits();
      while (_mainWindow.pollEvent(_event))
	{
	  if (CloseEvent())
	    Close();
	  if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	    return 0;
	}
      Clear();
      DrawAll();
      Display();
    }
  return 0;
}
/*
int     MainWindow::gameOver()
{
  if (_gameOverImg.LoadFromFile("img/gameover1.jpg"))
      _gameOver.SetImage(_gameOverImg);
  while (_mainWindow.IsOpened())
    {
      Clear();
      _mainWindow.Draw(_gameOver);
      while (_mainWindow.GetEvent(_event))
        {
          if (CloseEvent())
            return -1;
          if (_mainWindow.GetInput().IsKeyDown(sf::Key::Return))
            return 1;
        }
      Display();
    }
  return 0;
}

*/
