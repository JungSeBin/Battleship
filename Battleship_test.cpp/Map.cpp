#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	memset(m_MapPos, 0, sizeof(m_MapPos));
}


Map::~Map()
{
}


void Map::SetPos(char x, char y)
{
	m_MapPos[x - 'A'][y - '1'] = 1;
	return;
}

bool Map::ShipCheck(char x, char y)
{
	if (m_MapPos[x - 'A'][y - '1'] == 1)
		return true;
	return false;
}