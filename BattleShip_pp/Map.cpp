#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	int* mymaps[8] = { 0, };
	Aircraft aircraft = Aircraft();
	Battleship battleship = Battleship();
	Cruiser cruiser = Cruiser();
	Destroyer destroyer1 = Destroyer();
	Destroyer destroyer2 = Destroyer();
	Submarine submarine1 = Submarine();
	Submarine submarine2 = Submarine();
	Map:: mapSet(aircraft, battleship, cruiser, destroyer1, destroyer2, submarine1, submarine2, mymaps);
}


Map::~Map()
{
}

void mapSet(Aircraft _aircraft, Battleship _battleship, Cruiser _cruiser, Destroyer _destroyer1,
	Destroyer _destroyer2, Submarine _submarine1, Submarine _submarine2, int* maps[])
{
	int i;
	
	if (_aircraft.isHorizontal == true)
	{
		for (i = 0; i < 5;i++)
		{
			maps[_aircraft.headPositionX][_aircraft.headPositionY] = 1;
			_aircraft.headPositionX++;
		}
		for (i = 0; i < 4; i++)
		{
			maps[_battleship.headPositionX][_battleship.headPositionY] = 2;
			_battleship.headPositionX++;
		}
		for (i = 0; i < 3; i++)
		{
			maps[_cruiser.headPositionX][_cruiser.headPositionY] = 3;
			_cruiser.headPositionX++;
		}
		for (i = 0; i < 2; i++)
		{
			maps[_destroyer1.headPositionX][_destroyer1.headPositionY] = 4;
			_destroyer1.headPositionX++;
		}
		for (i = 0; i < 2; i++)
		{
			maps[_destroyer2.headPositionX][_destroyer2.headPositionY] = 4;
			_destroyer2.headPositionX++;
		}
	}
	else
	{
		for (i = 0; i < 5;i++)
		{
			maps[_aircraft.headPositionX][_aircraft.headPositionY] = 1;
			_aircraft.headPositionY++;
		}
		for (i = 0; i < 4; i++)
		{
			maps[_battleship.headPositionX][_battleship.headPositionY] = 2;
			_battleship.headPositionY++;
		}
		for (i = 0; i < 3; i++)
		{
			maps[_cruiser.headPositionX][_cruiser.headPositionY] = 3;
			_cruiser.headPositionY++;
		}
		for (i = 0; i < 2; i++)
		{
			maps[_destroyer1.headPositionX][_destroyer1.headPositionY] = 4;
			_destroyer1.headPositionY++;
		}
		for (i = 0; i < 2; i++)
		{
			maps[_destroyer2.headPositionX][_destroyer2.headPositionY] = 4;
			_destroyer2.headPositionY++;
		}
	}
	maps[_submarine1.headPositionX][_submarine1.headPositionY] = 5;
	maps[_submarine2.headPositionX][_submarine2.headPositionY] = 5;
}
void printMap(int* maps[])
{
	int i, j;
	
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (maps[i][j] == 1)
				printf("A\t");
			else if (maps[i][j] == 2)
				printf("B\t");
			else if (maps[i][j] == 3)
				printf("C\t");
			else if (maps[i][j] == 4)
				printf("D\t");
			else if (maps[i][j] == 5)
				printf("S\t");
			else
				printf(" \t");
		}
		printf("\n");
	}
}