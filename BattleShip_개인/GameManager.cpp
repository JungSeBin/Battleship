#include "stdafx.h"
#include "GameManager.h"


GameManager::GameManager()
:m_MenuUI(nullptr), m_BoardUI(nullptr), m_Player1(nullptr), m_Player2(nullptr),
m_MessageUI(nullptr), m_GamePlayNum(0), m_GameTurnNum(0), m_GameTurnSum(0), m_GameStatus(GAME_START)
{
	_ASSERTE(BOARD_ROW > 6 && BOARD_COL > 6 && "UI�������ϴ�.");
	m_BoardUI->ChangeConsoleSize(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_XSIZE, CONSOLE_YSIZE);
	srand((unsigned int)time(NULL));
	m_MenuUI =		new GameMenuUI();
	m_BoardUI =		new GameBoardUI();
	m_Player1 =		new Player();
	m_Player2 =		new Player();
	m_MessageUI =	new GameMessageUI();
}


GameManager::~GameManager()
{
	SafeDelete(m_MenuUI);
	SafeDelete(m_BoardUI);
	SafeDelete(m_Player1);
	SafeDelete(m_Player2);
	SafeDelete(m_MessageUI);
}

void GameManager::GameInit()
{
	GameReset();
	SetPlayerByGameMode();
	PrintBoardFrame();
	SetupShips(m_Player1, m_Player1->GetBoard());
	SetupShips(m_Player2, m_Player2->GetBoard());
}

void GameManager::GameStart()
{
	// ���ӻ��°� �����Ⱑ �ƴϸ� ���� �ٽ� ����
	while (m_GameStatus != GAME_END)
	{
		GameInit(); //���� ��� ������ ���� ���� ��� ����

		//������ ����ɶ����� ���� ���� ����
		while (!GameIsOver())
		{
			GameLoop();
		}
		m_GamePlayNum++; //���� �÷��� �� ����
		m_GameTurnSum += m_GameTurnNum;
		PrintBoardShips(); // ���� �� ����� ��ġ ���
		m_MessageUI->PrintGameNumMessage(m_GamePlayNum, m_GameTurnNum, m_GameTurnSum); //�÷��� Ƚ��, �ϼ�, ����ϼ� ���
		PrintEndMenu(); // ���� ����� ����
	}
}

bool GameManager::InValidAttackPosCheck(Position pos, Board* board, int x, int y)
{
	if (board == nullptr)
	{
		printf_s("board not found!");
		return true;
	}

	if (pos.y >= 'a' + BOARD_ROW || pos.y < 'a' || //���� ��ǥ�� ���� ������� üũ
		pos.x >= '1' + BOARD_COL || pos.x < '1')
	{
		m_MessageUI->PrintAttackResultMessage(INVALID_ATTACK, pos, x, y);
		return true;
	}
	if (board->GetPosMapStatus(pos) != NONE)	 //���� ��ǥ�� �̹� �����ߴ� ������ üũ
	{
		m_MessageUI->PrintAttackResultMessage(ALREADY_ATTACK, pos, x, y);
		return true;
	}
	m_MessageUI->PrintAttackResultMessage(VALID_ATTACK, pos, x, y);
	return false;
}

void GameManager::GameTurn(Player* attackPlayer, Player* defendPlayer, Board* defendBoard, std::string playerName, int x, int y)
{
	if (attackPlayer == nullptr || defendPlayer == nullptr)
	{
		printf_s("player not found!");
		return;
	}
	if (defendBoard == nullptr)
	{
		printf_s("board not found!");
		return;
	}
	Position attackPos;
	HitResult hitResult;
	if (attackPlayer->GetPlayerType() == USER_PLAYER)
		m_MenuUI->PrintAttackMenu(playerName);
	do
	{
		switch (attackPlayer->GetPlayerType())
		{
		case AI_PLAYER:
			attackPos = attackPlayer->RandomAttack();
			break;
		case USER_PLAYER:
			switch (m_MenuUI->GetCursorPos().y)
			{
			case RANDOM_ATTACK:
				attackPos = attackPlayer->RandomAttack();
				break;
			case USER_ATTACK:
				m_MessageUI->PrintAttackMessage();
				attackPos = attackPlayer->SelectAttack();
				break;
			}
			break;
		}
	} while (InValidAttackPosCheck(attackPos, defendBoard, x, y));
	m_MessageUI->EraseAttackMessage();

	hitResult = defendPlayer->HitCheck(attackPos);

	m_MessageUI->PrintHitResultMessage(hitResult, x, y+3);
}

void GameManager::UpdateBoard(Player* player)
{
	if (player == nullptr)
	{
		printf_s("player not found!");
		return;
	}
	//Player �� Board�� Manager�� ����� ����
	m_BoardUI->SetBoard(player->GetBoard());
}

