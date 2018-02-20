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
//							���ϸ��̸�,������ ���� (*����* ���ϸ��̸��� �ؽ�Ʈ�� �ִ´�� �־��ִ� �����ʿ�) 
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
	_element = (ELEMENT)DATABASE->getStatusData(name)->element;

	_currentEXP = 0;
	_maxEXP = 100;
	
	_maxHP = _racialHP;		
	_currentHP = _maxHP;	//��ó���� Ǯ�Ǵϱ�

	_atk = _racialATK;
	_def = _racialDEF;
	_specialATK = _racialSpecialATK;
	_specialDEF = _racialSpecialDEF;

}

//����ġ�÷��ִ°�
void pokemon::expPlus(int exp)
{
	_currentEXP += exp;
}

//�������ϸ� �ɷ�ġ�����°� ������Ʈ�Ҽ��ִ°��� �ɾ��ּ���
void pokemon::islevelUp()
{
	if (_maxEXP <= _currentEXP)
	{
		_level++;
		_currentEXP = _currentEXP - _maxEXP; //�������ϰ� ���� ����ġ�� �������ǰ� ���ƾ��ϴϱ�
		_maxEXP += _level * 30;				 //��...�������� ����ְ������
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