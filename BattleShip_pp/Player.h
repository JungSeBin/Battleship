#pragma once
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Map.h"

#define MAP_SIZE 8
#define MAX_SHIP 256

enum Diretion{
	WIDTH,
	LENGTH
};

class Player
{
public:
	Player();
	~Player();

	void SetupShips();
	void PrintShips();
	Position Attack();
	Map GetMap(){ return m_Map; }
	Map Defend();
	Ship* GetShip(int i){ return m_Ship[i]; }
	int GetShipNum(){ return _countof(m_Ship); }

private:
	void RandShips(int MaxSize);
	Ship*		m_Ship[MAX_SHIP];
	Aircraft	m_Aircraft;
	Battleship	m_Battleship;
	Cruiser		m_Cruiser;
	Destroyer	m_Destroyer[2];
	Map			m_Map;
	Diretion m_GenerateDir;
	char m_GenerateX, m_GenerateY;


};

