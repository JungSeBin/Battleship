#pragma once
#include "UI.h"

class GameMessageUI:
	public UI
{
public:
	GameMessageUI();
	~GameMessageUI();

public:
	void	PrintHitResultMessage(HitResult hitResult, int x, int y);
	void	PrintAttackResultMessage(AttackResult attackResult, Position attackPos, int x, int y);
	void	PrintGameOverMessage(std::string playerName);
	void	PrintSetDirectionMessage();
	void	PrintGameNumMessage(int playNum, int TurnNum, int TurnSum);
	void	PrintInvalidSetupMessage(std::string shipName);
	void	EraseInvalidSetupMessage();
	void	PrintAttackMessage();
	void	EraseAttackMessage();
	void	PrintSetupMessage(std::string shipName);
	void	EraseSetupMessage();
};

