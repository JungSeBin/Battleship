#include "stdafx.h"
#include "Player.h"
#pragma warning(disable:4996)


Player::Player()
:m_PlayerHp(0), m_Board(nullptr), m_Name()
{
	m_ShipList.push_back(new Aircraft());
	m_ShipList.push_back(new Battleship());
	m_ShipList.push_back(new Cruiser());
	m_ShipList.push_back(new Destroyer());
	m_ShipList.push_back(new Destroyer());
	m_Board = new Board;
};


Player::~Player()
{
	for (auto itor = m_ShipList.begin(); itor != m_ShipList.end();)
	{
		SafeDelete(*itor);
		itor = m_ShipList.erase(itor);
	}
	m_ShipList.clear();
	SafeDelete(m_Board);
}

DirPosition Player::RandomShipPos()
{
	DirPosition generatePos;
	generatePos.pos.x = rand() % BOARD_COL + '1';
	generatePos.pos.y = rand() % BOARD_ROW + 'a';
	generatePos.dir = rand() % 2 ? HORIZON : VERTICAL;

	return generatePos;
}

void Player::SetupShip(DirPosition generatePos, int shipNum)
{ 
	assert(generatePos.dir != NONEDIR ); // 배의 배치시작좌표가 방향이 없으면 중지
	assert(shipNum >= 0 && shipNum < TOTAL_COUNT); // shipNum이 0보다 작거나 배의 개수보다 많으면 중지

	for (int i = 0; i < m_ShipList[shipNum]->GetMaxHp(); ++i)
	{
		m_ShipList[shipNum]->AddPosition(generatePos.pos);
		m_Board->SetPosMapType(generatePos.pos, m_ShipList[shipNum]->GetShipType());
		m_Board->SetPosMapStatus(generatePos.pos, NONE);
		if (generatePos.dir == VERTICAL)
		{
			generatePos.pos.y++;
		}
		else if (generatePos.dir == HORIZON)
		{
			generatePos.pos.x++;
		}
	}
}

HitResult Player::HitCheck(Position pos)
{
	if (m_Board->GetPosMapType(pos) == SHIP_NONE)
	{
		m_Board->SetPosMapStatus(pos, MISS);
		return MISS;
	}
	else
	{
		m_PlayerHp--;
		for (auto& ship : m_ShipList)
		{
			switch (ship->HitCheck(pos))
			{
			case HIT:
				m_Board->SetPosMapStatus(pos, HIT);
				return HIT;
			case DESTROY:
				for (int i = 0; i < ship->GetMaxHp(); ++i)
				{
					m_Board->SetPosMapStatus(ship->GetPos(i), DESTROY);
				}
				switch (ship->GetShipType())
				{
				case AIRCRAFT:
					return AIRCRAFT_DESTROY;
				case BATTLESHIP:
					return BATTLESHIP_DESTROY;
				case CRUISER:
					return CRUISER_DESTROY;
				case DESTROYER:
					return DESTROYER_DESTROY;
				}
			}
		}
		return NONE;
	}
}

Position Player::SelectAttack()
{
	Position pos;
	std::string xBuffer;
	pos.y = getche();
	// 엔터 입력시 오류처리
	if (pos.y == ENTER)
	{
		pos.y = ' ';
		pos.x = ' ';
		return pos;
	}

	pos.x = getche();
	//...
	if (pos.x == ENTER)
		pos.x = ' ';
	return pos;
}

Position Player::RandomAttack()
{
	Position pos;
	pos.x = rand() % BOARD_ROW + '1';
	pos.y = rand() % BOARD_ROW + 'a';
	return pos;
}

void Player::ResetShipInfo()
{
	for (auto ship : m_ShipList)
	{
		ship->ResetPos();
		ship->ResetNowHp();
	}
}

void Player::ResetBoard()
{
	m_Board->ResetBoard();
}

Position Player::UserSetShipPos()
{
	Position generatePos;
	generatePos.y = getche();
	generatePos.x = getche();
	return generatePos;
}

void Player::ResetPlayerHp()
{
	m_PlayerHp = 0;
	for (auto ship : m_ShipList)
	{
		m_PlayerHp += ship->GetMaxHp();
	}
}

Ships* Player::GetShip(int i)
{
	assert(i >= 0 && i < TOTAL_COUNT); //index값이 0보다 작거나 배의 개수보다 크면 중지

	return m_ShipList[i];
}

int Player::GetShipHp(int i)
{
	assert(i >= 0 && i < TOTAL_COUNT); // index값이 0보다 작거나 배의 개수보다 크면 중지

	return m_ShipList[i]->GetMaxHp();
}
