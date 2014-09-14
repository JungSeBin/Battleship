#include "stdafx.h"
#include "Destroyer.h"


Destroyer::Destroyer()
{
	m_Type = DESTROYER;
	m_MaxHp = 2;
	m_NowHp = m_MaxHp;
	m_Name = "Destroyer";
}


Destroyer::~Destroyer()
{
}
