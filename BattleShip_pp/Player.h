#pragma once
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Map.h"

#define MAP_SIZE 8

static bool horizon;
static char x, y;

class Player
{
public:
	Player();
	~Player();

	void SetupShips();
	void PrintShips();
	void RandShips(int MaxSize);
	Position Attack();
	Map GetMap(){ return m_Map; }
	Map Defend();
	Ship* GetShip(int i){ return m_Ship[i]; }

private:
	Ship*		m_Ship[5];
	Aircraft	m_Aircraft;
	Battleship	m_Battleship;
	Cruiser		m_Cruiser;
	Destroyer	m_Destroyer[2];
	Map			m_Map;


};

