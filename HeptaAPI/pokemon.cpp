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
//							포켓몬이름,설정할 레벨 (*주의* 포켓몬이름은 텍스트에 있는대로 넣어주는 센스필요) 
void pokemon::pokemonStatus(string name, int level)
{
	if (level > LEVEL_MAX)
		level = LEVEL_MAX;

	_pokemonName = name;
	_level = level;
	
	
	_racialHP = DATABASE->getStatusData(name)->hp;
	_racialATK = DATABASE->getStatusData(name)->atk;
	_racialDEF = DATABASE->getStatusData(name)->def;
	_racialSpecialATK = DATABASE->getStatusData(name)->specialATK;
	_racialSpecialDEF = DATABASE->getStatusData(name)->specialDEF;
	_element = (SKILL_ELEMENT)DATABASE->getStatusData(name)->element;

	_currentEXP = 0;
	_maxEXP = 100;
	
	_maxHP = _racialHP;		
	_currentHP = _maxHP;	//맨처음엔 풀피니까

	_atk = _racialATK;
	_def = _racialDEF;
	_specialATK = _racialSpecialATK;
	_specialDEF = _racialSpecialDEF;

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

bool pokemon::addSkill(skills* sk)
{
	if (_vSkills.size() >= 4)
		return false;
	else
	{
		_vSkills.push_back(sk);
		return true;
	}
}