#pragma once
#include "gameNode.h"
#include <vector>
#include <math.h>

#define LEVEL_MAX	99		// 최대 레벨

enum ELEMENT
{
	ELEMENT_NORMAL,		// 노말	0
	ELEMENT_FIRE,		// 불	1
	ELEMENT_WATER,		// 물	2
	ELEMENT_ELECTRIC,	// 전기	3
	ELEMENT_PLANT,		// 풀	4
	ELEMENT_ICE,		// 얼음	5
	ELEMENT_FIGHT,		// 격투	6
	ELEMENT_POISON,		// 독	7
	ELEMENT_EARTH,		// 땅	8
	ELEMENT_WING,		// 비행	9
	ELEMENT_ESPER,		// 에스퍼10
	ELEMENT_INSECT,		// 곤충	11
	ELEMENT_ROCK,		// 바위	12
	ELEMENT_GHOST,		// 고스트13
	ELEMENT_DRAGON,		// 드래곤14
	ELEMENT_DARK,		// 악	15
	ELEMENT_STEEL,		// 강철	16
	ELEMENT_END
};

// 자... 이제 시작이야...(내꿈은~) 내꿈을 위한 여행~(피↗카↘츄↗!~) 걱정따윈없어 (없어↗!~~)
// 내 친구와!↗ 함께니까(픽↗까↘픽↗까↘!) 처음시작은 어색할지도 몰라~ (몰라!내친구 피카츄!~~) 
//날 지켜줄 거라고 믿고 있어~ 누구라도 얕보다간 큰일 나! 
//언제~나 어디서나 (피카츄가 옆에 있어!) 약할 때나 강할 때나 (피카츄가 옆에 있어!)
//너와 나 함께라면 우린 최고야~

class pokemon : public gameNode
{
protected:
	ELEMENT _element;		// 포켓몬의 속성
	string _pokemonName;	// 포켓몬 이름(종류)

	USHORT _level;			// 레벨	

	//포켓몬(종족)마다 처음 가지고있는 기본 능력치들
	USHORT _racialHP;		
	USHORT _racialATK;
	USHORT _racialDEF;
	USHORT _racialSpecialATK;		//기술썼을때 들어갈 데미지용 능력치
	USHORT _racialSpecialDEF;


	//종족치 + 레벨에 따라 늘어날 능력치 합한것을 넣을 공간
	USHORT _maxHP;
	USHORT _currentHP;
	USHORT _atk;
	USHORT _def;
	USHORT _specialATK;
	USHORT _specialDEF;
	USHORT _maxEXP;
	USHORT _currentEXP;

	// 적을 잡으면 얻는 경험치
	USHORT _exp;

public:
	pokemon();
	~pokemon();

	HRESULT init();
	void pokemonStatus(string name, int level);
	void expPlus(int exp);
	void islevelUp();

	//각종 접근자
	inline int getMaxHP() { return _maxHP; }
	inline int getCurrentHP() { return _currentHP; }
	inline int getMaxEXP() { return _maxEXP; }
	inline int getCurrentEXP() { return _currentEXP; }
	inline int getAtk() { return _atk; }
	inline int getDef() { return _def; }
	inline int getSpecialATK() { return _specialATK; }
	inline int getSpecialDef() { return _specialDEF; }
	inline int getLevel() { return _level; }
	inline ELEMENT getElement() { return _element; }
	inline string getName() { return _pokemonName; }

	//설정자
	inline int setCurrentEXP(int exp) { _currentEXP = exp; }

};
