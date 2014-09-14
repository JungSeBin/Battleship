#pragma once
class UI
{
public:
	UI();
	virtual ~UI();

public:
	void		ResetCursorPos();
	Position	GetCursorPos()			{ return m_CursorPos; }

protected:
	void		Gotoxy(int x, int y);
	void		SetColor(int color);
	Position	m_CursorPos;
};

