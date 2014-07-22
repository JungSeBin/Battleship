// BattleShip_pp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <time.h>
#include <iostream>
#include <string>
#pragma warning(disable:4996)

//enum enumresult { HIT , DESTROY, MISS };

void removeShip(std::string ship[], int type);
void printShip(std::string ship[], int size);
int isShipEmpty(std::string ship[], int size);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	std::string ship[] = { "Aircraft", "Battleship","Battleship2", "Cruiser", "Destroyer1", "Destroyer2" };
	std::string result[] = { "HIT", "DESTROY", "MISS" };

	char x;
	char y;

	int random_result = rand() % _countof(result);
	int type = rand() % _countof(ship);

	while (!isShipEmpty(ship,_countof(ship)))
	{
		random_result = rand() % _countof(result);
		do{
			type = rand() % _countof(ship);








		} while (ship[type] == "");

		printf("x좌표:");
		getche();
		printf("\n");
		printf("y좌표:");
		getche();
		printf("\n");

		printf("%s\n", result[random_result].c_str());
		if (random_result == 1)
			removeShip(ship, type);
		printShip(ship, _countof(ship));
	}
	printf("Game Over");
	getchar();
	return 0;
}

void removeShip(std::string ship[],int type)
{
	printf("\n*****%s가 격추되었습니다.*****\n\n", ship[type].c_str());
	ship[type] = "";
}

void printShip(std::string ship[], int size)
{
	printf("현재남은 배: ");
	printf("[");
	for (int i = 0; i < size; i++)
	{
		if (ship[i] != "")
			printf("%s  ", ship[i].c_str());
	}
	printf("\b\b");
	printf("]\n");

}

int isShipEmpty(std::string ship[],int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!ship[i].empty())
			return 0;
	}
	return 1;
}