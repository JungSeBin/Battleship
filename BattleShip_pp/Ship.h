#pragma once
class Ship
{
public:
	Ship();
	~Ship();

public:
	int getHp();
	void SetHp(int num);
	bool GiveDamage();

private:
	int hp;
	bool isHorizontal;
	int headPositionX;
	int headPositionY;
};

