#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include "Object.h"
#include "./inc/UMonsterOne.h"

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

MonsterOne::MonsterOne(char id, char x, char y, char type)
{
  m_id = id;
  m_x = x;
  m_y = y;
  m_type = 11;
  m_lim = 0;
}

MonsterOne::~MonsterOne()
{

}

void MonsterOne::move()
{
  std::cout << "Mouvement du type monstre 1" << std::endl;
  m_x--;
}


extern "C"
{
   __declspec(dllexport) MonsterOne *Create(char id, char x, char y)
  {
    return new MonsterOne(id, x, y);
  }
}
