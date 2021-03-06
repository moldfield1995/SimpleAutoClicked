#include <Windows.h>
#include <WinUser.h>
#include <thread>
#include <iostream>
int main()
{
	std::cout << "To toggle clicking on and off press scroll lock" << '\n';
	//Sets up mouse down
	PINPUT mouseDownInput = new INPUT();
	mouseDownInput->type = 0;
	mouseDownInput->mi = MOUSEINPUT{ 0,0,0,MOUSEEVENTF_LEFTDOWN,0,0 };
	//Sets up mouse up
	PINPUT mouseUpInput = new INPUT();
	mouseUpInput->type = 0;
	mouseUpInput->mi = MOUSEINPUT{ 0,0,0,MOUSEEVENTF_LEFTUP,0,0 };
	//allows the end user to click scroll lock
	Sleep(2000);

	while (true)
	{
		//checks if scroll lock is toggled
		while ((GetKeyState(VK_SCROLL) == 0x01))
		{
			Sleep(1000);
		}
		//inputs the click
		SendInput(1, mouseDownInput, sizeof(INPUT));
		Sleep(10);
		SendInput(1, mouseUpInput, sizeof(INPUT));
		Sleep(500);
	}
    return 0;
}

