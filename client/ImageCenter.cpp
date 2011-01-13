#include "ImageCenter.h"

ImageCenter::ImageCenter()
{
  sf::Image	img;

  //player 1
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
  //player 2
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
  //player 3
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
  //player 4
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
  //monster 1
  img.LoadFromFile("sprite/monster1pos1.png");
  _lmonster1.push_back(img);
  img.LoadFromFile("sprite/monster1pos2.png");
  _lmonster1.push_back(img);
  img.LoadFromFile("sprite/monster1pos3.png");
  _lmonster1.push_back(img);
  //monster2
  img.LoadFromFile("sprite/monster2.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_1.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_2.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_3.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_4.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_5.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_6.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_7.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_8.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_9.png");
  _lmonster2.push_back(img);
  img.LoadFromFile("sprite/monster2_10.png");
  _lmonster2.push_back(img);
  //monster 3
  img.LoadFromFile("sprite/monster3pos1.png");
  _lmonster3.push_back(img);
  img.LoadFromFile("sprite/monster3pos2.png");
  _lmonster3.push_back(img);
  img.LoadFromFile("sprite/monster3pos3.png");
  _lmonster3.push_back(img);
  img.LoadFromFile("sprite/monster3pos4.png");
  _lmonster3.push_back(img);
  //monster 4
  img.LoadFromFile("sprite/monster13_1.png");
  _lmonster4.push_back(img);
  img.LoadFromFile("sprite/monster13_2.png");
  _lmonster4.push_back(img);
  img.LoadFromFile("sprite/monster13_3.png");
  _lmonster4.push_back(img);
  img.LoadFromFile("sprite/monster13_4.png");
  _lmonster4.push_back(img);
  img.LoadFromFile("sprite/monster13_5.png");
  _lmonster4.push_back(img);
  img.LoadFromFile("sprite/monster13_6.png");
  _lmonster4.push_back(img);
  img.LoadFromFile("sprite/monster13_7.png");
  _lmonster4.push_back(img);
  img.LoadFromFile("sprite/monster13_8.png");
  _lmonster4.push_back(img);
  //monster 15
  img.LoadFromFile("sprite/monster3pos1.png");
  _lmonster5.push_back(img);
  img.LoadFromFile("sprite/monster3pos2.png");
  _lmonster5.push_back(img);
  img.LoadFromFile("sprite/monster3pos3.png");
  _lmonster5.push_back(img);
  img.LoadFromFile("sprite/monster3pos4.png");
  _lmonster5.push_back(img);
  //boss one
  img.LoadFromFile("sprite/boss1_1.png");
  _lboss1.push_back(img);
  img.LoadFromFile("sprite/boss1_2.png");
  _lboss1.push_back(img);
  img.LoadFromFile("sprite/boss1_3.png");
  _lboss1.push_back(img);
  img.LoadFromFile("sprite/boss1_4.png");
  _lboss1.push_back(img);
  img.LoadFromFile("sprite/boss1_5.png");
  _lboss1.push_back(img);
  img.LoadFromFile("sprite/boss1_4.png");
  _lboss1.push_back(img);
  img.LoadFromFile("sprite/boss1_3.png");
  _lboss1.push_back(img);
  img.LoadFromFile("sprite/boss1_2.png");
  _lboss1.push_back(img);
  //boss two
  img.LoadFromFile("sprite/boss_two.png");
  _lboss2.push_back(img);
  //boss three
  img.LoadFromFile("sprite/boss_three_1.png");
  _lboss3.push_back(img);
  img.LoadFromFile("sprite/boss_three_2.png");
  _lboss3.push_back(img);
  img.LoadFromFile("sprite/boss_three_3.png");
  _lboss3.push_back(img);
  img.LoadFromFile("sprite/boss_three_4.png");
  _lboss3.push_back(img);
  img.LoadFromFile("sprite/boss_three_5.png");
  _lboss3.push_back(img);
  //boss four
  img.LoadFromFile("sprite/boss_four_1.png");
  _lboss4.push_back(img);
  img.LoadFromFile("sprite/boss_four_2.png");
  _lboss4.push_back(img);
  img.LoadFromFile("sprite/boss_four_3.png");
  _lboss4.push_back(img);
  img.LoadFromFile("sprite/boss_four_4.png");
  _lboss4.push_back(img);
  //wall
  img.LoadFromFile("sprite/wall1.png");
  _lwall1.push_back(img);
  //wall pop meduse up
  img.LoadFromFile("sprite/wall28_1.png");
  _lwall2.push_back(img);
  img.LoadFromFile("sprite/wall28_2.png");
  _lwall2.push_back(img);
  img.LoadFromFile("sprite/wall28_3.png");
  _lwall2.push_back(img);
  //wall pop meduse down
  img.LoadFromFile("sprite/wall29_1.png");
  _lwall3.push_back(img);
  img.LoadFromFile("sprite/wall29_2.png");
  _lwall3.push_back(img);  
  img.LoadFromFile("sprite/wall29_3.png");
  _lwall3.push_back(img);
  //wall tete verte up
  img.LoadFromFile("sprite/wall30_1.png");
  _lwall4.push_back(img);
  img.LoadFromFile("sprite/wall30_2.png");
  _lwall4.push_back(img);
  //wall tete verte down
  img.LoadFromFile("sprite/wall31_1.png");
  _lwall5.push_back(img);
  img.LoadFromFile("sprite/wall31_2.png");
  _lwall5.push_back(img);
  //shoot player
  img.LoadFromFile("sprite/shoot1.png");
  _lweapon1.push_back(img);
  //shoot player level 2
  img.LoadFromFile("sprite/shoot10_1.png");
  _lweapon5.push_back(img);
  img.LoadFromFile("sprite/shoot10_2.png");
  _lweapon5.push_back(img);
  img.LoadFromFile("sprite/shoot10_3.png");
  _lweapon5.push_back(img);
  img.LoadFromFile("sprite/shoot10_4.png");
  _lweapon5.push_back(img);
  img.LoadFromFile("sprite/shoot10_5.png");
  _lweapon5.push_back(img);
  img.LoadFromFile("sprite/shoot10_6.png");
  _lweapon5.push_back(img);
  //shoot player level 3
  img.LoadFromFile("sprite/shoot32_1.png");
  _lweapon6.push_back(img);
  img.LoadFromFile("sprite/shoot32_2.png");
  _lweapon6.push_back(img);
  //shoot trash
  img.LoadFromFile("sprite/shoot6.png");
  _lweapon2.push_back(img);
  //shoot boss
  img.LoadFromFile("sprite/shoot7_1.png");
  _lweapon3.push_back(img);
  img.LoadFromFile("sprite/shoot7_2.png");
  _lweapon3.push_back(img);
  img.LoadFromFile("sprite/shoot7_3.png");
  _lweapon3.push_back(img);
  //shoot diagonale
  img.LoadFromFile("sprite/shoot6_1.png");
  _lweapon4.push_back(img);
  img.LoadFromFile("sprite/shoot6_2.png");
  _lweapon4.push_back(img);
    img.LoadFromFile("sprite/shoot6_3.png");
  _lweapon4.push_back(img);
    img.LoadFromFile("sprite/shoot6_4.png");
  _lweapon4.push_back(img);
  //explosion
  img.LoadFromFile("sprite/explo1.png");
  _lexplo1.push_back(img);
  img.LoadFromFile("sprite/explo2.png");
  _lexplo1.push_back(img);
  img.LoadFromFile("sprite/explo3.png");
  _lexplo1.push_back(img);
  img.LoadFromFile("sprite/explo4.png");
  _lexplo1.push_back(img);
  img.LoadFromFile("sprite/explo5.png");
  _lexplo1.push_back(img);
  img.LoadFromFile("sprite/explo6.png");
  _lexplo1.push_back(img);
  img.LoadFromFile("sprite/explo7.png");
  _lexplo1.push_back(img);
  img.LoadFromFile("sprite/explo8.png");
  _lexplo1.push_back(img);
  //astronaute
  img.LoadFromFile("sprite/astronaute_1.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_2.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_3.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_4.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_5.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_6.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_7.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_8.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_9.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_10.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_11.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_12.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_13.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_14.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_15.png");
  _lastronaute1.push_back(img);
  img.LoadFromFile("sprite/astronaute_16.png");
  _lastronaute1.push_back(img);
  //life
  img.LoadFromFile("sprite/life.png");
  _llife1.push_back(img);

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

const std::list<sf::Image>    &ImageCenter::getLweapon3() const
{
  return _lweapon3;
}

const std::list<sf::Image>    &ImageCenter::getLweapon4() const
{
  return _lweapon4;
}

const std::list<sf::Image>    &ImageCenter::getLweapon5() const
{
  return _lweapon5;
}

const std::list<sf::Image>    &ImageCenter::getLweapon6() const
{
  return _lweapon6;
}

const std::list<sf::Image>    &ImageCenter::getLmeteor1() const
{
  return _lmeteor1;
}

const std::list<sf::Image>    &ImageCenter::getLedge1() const
{
  return _ledge1;
}

const std::list<sf::Image>    &ImageCenter::getLwall1() const
{
  return _lwall1;
}

const std::list<sf::Image>    &ImageCenter::getLwall2() const
{
  return _lwall2;
}

const std::list<sf::Image>    &ImageCenter::getLwall3() const
{
  return _lwall3;
}

const std::list<sf::Image>    &ImageCenter::getLwall4() const
{
  return _lwall4;
}

const std::list<sf::Image>    &ImageCenter::getLwall5() const
{
  return _lwall5;
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

const std::list<sf::Image>    &ImageCenter::getLboss4() const
{
  return _lboss4;
}

const std::list<sf::Image>    &ImageCenter::getLexplo1() const
{
  return _lexplo1;
}

const std::list<sf::Image>    &ImageCenter::getLastronaute1() const
{
  return _lastronaute1;
}

const std::list<sf::Image>    &ImageCenter::getLlife1() const
{
  return _llife1;
}
