#include "stdafx.h"
#include "pokemon.h"

pokemon::pokemon()
{

}
pokemon::~pokemon()
{

}
					
HRESULT pokemon::init()
{
	
	return S_OK;
}
//							포켓몬이름,레벨,포켓몬의 속성
void pokemon::pokemonStatus(string name, int level, ELEMENT element)
{
	if (level > LEVEL_MAX)
		level = LEVEL_MAX;

	_pokemonName = name;
	_level = level;
	_element = element;
	
	_racialHP = DATABASE->getElementData(name)->hp;
	_racialATK = DATABASE->getElementData(name)->atk;
	_racialDEF = DATABASE->getElementData(name)->def;
	_racialSpecialATK = DATABASE->getElementData(name)->specialATK;
	_racialSpecialDEF = DATABASE->getElementData(name)->specialDEF;

	_maxHP = _racialHP;
	_currentHP = _maxHP;
	_maxEXP = 100;
	_atk = _racialATK;
	_def = _racialDEF;
	_specialATK = _racialSpecialATK;
	_specialDEF = _racialSpecialDEF;

	_currentEXP = 0;
	
}

//경험치올려주는거
void pokemon::expPlus(int exp)
{
	_currentEXP += exp;
}

//레벨업하면 능력치오르는거 업데이트할수있는곳에 걸어주세요
void pokemon::islevelUp()
{
	if (_maxEXP <= _currentEXP)
	{
		_level++;
		_currentEXP = _currentEXP - _maxEXP; //레벨업하고 남은 경험치는 레벨업되고 남아야하니까
		_maxEXP += _level * 30;				 //음...공식으로 집어넣고싶은데
		_maxHP += 3;					
		_atk += 2;
		_def += 2;
		_specialATK += 2;
		_specialDEF += 2;
	}
}