void GameManager::GameReset()
{
	//���� ��ҵ��� �ʱ�ȭ
	m_BoardUI->		ResetBoard();
	m_BoardUI->		ResetCursorPos();
	m_MenuUI->		ResetCursorPos();
	m_MessageUI->	ResetCursorPos();
	m_Player1->		ResetBoard();
	m_Player1->		ResetShipInfo();
	m_Player2->		ResetBoard();
	m_Player2->		ResetShipInfo();
	m_Player1->		ResetPlayerHp();
	m_Player2->		ResetPlayerHp();
	m_DeadType =	NONE_DEAD;
	m_GameTurnNum = 0;
}

void GameManager::SetPlayerByGameMode()
{
	m_MenuUI->PrintMainMenu();
	// MainUI�� Ŀ����ġ�� ������� Player Type �� Player Name����
	switch (m_MenuUI->GetCursorPos().y)
	{
	case AI_vs_AI_MODE:
		m_GameMode = AI_vs_AI_MODE;
		m_Player1->SetPlayerType(AI_PLAYER);
		m_Player1->SetPlayerName("AI 1");
		m_Player2->SetPlayerType(AI_PLAYER);
		m_Player2->SetPlayerName("AI 2");
		break;
	case Player_vs_AI_MODE:
		m_GameMode = Player_vs_AI_MODE;
		m_Player1->SetPlayerType(USER_PLAYER);
		m_Player1->SetPlayerName("PLAYER 1");
		m_Player2->SetPlayerType(AI_PLAYER);
		m_Player2->SetPlayerName("AI 2");
		break;
	case Player_vs_Player_MODE:
		m_GameMode = Player_vs_Player_MODE;
		m_Player1->SetPlayerType(USER_PLAYER);
		m_Player1->SetPlayerName("PLAYER 1");
		m_Player2->SetPlayerType(USER_PLAYER);
		m_Player2->SetPlayerName("PLAYER 2");
		break;
	}
}

void GameManager::SetupShips(Player* player, Board* board)
{
	if (player == nullptr)
	{
		printf_s("player not found!");
		return;
	}
	if (board == nullptr)
	{
		printf_s("board not found!");
		return;
	}
	DirPosition setPosition;
	int shipHp;

	if (player->GetPlayerType() == USER_PLAYER)
		m_MenuUI->PrintSetupMenu(player->GetPlayerName()); // ��ġ��� ����

	for (int i = 0; i < TOTAL_COUNT; ++i)
	{
		shipHp = player->GetShipHp(i);	//���� ũ�� �Է�

		//���� ������ǥ�� vaild �ϸ� setPosition�� ������ break
		do
		{
			switch (player->GetPlayerType())
			{
			case AI_PLAYER:
				setPosition = player->RandomShipPos();
				break;
			case USER_PLAYER:
				switch (m_MenuUI->GetCursorPos().y) //PrintSetupMenu ������ Ŀ����ġ�� ��ġ��� ����
				{
				case RANDOM_SET:
					setPosition = player->RandomShipPos();
					break;
				case USER_SET:
					m_MessageUI->PrintSetupMessage((player->GetShip(i))->GetName());
					setPosition.pos = player->UserSetShipPos();
					setPosition.dir = SelectDirection();
					m_MessageUI->EraseSetupMessage();
				}
			}
		} while (InvalidSetPosCheck(board, shipHp, setPosition, (player->GetShip(i))->GetName()));
		player->SetupShip(setPosition, i);	//i��° �踦 setPosition�� ������� ��ġ
		m_MessageUI->EraseInvalidSetupMessage();
		PrintBoardShips(); //������ �踦 ���
	}
}

bool GameManager::GameIsOver()
{
	switch (m_DeadType)
	{
	case NONE_DEAD:
		return false;
	case PLAYER1_DEAD:
		m_MessageUI->PrintGameOverMessage(m_Player2->GetPlayerName());
		return true;
	case PLAYER2_DEAD:
		m_MessageUI->PrintGameOverMessage(m_Player1->GetPlayerName());
		return true;
	default:
		return false;
	}
}

void GameManager::GameLoop()
{
	m_GameTurnNum++; //Turn �� ����

	//Player1 Turn
	PrintBoardShips();
	if (m_Player1->GetPlayerHp() > 0)
	{
		//������� ������, ������, �������� ������, �������� �̸�, �޼����� ����� ��ǥ
		GameTurn(m_Player1, m_Player2, m_Player2->GetBoard(), m_Player1->GetPlayerName(),
			P1_BOARD_X, MESSAGE_INTERVAL * BOARD_ROW - MESSAGE_INTERVAL * 2);
	}
	else
	{
		m_DeadType = PLAYER1_DEAD;
	}

	//Player2 Turn
	PrintBoardShips();
	if (m_Player2->GetPlayerHp() > 0)
	{
		GameTurn(m_Player2, m_Player1, m_Player1->GetBoard(), m_Player2->GetPlayerName(),
			P2_BOARD_X, MESSAGE_INTERVAL * BOARD_ROW - MESSAGE_INTERVAL * 2);
	}
	else
	{
		m_DeadType = PLAYER2_DEAD;
	}
}

