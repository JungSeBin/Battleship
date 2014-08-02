#pragma once
class Map
{
public:
	Map();
	~Map();
	void SetPos(char x, char y);
	bool ShipCheck(char x, char y);

//private:
	int m_MapPos[8][8];
};

