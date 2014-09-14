#pragma once


class Ships
{
public:
	Ships();
	virtual ~Ships();

public:
	void		ResetPos()					{ memset(m_Pos, 0, sizeof(Position)* POS_MAX_SIZE); }
	void		ResetNowHp()				{ m_NowHp = m_MaxHp; }
	Position	GetPos(int i);
	std::string GetName()					{ return m_Name; }
	int			GetMaxHp()					{ return m_MaxHp; }
	int			GetNowHp()					{ return m_NowHp; }
	ShipType	GetShipType()				{ return m_Type; }
	HitResult	HitCheck(Position pos);
	void		AddPosition(char x, char y);
	void		AddPosition(Position pos);

protected:
	Position m_Pos[POS_MAX_SIZE];
	int m_MaxHp;
	int m_NowHp;
	ShipType m_Type;
	std::string m_Name;
};

