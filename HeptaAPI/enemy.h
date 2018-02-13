#pragma once
#include "stdafx.h"
#include "gameNode.h";
//�ӽ����ϸ�

struct tagTempPokemon
{
	image* idleImage;
	image* moveImage;
	image* atkImage;
	image* hurtImage;

	char* idleImageName;
	char* moveImageName;
	char* atkImageName;
	char* hurtImageName;

	float x;
	float y;
	int direction;
	int state;
};


//���� ���� �ٶ󺸴� ����
enum direction
{
	UP,
	LEFTUP,
	LEFT,
	LEFTDOWN,
	DOWN,
	RIGHTDOWN,
	RIGHT,
	RIGHTUP,
};

enum state
{
	STATE_IDLE,
	STATE_ATTACK,
	STATE_MOVE,
	STATE_HURT
};

//�̹����� �̸��� ����üȭ�� �Ͽ� �θ�Ŭ������ �Ѱܼ� ���ε��� �� �ʿ� ���� �Ѱ��� �Լ��� ������ ���� ���Ǽ� ����ü
struct tagImageName
{
	char* idleImage;
	char* moveImage;
	char* attackImage;
	char* hurtImage;
};


class enemy : public gameNode
{
private:
	int _idleIndex;
	int _moveIndex;
	int _atkIndex;
	int _hurtIndex;
	int _count;

	bool _idleReverse;
	bool _atkReverse;
	bool _hurtReverse;
	bool _moveReverse;


	//������ �ѹ��� ����Ǿ�� �ϱ� ������
	bool _isOnceAttack;
	//�翬 Ÿ�ݵ� �ѹ��� ����
	bool _isOnceHurt;


protected:
	//�������� ������Ƽ�� ����Ŭ�������� �ڽŲ� ������ �ǵ��ϼ� �ֵ���
	tagTempPokemon _pokemon;


public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(tagImageName PokemonName, float x, float y);
	void release();
	void update();
	void render();


	void keyControl();
	void setState();
	void enemyMove();


	void enemyAttackMotion();
	void enemyHurtMotion();

	void enemyAngleSetting();
	tagTempPokemon getPokemon() { return _pokemon; }
		
};

