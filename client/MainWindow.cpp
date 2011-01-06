#include "MainWindow.h"

MainWindow::MainWindow()
{
  _mainWindow.Create(sf::VideoMode(800, 600, 32), "Best R-Type ever!!");
}

MainWindow::~MainWindow()
{
}

void	MainWindow::InitMenu()
{
  if (!_Ibackground.LoadFromFile("./img/background_menu.jpg"))
    {
      std::cerr << "Error: LoadFromFile img/background_menu.jpg failed!" 
		<< std::endl;
    }
  _background.SetImage(_Ibackground);
  _background.SetPosition(0, 0);
  _background.Resize(800, 600);

  if (!_menuFont.LoadFromFile("font/menuFont.ttf"))
    {
      std::cerr << "Error: LoadFromFile font/menuFont.ttf failed!" 
		<< std::endl;
    }
  else
    {
      _tPlay.SetFont(_menuFont);
      _tCredits.SetFont(_menuFont);
      _tItems.SetFont(_menuFont);
      _tExit.SetFont(_menuFont); 
    }
  _tPlay.SetText("1 : Launch game!");
  _tCredits.SetText("2 : Credits");
  _tItems.SetText("3 : Items");
  _tExit.SetText("4 : Exit!");
  _tPlay.SetSize(25);
  _tCredits.SetSize(25);
  _tItems.SetSize(25);
  _tExit.SetSize(25);
  _tPlay.SetColor(sf::Color(0, 0, 0));
  _tCredits.SetColor(sf::Color(0, 0, 0));
  _tItems.SetColor(sf::Color(0, 0, 0));
  _tExit.SetColor(sf::Color(0, 0, 0));
  _tPlay.SetPosition(325, 250);
  _tCredits.SetPosition(275, 350);
  _tItems.SetPosition(225, 450);
  _tExit.SetPosition(175, 550);
}

void	MainWindow::InitGameList()
{
  if (!_Ibackground.LoadFromFile("./img/background_menu.jpg"))
    {
      std::cerr << "Error: LoadFromFile img/background_menu.jpg failed!" 
		<< std::endl;
    }
  _background.SetImage(_Ibackground);
  _background.SetPosition(0, 0);
  _background.Resize(800, 600);
  
  //if (!_menuFont.LoadFromFile("font/menuFont.ttf"))
  //{
  //  std::cerr << "Error: LoadFromFile font/menuFont.ttf failed!" 
  //		<< std::endl;
  //}
  //  else
  //{
  //  _tPlay.SetFont(_menuFont);
  //  _tCredits.SetFont(_menuFont);
  //  _tItems.SetFont(_menuFont);
  //  _tExit.SetFont(_menuFont); 
  //}
  _tPlay.SetText("1 : Join Game 1");
  _tCredits.SetText("2 : Join Game 2");
  _tItems.SetText("3 : Join Game 3");
  _tExit.SetText("4 : Menu");
  //  _tPlay.SetSize(25);
  //_tCredits.SetSize(25);
  //_tItems.SetSize(25);
  //_tExit.SetSize(25);
  //_tPlay.SetColor(sf::Color(0, 0, 0));
  //_tCredits.SetColor(sf::Color(0, 0, 0));
  //_tItems.SetColor(sf::Color(0, 0, 0));
  //_tExit.SetColor(sf::Color(0, 0, 0));
  //_tPlay.SetPosition(325, 250);
  // _tCredits.SetPosition(275, 350);
  //_tItems.SetPosition(225, 450);
  //_tExit.SetPosition(175, 550);
}

