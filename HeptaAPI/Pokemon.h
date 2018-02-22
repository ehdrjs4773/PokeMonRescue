#pragma once
#include "gameNode.h"
#include "skills.h"
#include <vector>
#include <math.h>

#define LEVEL_MAX	99		// �ִ� ����

// ��... ���� �����̾�...(������~) ������ ���� ����~(�Ǣ�ī�����!~) ������������ (�����!~~)
// �� ģ����!�� �Բ��ϱ�(�Ȣֱ���Ȣֱ��!) ó�������� ��������� ����~ (����!��ģ�� ��ī��!~~) 
//�� ������ �Ŷ�� �ϰ� �־�~ ������ �躸�ٰ� ū�� ��! 
//����~�� ��𼭳� (��ī�� ���� �־�!) ���� ���� ���� ���� (��ī�� ���� �־�!)
//�ʿ� �� �Բ���� �츰 �ְ��~

class pokemon : public gameNode
{
protected:
	ELEMENT _element;		// ���ϸ��� �Ӽ�
	string _pokemonName;	// ���ϸ� �̸�(����)

	USHORT _level;			// ����	

	//���ϸ�(����)���� ó�� �������ִ� �⺻ �ɷ�ġ��
	USHORT _racialHP;		
	USHORT _racialATK;
	USHORT _racialDEF;
	USHORT _racialSpecialATK;		//��������� �� �������� �ɷ�ġ
	USHORT _racialSpecialDEF;


	//����ġ + ������ ���� �þ �ɷ�ġ ���Ѱ��� ���� ����
	USHORT _maxHP;
	USHORT _currentHP;
	USHORT _atk;
	USHORT _def;
	USHORT _specialATK;
	USHORT _specialDEF;
	USHORT _maxEXP;
	USHORT _currentEXP;

	// ���� ������ ��� ����ġ
	USHORT _exp;

	vector<skills*>				_vSkills;		// ��ų ����
	vector<skills*>::iterator	_vSkillsIter;	// ��ų ���� ���ͷ�����

public:
	pokemon();
	~pokemon();

	HRESULT init();
	void pokemonStatus(string name, int level);
	void expPlus(int exp);
	void islevelUp();
	void hitDamage(int damage);
	bool addSkill(skills* sk);

	//���� ������
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

	inline vector<skills*> getVSkill() { return _vSkills; }


	//������
	inline int setCurrentEXP(int exp) { _currentEXP = exp; }
	inline void setCurrentHP(int currentHP) { _currentHP  = currentHP; }
};
