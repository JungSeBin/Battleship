#pragma once

struct Position{
	int x;
	char y;
};

struct Status_Board{
	ShipType shipType;
	HitResult status;
};

struct DirPosition{
	Position pos;
	Direction dir;
};