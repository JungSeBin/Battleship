#pragma once
class Player
{
public:
	Player();
	~Player();
public:
	void StateUpdate();
	int hp;
	Map myMap;
	Map enemyMap;
};

