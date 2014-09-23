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
	//Board�� ����� ��ǥ�� ����
	assert(pos.y < 'a' + BOARD_ROW && pos.y >= 'a'
		&& pos.x < '1' + BOARD_COL && pos.x >= '1');

	//Release ��忡�� ���� ����� ��ǥ�̸� (a,1)���� �ʱ�ȭ
	if (pos.y >= 'a' + BOARD_ROW || pos.y < 'a'
		|| pos.x >= 'a' + BOARD_COL || pos.x < '1')
	{
		pos.y = 'a';
		pos.y = '1';
	}

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
	//Board�� ����� ��ǥ�� ����
	assert(pos.y < 'a' + BOARD_ROW && pos.y >= 'a'
		&& pos.x < '1' + BOARD_COL && pos.x >= '1');

	//Release ��忡�� ���� ����� ��ǥ�̸� (a,1)���� �ʱ�ȭ
	if (pos.y >= 'a' + BOARD_ROW || pos.y < 'a'
		|| pos.x >= 'a' + BOARD_COL || pos.x < '1')
	{
		pos.y = 'a';
		pos.y = '1';
	}

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
	//Board�� ����� ��ǥ�� ����
	assert(y < 'a' + BOARD_ROW && y >= 'a'
		&& x < '1' + BOARD_COL && x >= '1');

	//Release ��忡�� ���� ����� ��ǥ�̸� (a,1)���� �ʱ�ȭ
	if (y >= 'a' + BOARD_ROW || y < 'a'
		|| x >= 'a' + BOARD_COL || x < '1')
	{
		y = 'a';
		x = '1';
	}

	Position pos;
	pos.x = x;
	pos.y = y;
	AddPosition(pos);
}

Position Ships::GetPos(int i)
{
	assert(i >= 0 && i < POS_MAX_SIZE); // index���� 0���� �۰ų� MAX_SIZE���� ũ�� ����

	//Release ��忡�� index�� ������ ����� 0���� �ʱ�ȭ
	if (i < 0 || i > TOTAL_COUNT)
	{
		i = 0;
	}

	return m_Pos[i];
}

void Ships::ResetPos()
{
	memset(m_Pos, 0, sizeof(Position)* POS_MAX_SIZE);
}
