#include	"Player.h"

Player::Player()
{
  _id = 0;
  _posx = 10;
  _posy = 10;
  _life = 3;
}

Player::Player(unsigned char id)
{
  _id = id;
  _posx = 10;
  _posy = 10;
  _life = 3;
}

Player::~Player()
{

}

void	Player::setId(unsigned char id)
{
  _id = id;
}

void	Player::setPosx(unsigned char x)
{
  _posx = x;
}

void	Player::setPosy(unsigned char y)
{
  _posy = y;
}

void	Player::setLife(unsigned char life)
{
  _life = life;
}

unsigned char Player::getId()
{
  return (_id);
}

unsigned char Player::getPosx()
{
  return (_posx);
}

unsigned char Player::getPosy()
{
  return (_posy);
}

unsigned char	Player::getLife()
{
  return (_life);
}

