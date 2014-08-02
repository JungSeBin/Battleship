#include "stdafx.h"
#include "Player.h"
#include <time.h>


Player::Player()
{
}


Player::~Player()
{
}

void Player::SetupShips()
{

	// 가지고 있는 배들을 배치한다
	srand((unsigned int)time(NULL));
	int MaxSize = m_Aircraft.getHP();
	bool checker = true;
	int horizon;
	char x, y;

	while (checker)
	{
		x = rand() % 8 + 'A';
		y = rand() % 8 + '1';
		horizon = rand() % 2 ? true : false;

		if (horizon)
		{
			if (x + MaxSize <= 'H')
			{
				for (; x < x + MaxSize; x++)
				{
					if (m_Map.ShipCheck(x, y))
						break;
					else
						checker = false;
				}
			}
		}
		else
		{
			if (y + MaxSize <= '8')
			{
				for (; y < y + MaxSize; y++)
				{
					if (m_Map.ShipCheck(x, y))
						break;
					else
						checker = false;
				}
			}
		}
	}

	for (int i = 0; i < MaxSize; i++)
	{
		m_Aircraft.AddPosition(x, y);
		m_Map.SetPos(x,y);
		if (horizon)
		{
			x++;
		}
		else
		{
			y++;
		}
	}


}

void Player::PrintShips()
{
	m_Aircraft.PrintPos();
	m_Battleship.PrintPos();
	m_Cruiser.PrintPos();
	m_Destroyer[0].PrintPos();
	m_Destroyer[1].PrintPos();
}
