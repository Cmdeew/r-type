#include "ElementFactory.h"

ElementFactory::ElementFactory()
{
  _imgCenter = new ImageCenter();
}


Element	*ElementFactory::FactoryMethod(unsigned char type, unsigned char id, unsigned char posx, 
				       unsigned char posy)
{
  Element	*nElement;

  nElement = NULL;
  switch (type)
    {
    case 1:
      {
	nElement = new Element(posx, posy, 4, id, type);
	nElement->setSprite(_imgCenter->getLplayer1());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 2:
      {
	nElement = new Element(posx, posy, 4, id, type);
	nElement->setSprite(_imgCenter->getLplayer2());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 3:
      {
	nElement = new Element(posx, posy, 4, id, type);
	nElement->setSprite(_imgCenter->getLplayer3());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 4:
      {
	nElement = new Element(posx, posy, 4, id, type);
	nElement->setSprite(_imgCenter->getLplayer4());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 5:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLweapon1());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 6:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLweapon2());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 7:
      {
	nElement = new Element(posx, posy, 99, id, type);
	nElement->setSprite(_imgCenter->getLweapon3());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 8:
      {
	nElement = new Element(posx, posy, 99, id, type);
	nElement->setSprite(_imgCenter->getLweapon4());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 9:
      {
	nElement = new Element(posx, posy, 99, id, type);
	nElement->setSprite(_imgCenter->getLwall1());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 10:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLweapon5());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 11:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLmonster1());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 12:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLmonster2());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 13:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLmonster3());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 14:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLmonster4());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 15:
      {
	nElement = new Element(posx, posy, 1, id, type);
	break;
      }
    case 16:
      {
	nElement = new Element(posx, posy, 1, id, type);
	break;
      }
    case 17:
      {
	nElement = new Element(posx, posy, 1, id, type);
	break;
      }
    case 18:
      {
	nElement = new Element(posx, posy, 1, id, type);
	break;
      }
    case 19:
      {
	nElement = new Element(posx, posy, 1, id, type);
	break;
      }
    case 21:
      {
	nElement = new Element(posx, posy, 100, id, type);
	nElement->setSprite(_imgCenter->getLboss1());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 22:
      {
	nElement = new Element(posx, posy, 150, id, type);
	nElement->setSprite(_imgCenter->getLboss2());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 23:
      {
	nElement = new Element(posx, posy, 200, id, type);
	nElement->setSprite(_imgCenter->getLboss3());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 24:
      {
	nElement = new Element(posx, posy, 250, id, type);
	nElement->setSprite(_imgCenter->getLboss4());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 25:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLastronaute1());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 26:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLlife1());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    case 27:
      {
	nElement = new Element(posx, posy, 0, id, type);
	nElement->setSprite(_imgCenter->getLexplo1());
	nElement->_iter = nElement->getSprite().begin();
	break;
      }
    default:
      return NULL;
    }
  return nElement;
}

