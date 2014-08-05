#include "stdafx.h"
#include "Player.h"
#include <time.h>


Player::Player()
{
}


Player::~Player()
{
}

int horizon;
char x, y;

void Player::SetupShips()
{

	// ������ �ִ� ����� ��ǥ�� ���� ��ġ�Ѵ�
	int A_MaxSize = m_Aircraft.getHP();
	int B_MaxSize = m_Battleship.getHP();
	int C_MaxSize = m_Cruiser.getHP();
	int D_MaxSize = m_Destroyer[0].getHP();
	
	RandShips(A_MaxSize); //Aircraft ���� ��ǥ ����
	for (int i = 0; i < A_MaxSize; i++)
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
	RandShips(B_MaxSize); //Battleship ���� ��ǥ ����
	for (int i = 0; i < B_MaxSize; i++)
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
	RandShips(C_MaxSize); //Cruiser ���� ��ǥ ����
	for (int i = 0; i < C_MaxSize; i++)
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

	RandShips(D_MaxSize); //Destroyer1 ���� ��ǥ ����
	for (int i = 0; i < D_MaxSize; i++)
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

	RandShips(D_MaxSize); //Destroyer2 ���� ��ǥ ����
	for (int i = 0; i < D_MaxSize; i++)
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

void Player::RandShips(int MaxSize)
{
	//����� ��ǥ�� �����ϰ� �����Ѵ�.
	srand((unsigned int)time(NULL));
	bool checker = true;
	int x_buffer, y_buffer;

	while (checker)
	{
		x = rand() % 8 + 'A';
		y = rand() % 8 + '1';
		horizon = rand() % 2 ? true : false; //���θ� true ���θ� false
		//for���� ���� buffer
		x_buffer = x + MaxSize;
		y_buffer = y + MaxSize;

		if (horizon)
		{
			if (x_buffer <= 'H')
			{
				for (; x < x_buffer; x++)
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
			x = x - MaxSize;
		}
		else
		{
			if (y_buffer <= '8')
			{
				for (; y < y_buffer; y++)
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
			y = y - MaxSize;
		}
	}


}