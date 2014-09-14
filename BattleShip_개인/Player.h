#pragma once


#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Board.h"



class Player
{
public:
	Player();
	~Player();

public:
	void			SetupShip(DirPosition generatePos, int shipNum);
	Ships*			GetShip(int i);
	Board*			GetBoard()								{ return m_Board; }
	void			ResetShipInfo();
	void			ResetBoard();
	void			ResetPlayerHp();
	int				GetPlayerHp()							{ return m_PlayerHp; }
	int				GetShipHp(int i);
	void			SetPlayerType(PlayerType playerType)	{ m_Type = playerType; }
	PlayerType		GetPlayerType()							{ return m_Type; }
	std::string		GetPlayerName()							{ return m_Name; }
	void			SetPlayerName(std::string playerName)	{ m_Name = playerName; }
	Position		UserSetShipPos();
	DirPosition		RandomShipPos();
	Position		SelectAttack();
	Position		RandomAttack();
	HitResult		HitCheck(Position pos);
private:
	bool InvalidSetPosCheck(int shipHp, DirPosition generatePos);

	std::vector<Ships*>	m_ShipList;
	Board*				m_Board;
	int					m_PlayerHp;
	PlayerType			m_Type;
	std::string			m_Name;

};

