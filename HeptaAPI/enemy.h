#pragma once
#include "stdafx.h"
#include "gameNode.h"
#include "Pokemon.h"
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
	float speed;

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
	//������ �������ͽ��� ���� ���� enemyManager+imageInit�κп��� �ʱ�ȭ�� �� ����
	char* pokemonName;
	char* idleImage;
	char* moveImage;
	char* attackImage;
	char* hurtImage;
};


class enemy : public gameNode
{

private:
	//������ �ε��� 4������ ��������
	int _idleIndex;
	int _moveIndex;
	int _atkIndex;
	int _hurtIndex;
	int _count;

	//�ε��� ����� �������� 4���� ���������� 2���� �ᱹ �Ⱦ����ٰ� ����
	bool _idleReverse;
	bool _atkReverse;
	bool _hurtReverse;
	bool _moveReverse;
	bool _isMove;

	//Ÿ�ϴ��� �̵��� ���� �̵��Ÿ��� �ӽ� ���ǵ�!
	float _distance;
	float _tempSpeed;

private:
	//�̰� �θ�Ŭ�������� ����� �� �� ������ �; �̷���!!!
	pokemon _pokemonStatus;

protected:
	//�������� ������Ƽ�� ����Ŭ�������� �ڽŲ� ������ �ǵ��ϼ� �ֵ���
	//������ ���� �ʹ� ������� �ڽ�Ŭ�������� �������� �ʴ� Ŭ������ ��κ��ε� ��� ���� �����־�����
	//�������� private�� �°��� �غ� ����!!!
	tagTempPokemon _pokemon;

public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(tagImageName PokemonName, float x, float y, int level, ELEMENT elelment);
	void release();
	void update();
	void render();

	void setState();
	void enemyAttackMotion();
	void enemyHurtMotion();


	void enemyAngleSetting();
	void enemyTileMove();
	void enemyMoveSign();



	inline tagTempPokemon getPokemon() { return _pokemon; }
	inline float getX() { return _pokemon.x; }
	inline float getY() { return _pokemon.y; }
	inline int getDirection() { return _pokemon.direction; }
};

