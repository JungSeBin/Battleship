#include "stdafx.h"
#include "GameMenuUI.h"
#pragma warning(disable:4996)


GameMenuUI::GameMenuUI()
{
}


GameMenuUI::~GameMenuUI()
{
}

void GameMenuUI::PrintMainMenu()
{
	char select = NULL;
	m_CursorPos.x = MAINMENU_X;
	m_CursorPos.y = MAINMENU_Y + MENU_INTERVAL;
	Gotoxy(MAINMENU_X, MAINMENU_Y);
	SetColor(15);
	printf_s("***���� ��带 �����Ͻʽÿ�***");
	Gotoxy(MAINMENU_X + MENU_INTERVAL, MAINMENU_Y + MENU_INTERVAL);
	printf_s("AI vs AI");
	Gotoxy(MAINMENU_X + MENU_INTERVAL, MAINMENU_Y + MENU_INTERVAL*2);
	printf_s("Player vs AI");
	Gotoxy(MAINMENU_X + MENU_INTERVAL, MAINMENU_Y + MENU_INTERVAL*3);
	printf_s("Player vs Player");
	Gotoxy(MAINMENU_X + MENU_INTERVAL * 6, MAINMENU_Y + MENU_INTERVAL * 5);
	printf_s("������ ������ ũ��: %d X %d\n", BOARD_ROW, BOARD_COL);
	SetColor(14);
	printf_s("��WARNING��\n");
	SetColor(15);
	printf_s("������ ũ�Ⱑ 9�� �Ѿ�� AI vs AI ��常 �����մϴ�. ex) (10x9)");
	while (select != ENTER)
	{
		if (BOARD_ROW > 9 || BOARD_ROW > 9)
			m_CursorPos.y = AI_vs_AI_MODE;

		Gotoxy(m_CursorPos.x, m_CursorPos.y);
		printf_s("��");					 
		select = getch();				  
		Gotoxy(m_CursorPos.x, m_CursorPos.y);
		printf_s("  ");
		switch (select)
		{
		case UP:
			m_CursorPos.y -= CURSOR_INTERVAL;
			if (m_CursorPos.y < AI_vs_AI_MODE)
				m_CursorPos.y += CURSOR_INTERVAL;
			break;
		case DOWN:
			m_CursorPos.y += CURSOR_INTERVAL;
			if (m_CursorPos.y > Player_vs_Player_MODE)
				m_CursorPos.y -= CURSOR_INTERVAL;
			break;
		default:
			break;
		}
	}
	system("cls");
}

void GameMenuUI::PrintSetupMenu(std::string playerName)
{
	char select = NULL;
	m_CursorPos.x = SETUPMENU_X;
	m_CursorPos.y = SETUPMENU_Y + MENU_INTERVAL;
	Gotoxy(SETUPMENU_X + 6, 1);
	printf_s("** %s Turn **", playerName.c_str());
	Gotoxy(SETUPMENU_X, SETUPMENU_Y);
	printf_s("*�踦 ��ġ�� ����� �����Ͻʽÿ�.*");
	Gotoxy(SETUPMENU_X + MENU_INTERVAL, SETUPMENU_Y + MENU_INTERVAL);
	printf_s("���� ��ġ");
	Gotoxy(SETUPMENU_X+MENU_INTERVAL, SETUPMENU_Y + MENU_INTERVAL * 2);
	printf_s("���� ���� ��ġ");
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
			if (m_CursorPos.y < RANDOM_SET) 
				m_CursorPos.y += CURSOR_INTERVAL;
			break;
		case DOWN:
			m_CursorPos.y += CURSOR_INTERVAL;
			if (m_CursorPos.y > USER_SET) 
				m_CursorPos.y -= CURSOR_INTERVAL;
			break;
		}
	}
	Gotoxy(SETUPMENU_X, SETUPMENU_Y);
	printf_s("                                    ");
	Gotoxy(SETUPMENU_X + MENU_INTERVAL, SETUPMENU_Y + MENU_INTERVAL);
	printf_s("           ");
	Gotoxy(SETUPMENU_X + MENU_INTERVAL, SETUPMENU_Y + MENU_INTERVAL * 2);
	printf_s("                ");
}

void GameMenuUI::PrintAttackMenu(std::string playerName)
{
	char select = NULL;
	m_CursorPos.x = ATTACKMENU_X;
	m_CursorPos.y = ATTACKMENU_Y + MENU_INTERVAL;
	Gotoxy(ATTACKMENU_X + 6, 1);
	printf_s("** %s Turn **", playerName.c_str());
	Gotoxy(ATTACKMENU_X, ATTACKMENU_Y);
	printf_s("*�踦 ������ ����� �����Ͻʽÿ�.*");
	Gotoxy(ATTACKMENU_X + MENU_INTERVAL, ATTACKMENU_Y + MENU_INTERVAL);
	printf_s("���� ����");
	Gotoxy(ATTACKMENU_X + MENU_INTERVAL, ATTACKMENU_Y + MENU_INTERVAL * 2);
	printf_s("���� ����");
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
			if (m_CursorPos.y < RANDOM_ATTACK)
				m_CursorPos.y += CURSOR_INTERVAL;
			break;
		case DOWN:
			m_CursorPos.y += CURSOR_INTERVAL;
			if (m_CursorPos.y > USER_ATTACK)
				m_CursorPos.y -= CURSOR_INTERVAL;
			break;
		}
	}
	//���� �޼����� �����
	Gotoxy(ATTACKMENU_X, ATTACKMENU_Y);
	printf_s("                                    ");
	Gotoxy(ATTACKMENU_X, ATTACKMENU_Y + MENU_INTERVAL);
	printf_s("             ");
	Gotoxy(ATTACKMENU_X, ATTACKMENU_Y + MENU_INTERVAL * 2);
	printf_s("             ");
}

void GameMenuUI::PrintEndMenu()
{
	char select = NULL;
	m_CursorPos.x = ENDMENU_X;
	m_CursorPos.y = ENDMENU_Y + MENU_INTERVAL;
	Gotoxy(ENDMENU_X, ENDMENU_Y);
	printf_s("***������ �����Ͻðڽ��ϱ�?***");
	Gotoxy(ENDMENU_X + MENU_INTERVAL, ENDMENU_Y + MENU_INTERVAL);
	printf_s("*���� ����*");
	Gotoxy(ENDMENU_X + MENU_INTERVAL, ENDMENU_Y + MENU_INTERVAL * 2);
	printf_s("*���� �ٽ��ϱ�*");
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
			if (m_CursorPos.y < GAME_END)
				m_CursorPos.y += CURSOR_INTERVAL;
			break;
		case DOWN:
			m_CursorPos.y += CURSOR_INTERVAL;
			if (m_CursorPos.y > GAME_RESTART)
				m_CursorPos.y -= CURSOR_INTERVAL;
			break;
		default:
			break;
		}
	}
	system("cls");
}
