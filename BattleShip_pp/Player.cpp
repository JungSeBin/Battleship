#include "stdafx.h"
#include "Player.h"
#include <conio.h>
#include <time.h>

#pragma warning(disable:4996)


Player::Player()
{
	m_Ship[0] = &m_Aircraft;
	m_Ship[1] = &m_Battleship;
	m_Ship[2] = &m_Cruiser;
	m_Ship[3] = &m_Destroyer[0];
	m_Ship[4] = &m_Destroyer[1];
}


Player::~Player()
{
}



void Player::SetupShips()
{

	// 가지고 있는 배들을 좌표를 토대로 배치한다

	for (int ship_idx = 0; ship_idx < GetShipNum(); ship_idx++)
	{
		int hp = m_Ship[ship_idx]->GetHP();
		RandShips(hp); // 랜덤 좌표 설정
		for (int i = 0; i < hp; ++i)
		{
			m_Ship[ship_idx]->AddPosition(m_GenerateX, m_GenerateY);
			m_Map.SetPosValue(m_GenerateX, m_GenerateY, SHIP);
			if (m_GenerateDir)
			{
				m_GenerateX++;
			}
			else
			{
				m_GenerateY++;
			}
		}
	}
}

void Player::PrintShips()
//모든 배들의 좌표를 출력
{
	for (int i = 0; i < GetShipNum(); i++)
	{
		m_Ship[i]->PrintPos();
	}
}

void Player::RandShips(int Ship_Hp)
{
	//배들의 시작 좌표를 랜덤하게 설정한다.
	bool checker = true;
	int x_buffer, y_buffer;

	while (checker)
	{
		m_GenerateX = rand() % MAP_SIZE + 'A';
		m_GenerateY = rand() % MAP_SIZE + '1';
		m_GenerateDir = rand() % 2 ? true : false; //가로면 true 세로면 false
		//for문을 위한 buffer
		x_buffer = m_GenerateX + Ship_Hp;
		y_buffer = m_GenerateY + Ship_Hp;

		if (m_GenerateDir)
		{
			if (x_buffer <= 'H')
			{
				for (; m_GenerateX < x_buffer; ++m_GenerateX)
				{
					if (m_Map.GetPosValue(m_GenerateX, m_GenerateY))
					{
						checker = true;
						break;
					}
					else
						checker = false;
				}
			}
			m_GenerateX = m_GenerateX - Ship_Hp;
		}
		else
		{
			if (y_buffer <= '8')
			{
				for (; m_GenerateY < y_buffer; ++m_GenerateY)
				{
					if (m_Map.GetPosValue(m_GenerateX, m_GenerateY))
					{
						checker = true;
						break;
					}
					else
						checker = false;
				}
			}
			m_GenerateY = m_GenerateY - Ship_Hp;
		}
	}


}

Position Player::Attack()
{
	Position attackPos;

	printf_s("공격할 좌표 설정:");
	attackPos.x = getche();
	attackPos.y = getche();
	printf_s("\n");

	return attackPos;

}

Map Player::Defend()
{
	return GetMap();
}
