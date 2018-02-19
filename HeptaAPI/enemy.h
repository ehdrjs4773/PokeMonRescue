#pragma once
#include "stdafx.h"
#include "gameNode.h"
#include "Pokemon.h"
//임시포켓몬

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


//현재 상태 바라보는 방향
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


//이미지의 이름을 구조체화로 하여 부모클래스에 넘겨서 따로따로 할 필요 없이 한개의 함수로 끝내기 위한 편의성 구조체
struct tagImageName
{
	//맨위는 스테이터스에 사용될 네임 enemyManager+imageInit부분에서 초기화를 할 예정
	char* pokemonName;
	char* idleImage;
	char* moveImage;
	char* attackImage;
	char* hurtImage;
};


class enemy : public gameNode
{

private:
	//프레임 인덱스 4종류로 나눠놓고
	int _idleIndex;
	int _moveIndex;
	int _atkIndex;
	int _hurtIndex;
	int _count;

	//인덱스 상승을 뒤집어줄 4종류 나눠놨지만 2개는 결국 안쓰였다고 흑흑
	bool _idleReverse;
	bool _atkReverse;
	bool _hurtReverse;
	bool _moveReverse;
	bool _isMove;

	//타일단위 이동을 위한 이동거리와 임시 스피드!
	float _distance;
	float _tempSpeed;

private:
	//이건 부모클래스에서 충분히 할 수 있을듯 싶어서 이렇게!!!
	pokemon _pokemonStatus;
	tagTempPokemon _pokemon;
	
	Stage* _stage;
	player* _pl;



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
	inline pokemon getPokemonStatus() { return _pokemonStatus; }

	inline void setStageMemoryAdressLink(Stage* stage) { _stage = stage; }
	inline void setPlayerMemoryAdressLink(player* pl) { _pl = pl; }


	inline float getX() { return _pokemon.x; }
	inline float getY() { return _pokemon.y; }
	inline int getDirection() { return _pokemon.direction; }
};

