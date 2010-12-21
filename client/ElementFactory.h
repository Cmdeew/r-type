#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H

#include "ImageCenter.h"
#include "Element.h"

class	ElementFactory
{
 private:
  ImageCenter	*_imgCenter;
 public:
  ElementFactory();
  Element	*FactoryMethod(unsigned char type, unsigned char id, unsigned char posx, 
			       unsigned char posy);
};

#endif //!ELEMENTFACTORY_H
