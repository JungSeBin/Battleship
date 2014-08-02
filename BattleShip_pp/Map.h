#pragma once
class Map
{
public:
	Map();
	~Map();
public:
	void PrintMap();
	void MapSet(Aircraft _aircraft, Battleship _battleship, Cruiser _cruiser, Destroyer _destroyer1, 
		Destroyer _destroyer2, Submarine _submarine1, Submarine _submarine2, int* maps[]);
protected:
	Aircraft aircraft;
	Battleship battleship;
	Cruiser cruiser;
	Destroyer destroyer1;
	Destroyer destroyer2;
	Submarine submarine1;
	Submarine submarine2;

};

