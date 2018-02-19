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

protected:
	//귀차느니 프로텍티로 아이클래스들이 자신꺼 스스로 건들일수 있도록
	//과거의 나는 너무 어리석었다 자식클래스에서 쓰이지도 않는 클래스가 대부분인데 어디서 감히 써져있었을까
	//수요일쯤 private로 승격할 준비 하자!!!
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

