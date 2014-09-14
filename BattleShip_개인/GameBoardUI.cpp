#include "stdafx.h"
#include "GameBoardUI.h"


GameBoardUI::GameBoardUI()
{
}


GameBoardUI::~GameBoardUI()
{
}

void GameBoardUI::ChangeConsoleSize(HANDLE hBuffer, int cx, int cy)
{
	enum EFlag
	{
		FlagNoChange,
		FlagWindowFirst,
		FlagScreenFirst
	};

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hBuffer, &csbi);
	csbi.srWindow.Right -= csbi.srWindow.Left;
	csbi.srWindow.Bottom -= csbi.srWindow.Top;
	SetConsoleWindowInfo(hBuffer, TRUE, &csbi.srWindow);

	COORD coordLargestSize = GetLargestConsoleWindowSize(hBuffer);
	COORD coordNewSize = { min(coordLargestSize.X, cx), min(coordLargestSize.Y, cy) };
	COORD coordWindowSize = { csbi.srWindow.Right + 1, csbi.srWindow.Bottom + 1 };
	SMALL_RECT srWindowRect = {};

	EFlag eFlag = FlagNoChange;
	if (coordWindowSize.Y > coordNewSize.Y)
	{
		if (coordWindowSize.X < coordNewSize.X)
		{
			SMALL_RECT srNewWindow = csbi.srWindow;
			srNewWindow.Bottom = coordNewSize.Y - 1;
			SetConsoleWindowInfo(hBuffer, TRUE, &srNewWindow);
			eFlag = FlagScreenFirst;
		}
		else
		{
			eFlag = FlagWindowFirst;
		}
	}
	else if (coordWindowSize.Y < coordNewSize.Y)
	{
		if (coordWindowSize.X > coordNewSize.X)
		{
			SMALL_RECT srNewWindow = csbi.srWindow;
			srNewWindow.Right = coordNewSize.X - 1;
			SetConsoleWindowInfo(hBuffer, TRUE, &srNewWindow);
		}
		eFlag = FlagScreenFirst;
	}
	else
	{
		if (coordWindowSize.X > coordNewSize.X)
		{
			eFlag = FlagWindowFirst;
		}
		else if (coordWindowSize.X < coordNewSize.X)
		{
			eFlag = FlagScreenFirst;
		}
	}

	if (eFlag != FlagNoChange)
	{
		srWindowRect.Right = coordNewSize.X - 1;
		srWindowRect.Bottom = coordNewSize.Y - 1;
		if (eFlag == FlagWindowFirst)
		{
			SetConsoleWindowInfo(hBuffer, TRUE, &srWindowRect);
			SetConsoleScreenBufferSize(hBuffer, coordNewSize);
		}
		else
		{
			SetConsoleScreenBufferSize(hBuffer, coordNewSize);
			SetConsoleWindowInfo(hBuffer, TRUE, &srWindowRect);
		}
	}
	
}

void GameBoardUI::PrintBoardFrame(int x, int y, std::string playerName)
{
	char cx = '1';
	char cy = 'a' + BOARD_ROW - 1;
	for (int i = 0; i <= BOARD_ROW; ++i)
	{
		for (int j = 0; j <= BOARD_COL; ++j)
		{
			if (i == 0 && j == 0)
			{
				Gotoxy(x, y);
				printf_s("旨收");
				Gotoxy(x - 1, y + 1);
				printf_s("%c", cy--);
			}
			else if (i == 0 && j == BOARD_COL)
			{
				Gotoxy(x + COL_INTERVAL * j, y);
				printf_s("旬");
				Gotoxy(x + COL_INTERVAL * j, y + 1);
				printf_s("早");
			}
			else if (i == BOARD_ROW && j == 0)
			{
				Gotoxy(x, y + ROW_INTERVAL * i - 1);
				printf_s("早");
				Gotoxy(x, y + ROW_INTERVAL * i);
				printf_s("曲");
			}
			else if (i == BOARD_ROW && j == BOARD_COL)
			{
				Gotoxy(x + COL_INTERVAL * j - 2, y + ROW_INTERVAL * i);
				printf_s("收旭");
				Gotoxy(x + COL_INTERVAL * j - 2, y + ROW_INTERVAL * i + 1);
				printf_s(" %c", cx);
			}
			else if (j == 0)
			{
				Gotoxy(x, y + ROW_INTERVAL * i - 1);
				printf_s("早");
				Gotoxy(x, y + ROW_INTERVAL * i);
				printf_s("曳收");
				Gotoxy(x - 1, y + ROW_INTERVAL * i + 1);
				printf_s("%c", cy--);
			}
			else if (i == 0)
			{
				Gotoxy(x + COL_INTERVAL * j, y);
				printf_s("有收");
			}
			else if (j == BOARD_COL)
			{
				Gotoxy(x + COL_INTERVAL * j, y + ROW_INTERVAL * i);
				printf_s("朽");
				Gotoxy(x + COL_INTERVAL * j, y + ROW_INTERVAL * i + 1);
				printf_s("早");
			}
			else if (i == BOARD_ROW)
			{
				Gotoxy(x + COL_INTERVAL * j, y + ROW_INTERVAL * i - 1);
				printf_s("早");
				Gotoxy(x + COL_INTERVAL * j - 2, y + ROW_INTERVAL * i);
				printf_s("收朴");
				Gotoxy(x + COL_INTERVAL * j - 2, y + ROW_INTERVAL * i + 1);
				printf_s(" %c", cx++);
			}
			else
			{
				Gotoxy(x + COL_INTERVAL * j, y + ROW_INTERVAL * i - 1);
				printf_s("早");
				Gotoxy(x + COL_INTERVAL * j, y + ROW_INTERVAL * i);
				printf_s("朱收");
			}
		}
	}
	Gotoxy(x + PLAYERNAME_X, y + PLAYERNAME_Y);
	printf_s("<%s>", playerName.c_str());
}