void	MainWindow::InitCredits()
{
 if (!_Ibackground.LoadFromFile("./img/credits.jpg"))
    {
      std::cerr << "Error: LoadFromFile img/background_menu.jpg failed!" 
		<< std::endl;
    }
  _background.SetImage(_Ibackground);
  _background.SetPosition(0, 0);
  _background.Resize(800, 600);

  //  if (!_menuFont.LoadFromFile("font/menuFont.ttf"))
  //{
  //  std::cerr << "Error: LoadFromFile font/menuFont.ttf failed!" 
  //		<< std::endl;
  //}
  //else
  //{
  //  _tPlay.SetFont(_menuFont);
  //  _tCredits.SetFont(_menuFont);
  //  _tItems.SetFont(_menuFont);
  //  _tExit.SetFont(_menuFont); 
  //}
  _tPlay.SetText("1 : Menu");
  _tCredits.SetText("");
  _tItems.SetText("");
  _tExit.SetText("");
  //_tPlay.SetSize(25);
  //_tCredits.SetSize(25);
  //_tItems.SetSize(25);
  //_tExit.SetSize(25);
  //_tPlay.SetColor(sf::Color(0, 0, 0));
  //_tCredits.SetColor(sf::Color(0, 0, 0));
  //_tItems.SetColor(sf::Color(0, 0, 0));
  //_tExit.SetColor(sf::Color(0, 0, 0));
  //_tPlay.SetPosition(325, 250);
  //_tCredits.SetPosition(275, 350);
  //_tItems.SetPosition(225, 450);
  //_tExit.SetPosition(175, 550);
}

void	MainWindow::DrawAll()
{
  _mainWindow.Draw(_background);
  _mainWindow.Draw(_tPlay);
  _mainWindow.Draw(_tCredits);
  _mainWindow.Draw(_tItems);
  _mainWindow.Draw(_tExit);
}

bool	MainWindow::IsOpened()
{
  return _mainWindow.IsOpened();
}

bool	MainWindow::GetEvent()
{
  if (_mainWindow.GetEvent(_event))
    return true;
  else
    return false;
}

bool	MainWindow::CloseEvent()
{
  if (_event.Type == sf::Event::Closed || _mainWindow.GetInput().IsKeyDown(sf::Key::Escape))
    return true;
  else
    return false;
}

void	MainWindow::Close()
{
  _mainWindow.Close();
}

void	MainWindow::Clear()
{
  _mainWindow.Clear(sf::Color(0, 0, 0));
}

void	MainWindow::Display()
{
  _mainWindow.Display();
}

void	MainWindow::MainMenuLoop()
{
  InitMenu();
  while (_mainWindow.IsOpened())
    {
      while (_mainWindow.GetEvent(_event))
	{
	  if (CloseEvent() || _mainWindow.GetInput().IsKeyDown(sf::Key::Num4))
	    {
	      Close();
	    }
	  if (_mainWindow.GetInput().IsKeyDown(sf::Key::Num1))
	    GameListLoop();
	  if (_mainWindow.GetInput().IsKeyDown(sf::Key::Num2))
	    CreditsLoop();
	}
      Clear();
      DrawAll();
      Display();
    }

}

int	MainWindow::GameListLoop()
{
  InitGameList();
  while (_mainWindow.IsOpened())
    {
      while (_mainWindow.GetEvent(_event))
	{
	  if (CloseEvent())
	    {
	      Close();
	    }
	  if (_mainWindow.GetInput().IsKeyDown(sf::Key::Num1))
	    break;//join party one
	  if (_mainWindow.GetInput().IsKeyDown(sf::Key::Num2))
	    break;//join party two
	  if (_mainWindow.GetInput().IsKeyDown(sf::Key::Num3))
	    break;//join party three
	  if (_mainWindow.GetInput().IsKeyDown(sf::Key::Num4))
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
  InitCredits();
  while (_mainWindow.IsOpened())
    {
      while (_mainWindow.GetEvent(_event))
	{
	  if (CloseEvent())
	    {
	      Close();
	    }
	  if (_mainWindow.GetInput().IsKeyDown(sf::Key::Num1))
	    return 0;
	}
      Clear();
      DrawAll();
      Display();
    }
  return 0;
}
