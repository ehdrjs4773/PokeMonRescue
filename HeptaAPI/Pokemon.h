#pragma once
#include "gameNode.h"
#include <vector>
#include <math.h>

#define LEVEL_MAX	99		// �ִ� ����

enum ELEMENT
{
	ELEMENT_NORMAL,		// �븻
	ELEMENT_FIRE,		// ��
	ELEMENT_WATER,		// ��
	ELEMENT_ELECTRIC,	// ����
	ELEMENT_PLANT,		// Ǯ
	ELEMENT_ICE,		// ����
	ELEMENT_FIGHT,		// ����
	ELEMENT_POISON,		// ��
	ELEMENT_EARTH,		// ��
	ELEMENT_WING,		// ����
	ELEMENT_ESPER,		// ������
	ELEMENT_INSECT,		// ����
	ELEMENT_ROCK,		// ����
	ELEMENT_GHOST,		// ��Ʈ
	ELEMENT_DRAGON,		// �巡��
	ELEMENT_DARK,		// ��
	ELEMENT_STEEL,		// ��ö
	ELEMENT_END
};

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

public:
	pokemon();
	~pokemon();

	HRESULT init();
	void pokemonStatus(string name, int level, ELEMENT element);
	void expPlus(int exp);
	void islevelUp();

	//���� ������
	inline int getMaxHP() { return _maxHP; }
	inline int getCurrentHP() { return _currentHP; }
	inline int getMaxEXP() { return _maxEXP; }
	inline int getCurrentEXP() { return _currentEXP; }
	inline int getAtk() { return _atk; }
	inline int getDef() { return _def; }
	inline int getSpecialAtk() { return _specialATK; }
	inline int getSpecialDef() { return _specialDEF; }
	inline int getLevel() { return _level; }
	inline ELEMENT getElement() { return _element; }
	inline string getName() { return _pokemonName; }

	//������
	inline int setCurrentEXP(int exp) { _currentEXP = exp; }

};
