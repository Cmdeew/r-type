#include "AbstractWindow.h"

AbstractWindow::AbstractWindow()
{
  _App.Create(sf::VideoMode(800, 600, 32), "Best r-type ever!");
  _App.SetFramerateLimit(60);
  if (!_backgroundImg.LoadFromFile("img/background1.jpg"))
    std::cerr << "Error: Unable to load background" << std::endl;
  if (!_font.LoadFromFile("font/score.ttf"))
    std::cerr << "Error: Unable to load font" << std::endl;
  else
    _score.SetFont(_font);
  _score.SetText("score:");
  _score.SetSize(25);
  _score.SetPosition(500, 0);
  _score.SetColor(sf::Color(255, 255, 255));
  _background.SetImage(_backgroundImg);
}

void	AbstractWindow::Clear()
{
  _App.Clear(sf::Color(0, 0, 0));
}

void	AbstractWindow::Draw(const std::list<Element *> &list)
{
  std::list<Element *>::const_iterator	it;
  Element				*elem;
  std::list<sf::Sprite>::iterator	iter;

  it = list.begin();
  _App.Draw(_background);
  _App.Draw(_score);
  while (it != list.end())
    {
      elem = *it;
      if (elem)
	{
	  iter = elem->getSprite().begin();
	  elem->setPosSprite(*iter);
	  _App.Draw(*iter);
	}
      it++;
    }
}

bool	AbstractWindow::IsAnEvent()
{
  return _App.GetEvent(_event);
}

void	AbstractWindow::Display()
{
  _App.Display();
}

bool	AbstractWindow::Quit()
{
  if (_event.Type == sf::Event::Closed || _App.GetInput().IsKeyDown(sf::Key::Escape))
    {
      _App.Close();
      return true;
    }
  return false;
}

bool	AbstractWindow::IsLaunch()
{
  return _App.IsOpened();
}

bool	AbstractWindow::IsKeyUp()
{
  return _App.GetInput().IsKeyDown(sf::Key::Up);
}

bool	AbstractWindow::IsKeyDown()
{
  return _App.GetInput().IsKeyDown(sf::Key::Down);
}

bool	AbstractWindow::IsKeyLeft()
{
  return _App.GetInput().IsKeyDown(sf::Key::Left);
}

bool	AbstractWindow::IsKeyRight()
{
  return _App.GetInput().IsKeyDown(sf::Key::Right);
}

bool	AbstractWindow::IsShooting()
{
  return _App.GetInput().IsKeyDown(sf::Key::Space);
}

void	AbstractWindow::MoveBackground()
{
  sf::Sprite	background;

  if (_background.GetPosition().x == -1100)
    _background.SetX(0);
  _background.Move(-1, 0);
}

void	AbstractWindow::SetScore(int score)
{
  std::string	tmp;

  tmp = score;
  std::cout << tmp << std::endl;
  _score.SetText("score:" + tmp);
}
