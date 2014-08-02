#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{
	m_Hp = 0;
	memset(m_Pos, -1, sizeof(Position)* MAX_SIZE);
	m_Type = SHIPTYPE_NONE;
	m_Name.clear();
}


Ship::~Ship()
{
}

void Ship::AddPosition(Position pos)
{
	for (int i = 0; i < m_Hp; i++)
	{
		if (m_Pos[i].x == -1 && m_Pos[i].y == -1)
		{
			m_Pos[i] = pos;
			break;
		}
	}
}

void Ship::AddPosition(char x, char y)
{
	Position Pos;
	Pos.x = x;
	Pos.y = y;
	AddPosition(Pos);

}

void Ship::PrintHp()
{
	printf_s("HP of %s is %d\n", m_Name.c_str(), m_Hp);
}

HitStatus Ship::HitCheck(Position pos)
{
	HitStatus returnStatus = MISS;

	for (int i = 0; i < m_Hp; i++)
	{
		if (m_Pos[i].x == pos.x&&m_Pos[i].y == pos.y)
		{
			returnStatus = HIT;
			--m_Hp;
			break;
		}
	}
	if (m_Hp == 0)
	{
		switch (m_Type)
		{
		case AIRCRAFT :
			returnStatus = AIRCRAFT_DESTROY;
			break;
		case BATTLESHIP:
			returnStatus = BATTLESHIP_DESTROY;
			break;
		case CRUISER:
			returnStatus = CRUISER_DESTROY;
			break;
		case DESTROYER:
			returnStatus = DESTROYER_DESTROY;
			break;
		default:
			break;
		}
	}
	return returnStatus;
}

void Ship::PrintPos()
{
	printf_s("%s : ", m_Name.c_str());
	for (int i = 0; i < m_Hp; i++)
	{
		printf_s("%c%c ", m_Pos[i].x, m_Pos[i].y);
	}
	printf_s("\n");
}
