/*

KamstRec - Keyboard And Mouse State Recorder

A small and silent Win32 utility that can
record all keyboard & mouse state. It can write everything
to your console or special LOG file you specify.

Features:

* Small! No more that 64kb in size!
* Fast! You do not need too powerful computer to use this program!
* Silent! It works in hidden mode, but you can always switch between
hidden and console mode!
* Localizable! You can translate this program into your language easy and simply!

System Requirements:
Just have a computer, keyboard and mouse, LOL xD

Keep in mind that this is NOT a keylogger and NOT a malware.
Use this tool at your own risk. I am not responsible for any damage.

Thank you for using this program! Have a nice day!
Happy New 2022 Year!

Best Wishes,
Ivan Movchan aka NobootRecord.
St. Petersburg, Russia.

https://nobootrecord.github.io
*/

// Let's include some magic...
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Declare some variables we need
int old_kbd_data[256], new_kbd_data[256];
int lbutton, rbutton, mbutton;
char *msg;
POINT mouse_cur;
SYSTEMTIME st;
int oldX, oldY, newX, newY;
int asdasdf, qwerty;

// Null state
void NullState()
{
	asdasdf=lbutton+mbutton+rbutton+oldX+oldY;qwerty=0;	
}

// Get keyboard state
void KeyboardState()
{
		for (int i=0;i<256;i++) {
				old_kbd_data[i]=new_kbd_data[i];
				new_kbd_data[i]=GetAsyncKeyState(i);
		};
}

// Get mouse state
void MouseState()
{
	oldX = mouse_cur.x; oldY = mouse_cur.y;
	lbutton = (GetAsyncKeyState(VK_LBUTTON) & 0x8000);
	rbutton = (GetAsyncKeyState(VK_RBUTTON) & 0x8000);
	mbutton = (GetAsyncKeyState(VK_MBUTTON) & 0x8000);
	GetCursorPos(&mouse_cur);
	newX = mouse_cur.x; newY = mouse_cur.y;
}

// Print stuff
void PrintStuff()
{
	qwerty=lbutton+mbutton+rbutton+newX+newY;
	if (lbutton) printf("LBUTTON button pressed; "); if (mbutton) printf("MBUTTON button pressed; "); if (rbutton) printf("RBUTTON button pressed; ");	
	if ((newX+newY)!=(oldX+oldY)) printf("CursorPos %d, %d; ", newX, newY);
	for (int i=0;i<256;i++) {
		if (new_kbd_data[i]!=old_kbd_data[i]) printf("ASCII '%c' HEX 0x%02d key pressed; ", i, i);
	};
	//if (asdasdf!=qwerty) printf("\n");
}

// Main loop
DWORD WINAPI MainLoop(LPVOID lpParam)
{
	while (1)
	{
		NullState();KeyboardState();MouseState();PrintStuff();
	};
}

// Here we go
int main()
{
		printf("KamstRec v1.0. by Ivan Movchan\nhttps://nobootrecord.github.io\n\n");
		CreateThread(0, 0, MainLoop, 0, 0, 0);
		Sleep(-1);
}