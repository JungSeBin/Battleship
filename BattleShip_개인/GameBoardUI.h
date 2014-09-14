#pragma once
#include "Board.h"
#include "UI.h"

class GameBoardUI:
	public UI
{
public:
	GameBoardUI();
	~GameBoardUI();

public:
	void	ChangeConsoleSize(HANDLE, int x,int y);
	void	SetBoard(Board* board){ m_Board = *board; }
	void	PrintBoardFrame(int x, int y, std::string playerName);
	void	PrintBoardStatus(int x, int y);
	void	PrintBoardShips(int x, int y);
	void	ResetBoard();

private:
	Board m_Board;
};

