#pragma once
#include "stdafx.h"
#include "Pokemon.h"
#include "aStar.h"

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

	int idx, idy;					
	int tileIndex;

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

class Stage;
class player;
class tile;
class enemy : public pokemon
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
	tagTempPokemon _pokemon;
	
	Stage* _stage;
	player* _pl;

	aStar* _ast;
	vector<tile> _vCloseList;


public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(tagImageName PokemonName, float x, float y, int level);
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
	inline pokemon getPokemonStatus() { return _pokemonStatus; }

	inline void setStageMemoryAdressLink(Stage* stage) { _stage = stage; }
	inline void setPlayerMemoryAdressLink(player* pl) { _pl = pl; }


	inline float getX() { return _pokemon.x; }
	inline float getY() { return _pokemon.y; }
	inline int getDirection() { return _pokemon.direction; }
};

