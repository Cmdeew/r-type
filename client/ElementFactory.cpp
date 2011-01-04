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
	break;
      }
    case 2:
      {
	nElement = new Element(posx, posy, 4, id, type);
	nElement->setSprite(_imgCenter->getLplayer2());
	break;
      }
    case 3:
      {
	nElement = new Element(posx, posy, 4, id, type);
	nElement->setSprite(_imgCenter->getLplayer3());
	break;
      }
    case 4:
      {
	nElement = new Element(posx, posy, 4, id, type);
	nElement->setSprite(_imgCenter->getLplayer4());
	break;
      }
    case 5:
      {
	nElement = new Element(posx, posy, 1, id, type);
	break;
      }
    case 6:
      {
	nElement = new Element(posx, posy, 1, id, type);
	break;
      }
    case 7:
      {
	nElement = new Element(posx, posy, 99, id, type);
	break;
      }
    case 11:
      {
	nElement = new Element(posx, posy, 1, id, type);
	nElement->setSprite(_imgCenter->getLmonster1());
	break;
      }
    case 12:
      {
	nElement = new Element(posx, posy, 1, id, type);
	break;
      }
    case 13:
      {
	nElement = new Element(posx, posy, 1, id, type);
	break;
      }
    case 14:
      {
	nElement = new Element(posx, posy, 1, id, type);
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
	break;
      }
    case 22:
      {
	nElement = new Element(posx, posy, 200, id, type);
	break;
      }
    case 23:
      {
	nElement = new Element(posx, posy, 255, id, type);
	break;
      }
    case 24:
      {
	nElement = new Element(posx, posy, 0, id, type);
      }
    default:
      return NULL;
    }
  return nElement;
}

