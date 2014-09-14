#pragma once

#define MAX_SIZE 5

struct Position{
	char x;
	char y;
};

enum ShipType
{
	SHIP_NONE,
	SHIPTYPE_NONE,
	DESTROYER,
	CRUISER,
	BATTLESHIP,
	AIRCRAFT,
};

enum HitStatus
{
	MISS,
	HIT,
	AIRCRAFT_DESTROY,
	BATTLESHIP_DESTROY,
	CRUISER_DESTROY,
	DESTROYER_DESTROY,
};

class Ship
{
public:
	Ship();
	~Ship();

public:
	void AddPosition(Position pos);
	void AddPosition(char x, char y);
	void PrintHp();
	void PrintPos();
	int GetHP(){ return m_Hp; }
	HitStatus HitCheck(Position pos);

protected:
	int m_Hp;
	Position m_Pos[MAX_SIZE];
	ShipType m_Type;
	std::string m_Name;
};

