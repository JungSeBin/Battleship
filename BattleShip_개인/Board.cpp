#include "stdafx.h"
#include "Board.h"


Board::Board()
{
	ResetBoard();
}


Board::~Board()
{
}

void Board::SetPosMapType(Position pos, ShipType type)
{
	Position stablePos = ReturnPosAtoi(pos);
	m_Board[stablePos.y][stablePos.x].shipType = type;
}

void Board::SetPosMapStatus(Position pos, HitResult stat)
{
	Position stablePos = ReturnPosAtoi(pos);
	m_Board[stablePos.y][stablePos.x].status = stat;
}

ShipType Board::GetPosMapType(Position pos)
{
	Position stablePos = ReturnPosAtoi(pos);
	return m_Board[stablePos.y][stablePos.x].shipType;
}

HitResult Board::GetPosMapStatus(Position pos)
{
	Position stablePos = ReturnPosAtoi(pos);
	return m_Board[stablePos.y][stablePos.x].status;
}

Position Board::ReturnPosAtoi(Position pos)
{
	// ¸ÊÀ» ¹þ¾î³ª´Â ÁÂÇ¥ÀÌ¸é assert·Î ÁßÁö
	assert((IsValidPos(pos)));

	pos.x -= '1';
	pos.y -= 'a';
	return pos;
}

bool Board::IsValidPos(Position pos)
{
	return (pos.x < '1' + BOARD_COL && pos.x >= '1'
		&& pos.y < 'a' + BOARD_ROW && pos.y >= 'a');
}

void Board::ResetBoard()
{
	for (int row = 0; row < BOARD_COL; ++row)
	{
		for (int col = 0; col < BOARD_ROW; ++col)
		{
			m_Board[row][col].shipType = SHIP_NONE;
			m_Board[row][col].status = NONE;
		}
	}
}


