#pragma once
#include "gameNode.h"

enum ELEMENT
{
	ELEMENT_NORMAL,		// �븻	0
	ELEMENT_FIRE,			// ��	1
	ELEMENT_WATER,		// ��	2
	ELEMENT_ELECTRIC,		// ����	3
	ELEMENT_PLANT,		// Ǯ	4
	ELEMENT_ICE,			// ����	5
	ELEMENT_FIGHT,		// ����	6
	ELEMENT_POISON,		// ��	7
	ELEMENT_EARTH,		// ��	8
	ELEMENT_WING,			// ����	9
	ELEMENT_ESPER,		// ������10
	ELEMENT_INSECT,		// ����	11
	ELEMENT_ROCK,			// ����	12
	ELEMENT_GHOST,		// ��Ʈ13
	ELEMENT_DRAGON,		// �巡��14
	ELEMENT_DARK,			// ��	15
	ELEMENT_STEEL,		// ��ö	16
	ELEMENT_END
};

class skills
{
protected:
	ELEMENT _skillElement;
	string _skillName;
	USHORT _power;
	USHORT _maxPP;
	USHORT _currentPP;

public:
	skills();
	~skills();

	HRESULT init(string name);
	void setSkill(string name, int currentPP);

	inline void useSkill() { _currentPP--; }

	inline ELEMENT getSkillElement() { return _skillElement; }
	inline USHORT getCurrentPP() { return _currentPP; }
	inline USHORT getMaxPP() { return _maxPP; }
	inline USHORT getPower() { return _power; }
	inline string getName() { return _skillName; }

	inline void setCurrentPP(int pp) { _currentPP = pp; }
};

