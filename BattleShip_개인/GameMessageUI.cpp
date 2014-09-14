#include "stdafx.h"
#include "GameMessageUI.h"
#pragma warning(disable:4996)


GameMessageUI::GameMessageUI()
{
}


GameMessageUI::~GameMessageUI()
{
}

void GameMessageUI::PrintHitResultMessage(HitResult hitResult, int x, int y )
{
	Gotoxy(x, y);
	printf_s("                                   ");
	Gotoxy(x, y);
	switch (hitResult)
	{
	case MISS:
		printf_s("적에게 공격이 빗나갔습니다.");
		break;
	case HIT:
		printf_s("적에게 공격이 성공하였습니다.");
		break;
	case AIRCRAFT_DESTROY:
		printf_s("적의 Aircraft를 격침하였습니다.");
		break;
	case BATTLESHIP_DESTROY:
		printf_s("적의 BattleShip을 격침하였습니다.");
		break;
	case CRUISER_DESTROY:
		printf_s("적의 Cruiser를 격침하였습니다.");
		break;
	case DESTROYER_DESTROY:
		printf_s("적의 Destroyer를 격침하였습니다.");
		break;
	}
}

void GameMessageUI::PrintAttackResultMessage(AttackResult attackResult, Position attackPos, int x, int y)
{
	Gotoxy(ATTACKMESSAGE_X - MESSAGE_INTERVAL * 2, ATTACKMESSAGE_Y + MESSAGE_INTERVAL);
	printf_s("                                        ");
	switch (attackResult)
	{
	case ALREADY_ATTACK:
		Gotoxy(ATTACKMESSAGE_X - MESSAGE_INTERVAL, ATTACKMESSAGE_Y + MESSAGE_INTERVAL);
		printf_s("\"%c%c\" (은)는 이미 공격한 좌표입니다.", attackPos.y, attackPos.x);
		break;
	case INVALID_ATTACK:
		Gotoxy(ATTACKMESSAGE_X - MESSAGE_INTERVAL * 2, ATTACKMESSAGE_Y + MESSAGE_INTERVAL);
		printf_s("\"%c%c\" (은)는 유효하지 않은 좌표입니다.", attackPos.y, attackPos.x);
		break;
	case VALID_ATTACK:
		Gotoxy(x, y);
		printf_s("\"%c%c\" (을)를 공격하였습니다.", attackPos.y, attackPos.x);
		break;
	}
}

void GameMessageUI::PrintAttackMessage()
{
	Gotoxy(ATTACKMESSAGE_X, ATTACKMESSAGE_Y - MENU_INTERVAL);
	printf_s("*공격 좌표 설정*");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL, ATTACKMESSAGE_Y - 2);
	printf_s("┏━┓");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL, ATTACKMESSAGE_Y - 1);
	printf_s("┃--┃");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL, ATTACKMESSAGE_Y);
	printf_s("┗━┛");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL + 2, ATTACKMESSAGE_Y - 1);
}

void GameMessageUI::EraseAttackMessage()
{
	Gotoxy(ATTACKMESSAGE_X, ATTACKMESSAGE_Y - MENU_INTERVAL);
	printf_s("                ");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL, ATTACKMESSAGE_Y - 2);
	printf_s("      ");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL, ATTACKMESSAGE_Y - 1);
	printf_s("      ");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL, ATTACKMESSAGE_Y);
	printf_s("      ");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL + 2, ATTACKMESSAGE_Y - 1);
	printf_s("  ");
}

void GameMessageUI::PrintGameOverMessage(std::string playerName)
{
	Gotoxy(ATTACKMENU_X + 6, 1);
	printf_s("                    ");
	Gotoxy(ENDMESSAGE_X,ENDMESSAGE_Y);
	printf_s("  ** 게임 종료 **");
	Gotoxy(ENDMESSAGE_X - MESSAGE_INTERVAL, ENDMESSAGE_Y + MESSAGE_INTERVAL);
	printf_s("  <%s> (이)가 이겼습니다.", playerName.c_str());
}

