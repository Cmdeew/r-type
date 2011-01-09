#include "AbstractWindow.h"
#include <sstream>

AbstractWindow::AbstractWindow()
{
  _App.Create(sf::VideoMode(800, 775, 32), "Best r-type ever!");
  _App.SetFramerateLimit(60);
  if (!_backgroundImg.LoadFromFile("img/background1.jpg"))
    std::cerr << "Error: Unable to load background" << std::endl;
  if (!_interfaceImg.LoadFromFile("sprite/interface.png"))
    std::cerr << "Error: Unable to load the interface" << std::endl;
  if (!_lifeImg.LoadFromFile("sprite/lifeMenu.png"))
    std::cerr << "Error: Unable to Load Image" << std::endl;
  if (!_font.LoadFromFile("font/score.ttf"))
    std::cerr << "Error: Unable to load font" << std::endl;
  else
    {
      _score.SetFont(_font);
      _life.SetFont(_font);
      _id.SetFont(_font);
      _level.SetFont(_font);
    }
  _score.SetText("score:");
  _score.SetSize(25);
  _score.SetPosition(605, 650);
  _level.SetSize(25);
  _level.SetPosition(310, 660);
  _score.SetColor(sf::Color(255, 255, 255));
  _background.SetImage(_backgroundImg);
  _lifeSprite.SetImage(_lifeImg);
  _interface.SetImage(_interfaceImg);
  _lifeSprite.SetPosition(605, 700);
  _lifeSprite.Resize(45,40);
  _life.SetSize(25);
  _life.SetPosition(645, 700);
  _id.SetSize(25);
  _id.SetPosition(300, 700);
  _background.SetCenter(0, 50);
  _interface.SetPosition(0, 600);
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
  _App.Draw(_interface);
  _App.Draw(_level);
  _App.Draw(_score);
  _App.Draw(_lifeSprite);
  _App.Draw(_life);
  _App.Draw(_id);
  _App.Draw(_player);
  _App.Draw(_portrait);
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

void	AbstractWindow::setPlayer(sf::Sprite sprite, int id)
{
  _player = sprite;
  _player.SetPosition(250, 710);
  switch (id)
    {
    case 1:
      {
	if (!_portraitImg.LoadFromFile("sprite/inter_player1.png"))
	  std::cerr << "Error: Unable to load the interface" << std::endl;
	break;
      }
    case 2:
      {
	if (!_portraitImg.LoadFromFile("sprite/inter_player2.png"))
	  std::cerr << "Error: Unable to load the interface" << std::endl;
	break;
      }
    case 3:
      {
	if (!_portraitImg.LoadFromFile("sprite/inter_player3.png"))
	  std::cerr << "Error: Unable to load the interface" << std::endl;
	break;
      }
    case 4:
      {
	if (!_portraitImg.LoadFromFile("sprite/inter_player4.png"))
	  std::cerr << "Error: Unable to load the interface" << std::endl;
	break;
      }
    }
  _portrait.SetImage(_portraitImg);
  _portrait.SetPosition(500, 665);
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

void	AbstractWindow::SetText(int score, int life, int id, int level)
{
  std::string	tmp;
  std::ostringstream oss;

  oss << score;
  tmp = oss.str();
  _score.SetText("score: " + tmp);
  oss.str("");
  oss << life;
  tmp = oss.str();
  _life.SetText(" x" + tmp);
  oss.str("");
  oss << id;
  tmp = oss.str();
  _id.SetText("player " + tmp);
  oss.str("");
  oss << level;
  tmp = oss.str();
  _level.SetText("level " + tmp);
}
