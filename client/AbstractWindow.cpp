#include "AbstractWindow.h"
#include <sstream>

AbstractWindow::AbstractWindow()
{
  _App.create(sf::VideoMode(800, 775, 32), "Best r-type ever!");
  _App.setFramerateLimit(60);
  if (!_backgroundImg.loadFromFile("img/background1.jpg"))
    std::cerr << "Error: Unable to load background" << std::endl;
  if (!_background2Img.loadFromFile("img/background2.jpg"))
    std::cerr << "Error: Unable to load background" << std::endl;
  if (!_background3Img.loadFromFile("img/background3.jpg"))
    std::cerr << "Error: Unable to load background" << std::endl;
  if (!_background4Img.loadFromFile("img/background4.jpg"))
    std::cerr << "Error: Unable to load background" << std::endl;

  if (!_interfaceImg.loadFromFile("sprite/interface.png"))
    std::cerr << "Error: Unable to load the interface" << std::endl;
  if (!_lifeImg.loadFromFile("sprite/lifeMenu.png"))
    std::cerr << "Error: Unable to Load Image" << std::endl;
  if (_gameOverImg.loadFromFile("img/gameover1.jpg"))
    _gameOver.setTexture(_gameOverImg);
  if (!_font.loadFromFile("font/score.ttf"))
    std::cerr << "Error: Unable to load font" << std::endl;
  else
    {
      /*
        Looking for sf::String::setFont() in SFML 2
      _score.SetFont(_font);
      _life.SetFont(_font);
      _id.SetFont(_font);
      _level.SetFont(_font);
      */
    }
  _score = "score:";
  //_score.SetSize(25);
  //_score.SetPosition(605, 650);
  //_level.SetSize(25);
  //_level.SetPosition(310, 660);
  //_score.SetColor(sf::Color(255, 255, 255));

  _background.setTexture(_backgroundImg);
  _background2.setTexture(_background2Img);
  _background3.setTexture(_background3Img);
  _background4.setTexture(_background4Img);

  _lifeSprite.setTexture(_lifeImg);
  _interface.setTexture(_interfaceImg);
  _lifeSprite.setPosition(605, 700);
  _lifeSprite.scale(45,40);
  //  _life.SetSize(25);
  //  _life.SetPosition(645, 700);
  //  _id.SetSize(25);
  //  _id.SetPosition(300, 700);
  _background.setOrigin(0, 50);
  _interface.setPosition(0, 600);
}

void	AbstractWindow::Clear()
{
  _App.clear(sf::Color(0, 0, 0));
}

void	AbstractWindow::Draw(const std::list<Element *> &list, int mode, int level)
{
  std::list<Element *>::const_iterator	it;
  std::list<sf::Sprite>::iterator	iter;
  Element				*elem;

  if (mode == 0)
    {
      it = list.begin();
      if (level == 1)
	_App.draw(_background);
      else if (level == 2)
	_App.draw(_background2);
      else if (level == 3)
	_App.draw(_background3);
      else if (level == 4)
	_App.draw(_background4);
      _App.draw(_interface);
      //_App.draw(_level);
      //_App.draw(_score);
      //_App.draw(_lifeSprite);
      //_App.draw(_life);
      //_App.draw(_id);
      _App.draw(_player);
      _App.draw(_portrait);
      while (it != list.end())
	{
	  elem = *it;
	  if (elem)
	    {
	      iter = elem->_iter;
	      elem->setPosSprite(*iter);
	      _App.draw(*iter);
	    }
	  it++;
	}
    }
  else
    _App.draw(_gameOver);
}

bool	AbstractWindow::IsAnEvent()
{
  return _App.pollEvent(_event);
}

void	AbstractWindow::Display()
{
  _App.display();
}

bool	AbstractWindow::Quit()
{
  //if (_event.Type == sf::Event::Closed || _App.GetInput().IsKeyDown(sf::Key::Escape))
  //  if (_event.type == sf::Event::Closed || _App.GetInput().IsKeyDown(sf::Keyboard::Escape))
  if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      _App.close();
      return true;
    }
  return false;
}

void	AbstractWindow::setPlayer(sf::Sprite sprite, int id)
{
  _player = sprite;
  _player.setPosition(250, 710);
  switch (id)
    {
    case 1:
      {
	if (!_portraitImg.loadFromFile("sprite/inter_player1.png"))
	  std::cerr << "Error: Unable to load the interface" << std::endl;
	break;
      }
    case 2:
      {
	if (!_portraitImg.loadFromFile("sprite/inter_player2.png"))
	  std::cerr << "Error: Unable to load the interface" << std::endl;
	break;
      }
    case 3:
      {
	if (!_portraitImg.loadFromFile("sprite/inter_player3.png"))
	  std::cerr << "Error: Unable to load the interface" << std::endl;
	break;
      }
    case 4:
      {
	if (!_portraitImg.loadFromFile("sprite/inter_player4.png"))
	  std::cerr << "Error: Unable to load the interface" << std::endl;
	break;
      }
    }
  _portrait.setTexture(_portraitImg);
  _portrait.setPosition(500, 665);
}

bool	AbstractWindow::IsLaunch()
{
  return _App.isOpen();
}

bool	AbstractWindow::IsKeyUp()
{
  //return _App.GetInput().IsKeyDown(sf::Key::Up);
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
}

bool	AbstractWindow::IsKeyDown()
{
  //return _App.GetInput().IsKeyDown(sf::Key::Down);
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

bool	AbstractWindow::IsKeyLeft()
{
  //return _App.GetInput().IsKeyDown(sf::Key::Left);
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

bool	AbstractWindow::IsKeyRight()
{
  //return _App.GetInput().IsKeyDown(sf::Key::Right);
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

bool	AbstractWindow::IsShooting()
{
  //return _App.GetInput().IsKeyDown(sf::Key::Space);
  return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void	AbstractWindow::MoveBackground()
{
  sf::Sprite	background;

  if (_background.getPosition().x == -1100)
    {
      /*
      _background.SetX(0);
      _background2.SetX(0);
      _background3.SetX(0);
      _background4.SetX(0);
      */
      _background.setPosition(0, 0);
      _background2.setPosition(0, 0);
      _background3.setPosition(0, 0);
      _background4.setPosition(0, 0);
    }
  _background.move(-1, 0);
  _background2.move(-1, 0);
  _background3.move(-1, 0);
  _background4.move(-1, 0);
}

void	AbstractWindow::SetText(int score, int life, int id, int level)
{
  std::string	tmp;
  std::ostringstream oss;

  oss << score;
  tmp = oss.str();
  _score = "score: " + tmp;
  oss.str("");
  oss << life;
  tmp = oss.str();
  _life = " x" + tmp;
  oss.str("");
  oss << id;
  tmp = oss.str();
  _id = "player " + tmp;
  oss.str("");
  oss << level;
  tmp = oss.str();
  _level = "level " + tmp;
}

void	AbstractWindow::Close()
{
  _App.close();
}
