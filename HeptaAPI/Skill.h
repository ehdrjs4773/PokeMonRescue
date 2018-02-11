#pragma once
#include "gameNode.h"



enum type				// ��ų Ÿ�� ����
{
	type_Nomal,         // �븻 Ÿ��
	type_Fire,			// �� Ÿ��
	type_Ice,			// ���� Ÿ��
	type_Water,			// �� Ÿ��
	type_Electric,		// ���� Ÿ��
	type_Psychic,		// ������ Ÿ��
	type_Grass,			// Ǯ Ÿ��
	type_Earth,			// �� Ÿ��
	type_Fly,			// ���� Ÿ��
	type_Ghost,			// ��Ʈ Ÿ��
	type_Dragoon,		// �巡�� Ÿ��
	type_Dark,			// �� Ÿ��
	type_Fairy,			// �� Ÿ��
	type_Steel,			// ��ö Ÿ��
	type_Rock,			// ���� Ÿ��
	type_bug,			// ���� Ÿ��5j
	type_Sprattle,		// ���� Ÿ��
	type_Poison			// �� Ÿ��
};



struct skillInfo
{
	char* name;				// ��ų �̸�
	image image;			// ��ų �̹���
	RECT rc;			    // ��ų �ڽ� ����
	float x;				// ��ų x ��ǥ
	float y;				// ��ų y ��ǥ
	int count;				// ��ų ī��Ʈ
	int currentFramex;		// ��ų ������ 

};




class Skill : public gameNode
{
private :

	skillInfo _skill;
	

public:
	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	virtual void setSkillEffect(char* name, int x, int y);
	void skillEffectInfo();

	Skill();
	~Skill();
};

