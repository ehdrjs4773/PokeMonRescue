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
//							���ϸ��̸�,����,���ϸ��� �Ӽ�
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