void GameBoardUI::ResetBoard()
{
	m_Board.ResetBoard();
}

void GameBoardUI::PrintBoardStatus(int x, int y)
{
	Position pos;
	for (int i = 0; i < BOARD_ROW; ++i)
	{
		for (int j = 0; j < BOARD_COL; ++j)
		{
			pos.y = BOARD_ROW - i + 'a' - 1;
			pos.x = j + '1';
			if (m_Board.GetPosMapStatus(pos) == MISS)
			{
				SetColor(WHITE);
				Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
				printf_s("炤");
			}
			else if (m_Board.GetPosMapStatus(pos) == HIT)
			{
				SetColor(PINK);
				Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
				printf_s("為");
				SetColor(WHITE);
			}
			if (m_Board.GetPosMapStatus(pos) == DESTROY)
			{
				switch (m_Board.GetPosMapType(pos))
				{
				case AIRCRAFT:
					SetColor(RED);
					Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
					printf_s("活");
					SetColor(WHITE);
					break;
				case BATTLESHIP:
					SetColor(BLUE);
					Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
					printf_s("派");
					SetColor(WHITE);
					break;
				case CRUISER:
					SetColor(YELLOW);
					Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
					printf_s("炯");
					SetColor(WHITE);
					break;
				case DESTROYER:
					SetColor(GREEN);
					Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
					printf_s("芍");
					SetColor(WHITE);
					break;
				}
			}
		}
	}
}

void GameBoardUI::PrintBoardShips(int x, int y)
{
	Position pos;
	for (int i = 0; i < BOARD_ROW; ++i)
	{
		for (int j = 0; j < BOARD_COL; ++j)
		{
			pos.y = BOARD_ROW - i + 'a' - 1;
			pos.x = j + '1';
			if (m_Board.GetPosMapStatus(pos) == MISS)
			{
				SetColor(WHITE);
				Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
				printf_s("炤");
			}
			switch (m_Board.GetPosMapType(pos))
			{
			case AIRCRAFT:
				SetColor(RED);
				if (m_Board.GetPosMapStatus(pos) != NONE)
					SetColor(GRAY);
				Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
				printf_s("活");
				SetColor(WHITE);
				break;
			case BATTLESHIP:
				SetColor(BLUE);
				if (m_Board.GetPosMapStatus(pos) != NONE)
					SetColor(GRAY);
				Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
				printf_s("派");
				SetColor(WHITE);
				break;
			case CRUISER:
				SetColor(YELLOW);
				if (m_Board.GetPosMapStatus(pos) != NONE)
					SetColor(GRAY);
				Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
				printf_s("炯");
				SetColor(WHITE);
				break;
			case DESTROYER:
				SetColor(GREEN);
				if (m_Board.GetPosMapStatus(pos) != NONE)
					SetColor(GRAY);
				Gotoxy(x + 2 + COL_INTERVAL * j, y + 1 + ROW_INTERVAL * i);
				printf_s("芍");
				SetColor(WHITE);
				break;
			}
		}
	}
}
