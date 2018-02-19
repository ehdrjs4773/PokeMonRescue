#pragma once
#include "gameNode.h"
#include "player.h"


class player;
class Stage;

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
	type_bug,			// ���� Ÿ��
	type_Sprattle,		// ���� Ÿ��
	type_Poison,			// �� Ÿ��
	type_End
};



struct skillInfo
{
	char* name;				// ��ų �̸�
	image* image;			// ��ų �̹���
	RECT rc;			    // ��ų �ڽ� ����
	float x;				// ��ų x ��ǥ
	float y;				// ��ų y ��ǥ
	int count;				// ��ų ī��Ʈ
	int currentFramex;		// ��ų ������ 
	type type;				// ��ų Ÿ��
	float damege;			// ��ų �����
};




class Skill : public gameNode
{
private :
	
	player* _player;
	Stage* _stage;
	skillInfo _skill;
	

public:
	
	virtual HRESULT init(char* name, int x, int y, type type);
	virtual void release();
	virtual void update();
	virtual void render();


	Skill();
	~Skill();

	void setStageMemoryAdressLink(Stage* stages) { _stage = stages; }
	void setPlayerMemoryAdressLink(player* plays) { _player = plays; }


};

