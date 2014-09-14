#pragma once
#include "UI.h"
class GameMenuUI:
	public UI
{
public:
	GameMenuUI();
	~GameMenuUI();

public:
	void	PrintMainMenu();
	void	PrintSetupMenu(std::string playerName);
	void	PrintAttackMenu(std::string playerName);
	void	PrintEndMenu();
};

