#include "stdafx.h"
#include "UI.h"


UI::UI()
{
	ResetCursorPos();
}


UI::~UI()
{
}

void UI::Gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void UI::SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void UI::ResetCursorPos()
{
	m_CursorPos.x = 0;
	m_CursorPos.y = NULL;
}
