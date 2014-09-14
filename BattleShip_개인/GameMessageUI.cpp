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
		printf_s("������ ������ ���������ϴ�.");
		break;
	case HIT:
		printf_s("������ ������ �����Ͽ����ϴ�.");
		break;
	case AIRCRAFT_DESTROY:
		printf_s("���� Aircraft�� ��ħ�Ͽ����ϴ�.");
		break;
	case BATTLESHIP_DESTROY:
		printf_s("���� BattleShip�� ��ħ�Ͽ����ϴ�.");
		break;
	case CRUISER_DESTROY:
		printf_s("���� Cruiser�� ��ħ�Ͽ����ϴ�.");
		break;
	case DESTROYER_DESTROY:
		printf_s("���� Destroyer�� ��ħ�Ͽ����ϴ�.");
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
		printf_s("\"%c%c\" (��)�� �̹� ������ ��ǥ�Դϴ�.", attackPos.y, attackPos.x);
		break;
	case INVALID_ATTACK:
		Gotoxy(ATTACKMESSAGE_X - MESSAGE_INTERVAL * 2, ATTACKMESSAGE_Y + MESSAGE_INTERVAL);
		printf_s("\"%c%c\" (��)�� ��ȿ���� ���� ��ǥ�Դϴ�.", attackPos.y, attackPos.x);
		break;
	case VALID_ATTACK:
		Gotoxy(x, y);
		printf_s("\"%c%c\" (��)�� �����Ͽ����ϴ�.", attackPos.y, attackPos.x);
		break;
	}
}

void GameMessageUI::PrintAttackMessage()
{
	Gotoxy(ATTACKMESSAGE_X, ATTACKMESSAGE_Y - MENU_INTERVAL);
	printf_s("*���� ��ǥ ����*");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL, ATTACKMESSAGE_Y - 2);
	printf_s("������");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL, ATTACKMESSAGE_Y - 1);
	printf_s("��--��");
	Gotoxy(ATTACKMESSAGE_X + MESSAGE_INTERVAL, ATTACKMESSAGE_Y);
	printf_s("������");
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
	printf_s("  ** ���� ���� **");
	Gotoxy(ENDMESSAGE_X - MESSAGE_INTERVAL, ENDMESSAGE_Y + MESSAGE_INTERVAL);
	printf_s("  <%s> (��)�� �̰���ϴ�.", playerName.c_str());
}

void GameMessageUI::PrintSetupMessage(std::string shipName)
{
	Gotoxy(SETUPMESSAGE_X, SETUPMESSAGE_Y);
	printf_s("** %s ��ġ ���� ��ǥ �Է� **", shipName.c_str());
	Gotoxy(SETUPMESSAGE_X, SETUPMESSAGE_Y + MESSAGE_INTERVAL);
	printf_s(" ex) \"a1\"�̸� \"a1\"���� ������� ��ġ");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3 , SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2 - 2);
	printf_s("������");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3, SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2 - 1);
	printf_s("��--��");
	Gotoxy(SETUPMESSAGE_X + MESSAGE_INTERVAL * 3 , SETUPMESSAGE_Y + MESSAGE_INTERVAL * 2);
	printf_s("������");
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
	printf_s("�ش� ��ǥ�κ��ʹ� %s�� ��ġ�� �Ұ��� �մϴ�.", shipName.c_str());
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
	printf_s("*�踦 ��ġ�� ������ �����Ͻʽÿ�.*");
	Gotoxy(DIRECTIONMESSAGE_X + MENU_INTERVAL, DIRECTIONMESSAGE_Y + MENU_INTERVAL);
	printf_s("���� ��ġ");
	Gotoxy(DIRECTIONMESSAGE_X + MENU_INTERVAL, DIRECTIONMESSAGE_Y + MENU_INTERVAL * 2);
	printf_s("���� ��ġ");
	while (select != ENTER)
	{
		Gotoxy(m_CursorPos.x, m_CursorPos.y);
		printf_s("��");
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

	//enter �Է��� ���� �����
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
	printf_s("�÷��� Ƚ��: %d��  ", playNum);
	printf_s("�̹� ���� �ϼ�: %d��", TurnNum);
	Gotoxy(GAMENUMMESSAGE_X, GAMENUMMESSAGE_Y + 2);
	printf_s("   ���ݱ����� ��� �ϼ�: %d��", TurnSum / playNum);
}
