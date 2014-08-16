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

	// ������ �ִ� ����� ��ǥ�� ���� ��ġ�Ѵ�
	int A_Hp = m_Aircraft.getHP();
	int B_Hp = m_Battleship.getHP();
	int C_Hp = m_Cruiser.getHP();
	int D_Hp = m_Destroyer[0].getHP();
	
	RandShips(A_Hp); //Aircraft ���� ��ǥ ����
	for (int i = 0; i < A_Hp; ++i)
	{
		m_Aircraft.AddPosition(x, y);
		m_Map.SetPos(x, y);
		if (horizon)
		{
			x++;
		}
		else
		{
			y++;
		}
	}
	RandShips(B_Hp); //Battleship ���� ��ǥ ����
	for (int i = 0; i < B_Hp; ++i)
	{
		m_Battleship.AddPosition(x, y);
		m_Map.SetPos(x, y);
		if (horizon)
		{
			x++;
		}
		else
		{
			y++;
		}
	}
	RandShips(C_Hp); //Cruiser ���� ��ǥ ����
	for (int i = 0; i < C_Hp; ++i)
	{
		m_Cruiser.AddPosition(x, y);
		m_Map.SetPos(x, y);
		if (horizon)
		{
			x++;
		}
		else
		{
			y++;
		}
	}

	RandShips(D_Hp); //Destroyer1 ���� ��ǥ ����
	for (int i = 0; i < D_Hp; ++i)
	{
		m_Destroyer[0].AddPosition(x, y);
		m_Map.SetPos(x, y);
		if (horizon)
		{
			x++;
		}
		else
		{
			y++;
		}
	}

	RandShips(D_Hp); //Destroyer2 ���� ��ǥ ����
	for (int i = 0; i < D_Hp; ++i)
	{
		m_Destroyer[1].AddPosition(x, y);
		m_Map.SetPos(x, y);
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
//��� ����� ��ǥ�� ���
{
	m_Aircraft.PrintPos();
	m_Battleship.PrintPos();
	m_Cruiser.PrintPos();
	m_Destroyer[0].PrintPos();
	m_Destroyer[1].PrintPos();
}

void Player::RandShips(int Ship_Hp)
{
	//����� ��ǥ�� �����ϰ� �����Ѵ�.
	srand((unsigned int)time(NULL));
	bool checker = true;
	int x_buffer, y_buffer;

	while (checker)
	{
		x = rand() % MAP_SIZE + 'A';
		y = rand() % MAP_SIZE + '1';
		horizon = rand() % 2 ? true : false; //���θ� true ���θ� false
		//for���� ���� buffer
		x_buffer = x + Ship_Hp;
		y_buffer = y + Ship_Hp;

		if (horizon)
		{
			if (x_buffer <= 'H')
			{
				for (; x < x_buffer; ++x)
				{
					if (m_Map.ShipCheck(x, y))
					{
						checker = true;
						break;
					}
					else
						checker = false;
				}
			}
			x = x - Ship_Hp;
		}
		else
		{
			if (y_buffer <= '8')
			{
				for (; y < y_buffer; ++y)
				{
					if (m_Map.ShipCheck(x, y))
					{
						checker = true;
						break;
					}
					else
						checker = false;
				}
			}
			y = y - Ship_Hp;
		}
	}


}

Position Player::Attack()
{
	Position attackPos;

	printf_s("������ ��ǥ ����:");
	attackPos.x = getche();
	attackPos.y = getche();
	printf_s("\n");

	return attackPos;

	//if (hit == AIRCRAFT_DESTROY)
	//	printf_s("Aircraft Destroy");
	//else if (hit == BATTLESHIP_DESTROY)
	//	printf_s("Battleship Destroy");
	//else if (hit == CRUISER_DESTROY)
	//	printf_s("Cruiser Destroy");
	//else if (hit == DESTROYER_DESTROY)
	//	printf_s("Destroyer Destroy");
	//else if (hit == HIT)
	//	printf_s("Hit");
	//else
	//	printf_s("Miss");
}

Map Player::Defend()
{
	return GetMap();
}
