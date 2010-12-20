#include "MainWindow.h"

int	main()
{
  MainWindow	test;
  
  test.InitBackground();
  test.InitText();
  while (test.IsOpened())
    {
      test.Clear();
      while (test.GetEvent())
	{
	  if (test.CloseEvent())
	    test.Close();
	}
      test.DrawAll();
      test.Display();
    }
  return (0);
}
