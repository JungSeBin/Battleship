#include "stdafx.h"
#include "Battleship.h"


Battleship::Battleship()
{
	m_Type = BATTLESHIP;
	m_MaxHp = 4;
	m_NowHp = m_MaxHp;
	m_Name = "Battleship";
}


Battleship::~Battleship()
{
}
