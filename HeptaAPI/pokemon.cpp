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
	
	_maxHP = _racialHP + (level*((_racialHP + 50) / 50));
	_currentHP = _maxHP;	//��ó���� Ǯ�Ǵϱ�

	_atk = _racialATK + (level*((_racialATK + 50) / 50));
	_def = _racialDEF + (level*((_racialDEF + 50) / 50));
	_specialATK = _racialSpecialATK + (level * ((_racialSpecialATK + 50) / 50));
	_specialDEF = _racialSpecialDEF + (level* ((_racialSpecialDEF + 50) / 50));

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
void pokemon::hitDamage(int damage)
{
	if (damage > _currentHP)
		_currentHP = 0;
	else
		_currentHP -= damage;
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