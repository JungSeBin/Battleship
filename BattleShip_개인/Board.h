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
	ShipType	GetPosMapType(Position pos);
	HitResult	GetPosMapStatus(Position pos);

private:
	bool		IsValidPos(Position pos);
	Position	ReturnPosAtoi(Position pos);

	Status_Board m_Board[BOARD_ROW][BOARD_COL];
};