bool GameManager::InvalidSetPosCheck(Board* board, int shipHp, DirPosition setPosition, std::string shipName)
{
	if (board == nullptr)
	{
		printf_s("board not found!"); //board�� nullptr���� üũ
		return true;
	}

	if (setPosition.pos.y < 'a' || setPosition.pos.y >= 'a' + BOARD_ROW
		|| setPosition.pos.x < '1' || setPosition.pos.x >= '1' + BOARD_COL) //�Էµ� ��ǥ�� ���� ������� üũ
	{
		m_MessageUI->PrintInvalidSetupMessage(shipName);
		return true;
	}

	switch (setPosition.dir)
	{
		case VERTICAL:
			if (setPosition.pos.y + shipHp > 'a' + BOARD_ROW)	//���� ������ǥ�� ���� �踦 ��ġ������ ���� ������� üũ
			{
				m_MessageUI->PrintInvalidSetupMessage(shipName);
				return true;
			}
			for (int i = 0; i < shipHp; ++i)
			{
				if (board->GetPosMapType(setPosition.pos) != SHIP_NONE)	/*���� ������ǥ�� ���� �踦
																		��ġ�� ���߿� �谡 �̹� ������ �ִ��� üũ*/
				{
					m_MessageUI->PrintInvalidSetupMessage(shipName);
					return true;
				}
				setPosition.pos.y++;

			}
			break;
		case HORIZON:
			if (setPosition.pos.x + shipHp > '1' + BOARD_COL)
			{
				m_MessageUI->PrintInvalidSetupMessage(shipName);
				return true;
			}
			for (int i = 0; i < shipHp; ++i)
			{
				if (board->GetPosMapType(setPosition.pos) != SHIP_NONE)
				{
					m_MessageUI->PrintInvalidSetupMessage(shipName);
					return true;
				}
				setPosition.pos.x++;
			}
			break;
		default:
			m_MessageUI->PrintInvalidSetupMessage(shipName);
			return true;
	}
	return false;
}

void GameManager::PrintBoardFrame()
{
	m_BoardUI->PrintBoardFrame(P1_BOARD_X, P1_BOARD_Y, m_Player1->GetPlayerName());
	m_BoardUI->PrintBoardFrame(P2_BOARD_X, P2_BOARD_Y, m_Player2->GetPlayerName());
}

void GameManager::PrintEndMenu()
{
	m_MenuUI->PrintEndMenu();
	switch (m_MenuUI->GetCursorPos().y)
	{
	case GAME_END:
		m_GameStatus = GAME_END;
		break;
	case GAME_RESTART:
		m_GameStatus = GAME_RESTART;
		break;
	}
}

Direction GameManager::SelectDirection()
{
	m_MessageUI->PrintSetDirectionMessage();
	switch (m_MessageUI->GetCursorPos().y)
	{
	case HORIZON:
		return HORIZON;
	case VERTICAL:
		return VERTICAL;
	default:
		return NONEDIR;
	}
}

void GameManager::PrintBoardShips()
{
	if (m_DeadType != NONE_DEAD)
	{
		UpdateBoard(m_Player1);
		m_BoardUI->PrintBoardShips(P1_BOARD_X, P1_BOARD_Y);
		UpdateBoard(m_Player2);
		m_BoardUI->PrintBoardShips(P2_BOARD_X, P2_BOARD_Y);
	}

	else
	{
		switch (m_GameMode)
		{
		case AI_vs_AI_MODE:
			UpdateBoard(m_Player1);
			m_BoardUI->PrintBoardShips(P1_BOARD_X, P1_BOARD_Y);
			UpdateBoard(m_Player2);
			m_BoardUI->PrintBoardShips(P2_BOARD_X, P2_BOARD_Y);
			break;
		case Player_vs_AI_MODE:
			UpdateBoard(m_Player1);
			m_BoardUI->PrintBoardShips(P1_BOARD_X, P1_BOARD_Y);
			UpdateBoard(m_Player2);
			m_BoardUI->PrintBoardStatus(P2_BOARD_X, P2_BOARD_Y);
			break;
		case Player_vs_Player_MODE:
			UpdateBoard(m_Player1);
			m_BoardUI->PrintBoardStatus(P1_BOARD_X, P1_BOARD_Y);

			UpdateBoard(m_Player2);
			m_BoardUI->PrintBoardStatus(P2_BOARD_X, P2_BOARD_Y);
			break;
		}
	}
}
