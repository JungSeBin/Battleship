#pragma once
#include "Player.h"
#include "GameBoardUI.h"
#include "GameMenuUI.h"
#include "GameMessageUI.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

public:
	void		GameStart();

private:
	void		GameInit();
	void		GameReset();
	void		SetPlayerByGameMode();
	void		GameLoop();
	void		UpdateBoard(Player* player);
	void		PrintBoardShips();
	void		PrintBoardFrame();
	bool		GameIsOver();
	void		SetupShips(Player* player, Board* board);
	bool		InvalidSetPosCheck(Board* board, int shipHp, DirPosition generatePos, std::string shipName);
	bool		InValidAttackPosCheck(Position pos, Board* board, int x, int y);
	void		PrintEndMenu();
	Direction	SelectDirection();
	void		GameTurn(Player* attackPlayer, Player* defendPlayer, Board* defendBoard, std::string playerName, int x, int y);
		
	Player*			m_Player1;
	Player*			m_Player2;
	GameBoardUI*	m_BoardUI;
	GameMenuUI*		m_MenuUI;
	GameMessageUI*	m_MessageUI;
	GameMode		m_GameMode;
	DeadType		m_DeadType;
	GameStatus		m_GameStatus;
	int				m_GameTurnNum;
	int				m_GamePlayNum;
	int				m_GameTurnSum;
};

