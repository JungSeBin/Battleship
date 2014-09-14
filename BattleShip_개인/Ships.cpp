#include "stdafx.h"
#include "Ships.h"


Ships::Ships()
:m_MaxHp(0), m_NowHp(0), m_Type(SHIP_NONE), m_Name()
{
	ResetPos();
}


Ships::~Ships()
{
}

HitResult Ships::HitCheck(Position pos)
{
	//Board를 벗어나는 좌표면 중지
	assert(pos.y < 'a' + BOARD_ROW && pos.y >= 'a'
		&& pos.x < '1' + BOARD_COL && pos.x >= '1');

	HitResult hitResult = MISS;

	for (int i = 0; i < GetMaxHp(); ++i)
	{
		if (m_Pos[i].y == pos.y && m_Pos[i].x == pos.x)
		{
			--m_NowHp;
			if (m_NowHp == 0)
			{
				hitResult = DESTROY;
				break;
			}
			hitResult = HIT;
		}
	}
	return hitResult;
}

void Ships::AddPosition(Position pos)
{
	//Board를 벗어나는 좌표면 중지
	assert(pos.y < 'a' + BOARD_ROW && pos.y >= 'a'
		&& pos.x < '1' + BOARD_COL && pos.x >= '1');

	for (int i = 0; i < GetMaxHp(); ++i)
	{
		if (m_Pos[i].y == 0 && m_Pos[i].x == 0)
		{
			m_Pos[i].y = pos.y;
			m_Pos[i].x = pos.x;
			break;
		}
	}
}

void Ships::AddPosition(char x, char y)
{
	//Board를 벗어나는 좌표면 중지
	assert(y < 'a' + BOARD_ROW && y >= 'a'
		&& x < '1' + BOARD_COL && x >= '1');

	Position pos;
	pos.x = x;
	pos.y = y;
	AddPosition(pos);
}

Position Ships::GetPos(int i)
{
	assert(i >= 0 && i < POS_MAX_SIZE); // index값이 0보다 작거나 MAX_SIZE보다 크면 중지

	return m_Pos[i];
}
