#pragma once
#include "stdafx.h"
#include "gameNode.h";
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


	//공격은 한번만 진행되어야 하기 때문에
	bool _isOnceAttack;
	//당연 타격도 한번만 진행
	bool _isOnceHurt;


protected:
	//귀차느니 프로텍티로 아이클래스들이 자신꺼 스스로 건들일수 있도록
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

