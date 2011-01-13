#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include "Object.h"
#include "./inc/UMonsterTwo.h"

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

MonsterTwo::MonsterTwo(char id, char x, char y, char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = 12;
  m_lim = 0;
}

MonsterTwo::~MonsterTwo()
{

}

void MonsterTwo::move()
{
  m_x--;
  if (m_lim < 5)
    m_y++;
  else
    m_y--;
  if (m_lim == 10)
    m_lim = 0;
  else
    m_lim++;
}

extern "C"
{
   __declspec(dllexport) MonsterTwo *Create(char id, char x, char y)
  {
    return new MonsterTwo(id, x, y);
  }
}

