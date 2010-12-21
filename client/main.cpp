#include <iostream>
#include "gameclient.h"

int main()
{
	std::cout << "coucou !" << std::endl;
	gameClient gamer;
	gamer.loopClient();
	return (0);
}
