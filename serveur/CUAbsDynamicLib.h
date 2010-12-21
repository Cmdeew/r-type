#ifndef _CUABSDYNAMICLIB_H_
# define _CUABSDYNAMICLIB_H_

#ifndef _WIN32
#include "AbsDynamicLib.h"

class	CUAbsDynamicLib : public AbsDynamicLib
{
 public:
  hand	AOpenLib(pstr name);
  bool	ACloseLib(hand lib);
  addr	ASymLib(hand lib, const char *symbol);
  CUAbsDynamicLib();
  ~CUAbsDynamicLib();
};
#endif

#endif //_CUABSTHREAD_H_
