#ifndef _IABSDYNAMICLIB_H_
# define _IABSDYNAMICLIB_H_

#include <iostream>

typedef void *	hand;
typedef void *	pstr;
typedef void *	addr;

class	IAbsDynamicLib
{
 public:
  virtual hand	AOpenLib(pstr name) = 0;
  virtual bool	ACloseLib(hand lib) = 0;
  virtual addr	ASymLib(hand lib, const char *symbol) = 0;
};

#endif //_IABSDYNAMICLIB_H_