void GameMessageUI::PrintSetupMessage(std::string shipName)
{
	Gotoxy(SETUPMESSAGE_X, SETUPMESSAGE_Y);
	printf_s("** %s 배치 시작 좌표 입력 **", shipName.c_str());
	Gotoxy(SETUPMESSAGE_X, SETUPMESSAGE_Y + MESSAGE_INTERVAL);
	printf_s(" ex) \"a1\"이면 \"a1\"부터 순서대로 배치");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3 , SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2 - 2);
	printf_s("┏━┓");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3, SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2 - 1);
	printf_s("┃--┃");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3 , SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2);
	printf_s("┗━┛");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3 + 2, SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2 - 1);
}

void GameMessageUI::EraseSetupMessage()
{
	Gotoxy(SETUPMESSAGE_X, SETUPMESSAGE_Y);
	printf_s("                                     ");
	Gotoxy(SETUPMESSAGE_X, SETUPMESSAGE_Y + MESSAGE_INTERVAL);
	printf_s("                                    ");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3, SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2 - 2);
	printf_s("      ");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3 , SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2 - 1);
	printf_s("      ");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3 , SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2);
	printf_s("      ");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3 + 2, SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2 - 1);
}

void GameMessageUI::PrintInvalidSetupMessage(std::string shipName)
{
	Gotoxy(DIRECTIONMESSAGE_X - MESSAGE_INTERVAL, DIRECTIONMESSAGE_Y + MESSAGE_INTERVAL * 3);
	printf_s("해당 좌표로부터는 %s의 배치가 불가능 합니다.", shipName.c_str());
}

void GameMessageUI::EraseInvalidSetupMessage()
{
	Gotoxy(DIRECTIONMESSAGE_X - MESSAGE_INTERVAL, DIRECTIONMESSAGE_Y + MESSAGE_INTERVAL * 3);
	printf_s("                                                    ");
}

void GameMessageUI::PrintSetDirectionMessage()
{
	char select = NULL;
	m_CursorPos.x = DIRECTIONMESSAGE_X;
	m_CursorPos.y = DIRECTIONMESSAGE_Y + MENU_INTERVAL;
	Gotoxy(DIRECTIONMESSAGE_X, DIRECTIONMESSAGE_Y);
	printf_s("*배를 배치할 방향을 선택하십시오.*");
	Gotoxy(DIRECTIONMESSAGE_X + MENU_INTERVAL, DIRECTIONMESSAGE_Y + MENU_INTERVAL);
	printf_s("가로 배치");
	Gotoxy(DIRECTIONMESSAGE_X + MENU_INTERVAL, DIRECTIONMESSAGE_Y + MENU_INTERVAL * 2);
	printf_s("세로 배치");
	while (select != ENTER)
	{
		Gotoxy(m_CursorPos.x, m_CursorPos.y);
		printf_s("▶");
		select = getch();
		Gotoxy(m_CursorPos.x, m_CursorPos.y);
		printf_s("  ");
		switch (select)
		{
		case UP:
			m_CursorPos.y -= CURSOR_INTERVAL;
			if (m_CursorPos.y < HORIZON)
				m_CursorPos.y += CURSOR_INTERVAL;
			break;
		case DOWN:
			m_CursorPos.y += CURSOR_INTERVAL;
			if (m_CursorPos.y > VERTICAL)
				m_CursorPos.y -= CURSOR_INTERVAL;
			break;
		}
	}

	//enter 입력후 내용 지우기
	Gotoxy(DIRECTIONMESSAGE_X, DIRECTIONMESSAGE_Y);
	printf_s("                                    ");
	Gotoxy(DIRECTIONMESSAGE_X + MENU_INTERVAL, DIRECTIONMESSAGE_Y + MENU_INTERVAL);
	printf_s("         ");
	Gotoxy(DIRECTIONMESSAGE_X + MENU_INTERVAL, DIRECTIONMESSAGE_Y + MENU_INTERVAL * 2);
	printf_s("         ");
}

void GameMessageUI::PrintGameNumMessage(int playNum, int TurnNum, int TurnSum)
{
	Gotoxy(GAMENUMMESSAGE_X, GAMENUMMESSAGE_Y);
	printf_s("플레이 횟수: %d번  ", playNum);
	printf_s("이번 게임 턴수: %d턴", TurnNum);
	Gotoxy(GAMENUMMESSAGE_X, GAMENUMMESSAGE_Y + 2);
	printf_s("   지금까지의 평균 턴수: %d턴", TurnSum / playNum);
}
