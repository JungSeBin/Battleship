// Battleship_test.cpp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Player.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Aircraft air;
	Battleship battleship;
	Cruiser cruiser;
	Destroyer destroyer;
	Player player;

	Position pos;
	pos.x = '1';
	pos.y = '2';
	air.AddPosition('1','2');

	air.PrintHp();
	battleship.PrintHp();
	cruiser.PrintHp();
	destroyer.PrintHp();

	air.HitCheck(pos);
	air.PrintHp();
	player.SetupShips();
	player.PrintShips();
	getchar();

	return 0;
}

