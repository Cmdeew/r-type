#include "ImageCenter.h"

ImageCenter::ImageCenter()
{
  sf::Image	img;

  img.LoadFromFile("sprite/player1.png");
  _lplayer1.push_back(img);
  img.LoadFromFile("sprite/player1_up1.png");
  _lplayer1.push_back(img);
  img.LoadFromFile("sprite/player1_up2.png");
  _lplayer1.push_back(img);
  img.LoadFromFile("sprite/player1_down1.png");
  _lplayer1.push_back(img);
  img.LoadFromFile("sprite/player1_down2.png");
  _lplayer1.push_back(img);
  img.LoadFromFile("sprite/player1_up1.png");
  _lplayer1.push_back(img);

  img.LoadFromFile("sprite/player2.png");
  _lplayer2.push_back(img);
  img.LoadFromFile("sprite/player2_up1.png");
  _lplayer2.push_back(img);
  img.LoadFromFile("sprite/player2_up2.png");
  _lplayer2.push_back(img);
  img.LoadFromFile("sprite/player2_down1.png");
  _lplayer2.push_back(img);
  img.LoadFromFile("sprite/player2_down2.png");
  _lplayer2.push_back(img);
  img.LoadFromFile("sprite/player2_up1.png");
  _lplayer2.push_back(img);

  img.LoadFromFile("sprite/player3.png");
  _lplayer3.push_back(img);
  img.LoadFromFile("sprite/player3_up1.png");
  _lplayer3.push_back(img);
  img.LoadFromFile("sprite/player3_up2.png");
  _lplayer3.push_back(img);
  img.LoadFromFile("sprite/player3_down1.png");
  _lplayer3.push_back(img);
  img.LoadFromFile("sprite/player3_down2.png");
  _lplayer3.push_back(img);
  img.LoadFromFile("sprite/player3_up1.png");
  _lplayer3.push_back(img);

  img.LoadFromFile("sprite/player4.png");
  _lplayer4.push_back(img);
  img.LoadFromFile("sprite/player4_up1.png");
  _lplayer4.push_back(img);
  img.LoadFromFile("sprite/player4_up2.png");
  _lplayer4.push_back(img);
  img.LoadFromFile("sprite/player4_down1.png");
  _lplayer4.push_back(img);
  img.LoadFromFile("sprite/player4_down2.png");
  _lplayer4.push_back(img);
  img.LoadFromFile("sprite/player4_up1.png");
  _lplayer4.push_back(img);

  img.LoadFromFile("sprite/monster11.png");
  _lmonster1.push_back(img);

  img.LoadFromFile("sprite/monster12.png");
  _lmonster2.push_back(img);

  img.LoadFromFile("sprite/shoot5.png");
  _lweapon1.push_back(img);

  img.LoadFromFile("sprite/shoot6.png");
  _lweapon2.push_back(img);

}

const std::list<sf::Image>    &ImageCenter::getLplayer1() const
{
  return _lplayer1;
}

const std::list<sf::Image>    &ImageCenter::getLplayer2() const
{
  return _lplayer2;
}

const std::list<sf::Image>    &ImageCenter::getLplayer3() const
{
  return _lplayer3;
}

const std::list<sf::Image>    &ImageCenter::getLplayer4() const
{
  return _lplayer4;
}

const std::list<sf::Image>    &ImageCenter::getLweapon1() const
{
  return _lweapon1;
}

const std::list<sf::Image>    &ImageCenter::getLweapon2() const
{
  return _lweapon2;
}

const std::list<sf::Image>    &ImageCenter::getLmeteor1() const
{
  return _lmeteor1;
}

const std::list<sf::Image>    &ImageCenter::getLedge1() const
{
  return _ledge1;
}

const std::list<sf::Image>    &ImageCenter::getLmonster1() const
{
  return _lmonster1;
}

const std::list<sf::Image>    &ImageCenter::getLmonster2() const
{
  return _lmonster2;
}

const std::list<sf::Image>    &ImageCenter::getLmonster3() const
{
  return _lmonster3;
}

const std::list<sf::Image>    &ImageCenter::getLmonster4() const
{
  return _lmonster4;
}

const std::list<sf::Image>    &ImageCenter::getLmonster5() const
{
  return _lmonster5;
}

const std::list<sf::Image>    &ImageCenter::getLmonster6() const
{
  return _lmonster6;
}

const std::list<sf::Image>    &ImageCenter::getLmonster7() const
{
  return _lmonster7;
}

const std::list<sf::Image>    &ImageCenter::getLmonster8() const
{
  return _lmonster8;
}

const std::list<sf::Image>    &ImageCenter::getLmonster9() const
{
  return _lmonster9;
}

const std::list<sf::Image>    &ImageCenter::getLboss1() const
{
  return _lboss1;
}

const std::list<sf::Image>    &ImageCenter::getLboss2() const
{
  return _lboss2;
}

const std::list<sf::Image>    &ImageCenter::getLboss3() const
{
  return _lboss3;
}

const std::list<sf::Image>    &ImageCenter::getLexplo1() const
{
  return _lexplo1;
}
