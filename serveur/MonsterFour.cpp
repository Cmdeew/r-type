#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include "Object.h"
#include "./inc/UMonsterFour.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		std::cout << ">>> [DLL] DLL_PROCESS_ATTACH";
		if (lpReserved == NULL)
		{
			std::cout << "\t dynamic load" << std::endl;
		}
		else
		{
			std::cout << "\t static load" << std::endl;
		}
		break;
	case DLL_THREAD_ATTACH:
		std::cout << ">>> [DLL] DLL_THREAD_ATTACH" << std::endl;
		break;
	case DLL_THREAD_DETACH:
		std::cout << ">>> [DLL] DLL_THREAD_DETACH" << std::endl;
		break;
	case DLL_PROCESS_DETACH:
		std::cout << ">>> [DLL] DLL_PROCESS_DETACH";
		if (lpReserved == NULL)
		{
			std::cout << "\t FreeLibrary called or DLL load failed" << std::endl;
		}
		else
		{
			std::cout << "\t Process terminated" << std::endl;
		}
		break;
	}
	return TRUE;
}

MonsterFour::MonsterFour(char id, char x, char y, char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = 14;
  m_lim = 0;
}

MonsterFour::~MonsterFour()
{

}

void MonsterFour::move()
{
  m_x--;
}

extern "C"
{
   __declspec(dllexport) MonsterFour *Create(char id, char x, char y)
  {
    return new MonsterFour(id, x, y);
  }
}