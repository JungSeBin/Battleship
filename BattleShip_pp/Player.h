#pragma once
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Map.h"

class Player
{
public:
	Player();
	~Player();

	void SetupShips();
	void PrintShips();
	void RandShips(int MaxSize);

private:
	Aircraft	m_Aircraft;
	Battleship	m_Battleship;
	Cruiser		m_Cruiser;
	Destroyer	m_Destroyer[2];
	Map			m_Map;


};

