#include "AbstractWindow.h"

AbstractWindow::AbstractWindow()
{
  _App.Create(sf::VideoMode(800, 600, 32), "Best r-type ever!");
  _App.SetFramerateLimit(60);
  _backgroundImg.LoadFromFile("img/background1.jpg");
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
  if (_event.Type == sf::Event::Closed)
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


void	AbstractWindow::MoveBackground()
{
  _background.Move(-0.2, 0);
}
