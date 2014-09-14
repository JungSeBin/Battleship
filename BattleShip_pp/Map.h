#pragma once

enum MapState{ NONE, SHIP, CHECKED, INVALID_INPUT };

class Map
{
public:
	Map();
	~Map();

public:
	void SetPosValue(char x, char y, MapState value);
	MapState GetPosValue(char x, char y);

private:
	MapState m_MapPos[8][8];
};

