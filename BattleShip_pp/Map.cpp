#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	memset(m_MapPos, NONE, sizeof(m_MapPos));
}


Map::~Map()
{
}


void Map::SetPosValue(char x, char y,MapState value)
{
	m_MapPos[x - 'A'][y - '1'] = value;
	return;
}

MapState Map::GetPosValue(char x, char y)
{
	if (x <= 'A' || x >= 'H' || y >= '8' || y <= '1')
		return INVALID_INPUT;
	return m_MapPos[x - 'A'][y - '1'];
}