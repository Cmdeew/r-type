#ifndef _CWABSDYNAMICLIB_H_
# define _CWABSDYNAMICLIB_H_

#ifdef _WIN32
#include "AbsDynamicLib.h"

class	CWAbsDynamicLib : public AbsDynamicLib
{
 public:
  hand	AOpenLib(pstr name);
  bool	ACloseLib(hand lib);
  addr	ASymLib(hand lib, const char *symbol);
  CWAbsDynamicLib();
  ~CWAbsDynamicLib();
};
#endif

#endif //_CUABSTHREAD_H_
