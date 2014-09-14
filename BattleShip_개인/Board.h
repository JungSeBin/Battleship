#pragma once
#include "Ships.h"


class Board
{
public:
	Board();
	~Board();

public:
	void		ResetBoard();
	void		SetPosMapType(Position pos, ShipType type);
	void		SetPosMapStatus(Position pos, HitResult stat);
	bool		IsValidPos(Position pos);
	Position	ReturnPosAtoi(Position pos);
	ShipType	GetPosMapType(Position pos);
	HitResult	GetPosMapStatus(Position pos);

private:
	Status_Board m_Board[BOARD_ROW][BOARD_COL];
};

