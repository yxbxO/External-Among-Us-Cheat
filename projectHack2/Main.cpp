#include<iostream>
#include<windows.h>
#include<vector>
#include "proc.h"
#include<tchar.h>
#include"ImpHax.h"



int main() {
	//Get procID of the target process
	DWORD procID = GetProcid(L"Among Us.exe");
	std::cout << "procID = " << procID << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

	//intro
	std::cout << "\nWelcome to a simple Among Us hack!\n\Press SPACE to get started, or anywhere else to exit" << std::endl;
	std::cout << "\n-----------------------------------------" << std::endl;
	system("pause > null");

	int playerInput;
	int off1 = 0x1C;

	do {
		//Menu options
		std::cout << "\nChoose what you would like to change:\n	> Player Settings = 0\n	> Lobby Settings  = 1\n	> Imposter Hacks  = 2\n	> Exit App        = 3" << std::endl;
		std::cin >> playerInput;

		//gets base address of lobby, player, imp
		uintptr_t baseAddress = mainMenu(playerInput, procID);

		switch (playerInput)
		{
		case 0:
			PLsetting(procID, NULL);
			break;
		case 1:
			std::cout << "nothing special yet\n" << std::endl;
			return 0;
		case 2:
			//displays imposter hax
			doImphax(procID, baseAddress);
			break;
		case 3:
			std::cout << "\nExiting" << std::endl;
			Sleep(3000);
			return 0;
		}
	} while (playerInput != 3);



	/*//gets the process handle
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);

	//resolve the offsets
	uintptr_t modbase = GetModuleBaseAddress(procID, L"GameAssembly.dll");
	std::vector<unsigned int> plOffset = { 0x5c };
	uintptr_t pladdr = FindDMAAddy(hProcess, modbase, plOffset);
	std::cout << "current pointer to the Adrress = 0x" << std::hex << pladdr << std::endl;

	plOffset.push_back(off1);*/



	return 0;
}