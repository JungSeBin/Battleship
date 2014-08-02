#pragma once
class GameManager
{
public:
	GameManager();
	~GameManager();
public:
	void ReadMap(Map _myMap, Map _enemyMap);
	bool IsGameEnd(bool _Turn);
	int HitCheck(int _X,int _Y);
	bool Turn();
	void InitGame();
};

