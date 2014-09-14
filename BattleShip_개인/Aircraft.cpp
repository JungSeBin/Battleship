#include "stdafx.h"
#include "Aircraft.h"


Aircraft::Aircraft()
{
	m_Type = AIRCRAFT;
	m_MaxHp = 5;
	m_NowHp = m_MaxHp;
	m_Name = "Aircraft";
}


Aircraft::~Aircraft()
{
}
