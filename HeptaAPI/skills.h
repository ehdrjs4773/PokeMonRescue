#pragma once
#include "gameNode.h"

enum ELEMENT
{
	ELEMENT_NORMAL,		// 노말	0
	ELEMENT_FIRE,			// 불	1
	ELEMENT_WATER,		// 물	2
	ELEMENT_ELECTRIC,		// 전기	3
	ELEMENT_PLANT,		// 풀	4
	ELEMENT_ICE,			// 얼음	5
	ELEMENT_FIGHT,		// 격투	6
	ELEMENT_POISON,		// 독	7
	ELEMENT_EARTH,		// 땅	8
	ELEMENT_WING,			// 비행	9
	ELEMENT_ESPER,		// 에스퍼10
	ELEMENT_INSECT,		// 곤충	11
	ELEMENT_ROCK,			// 바위	12
	ELEMENT_GHOST,		// 고스트13
	ELEMENT_DRAGON,		// 드래곤14
	ELEMENT_DARK,			// 악	15
	ELEMENT_STEEL,		// 강철	16
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

