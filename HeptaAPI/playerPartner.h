#pragma once
#include "gameNode.h"
#include "pokemon.h"

enum PARTNER_DIRECTION
{
	PARTNER_BOTTOM,				//아래
	PARTNER_LEFT_BOTTOM,		//왼쪽 아래
	PARTNER_LEFT,				//왼쪽
	PARTNER_LEFT_TOP,			//왼쪽 위
	PARTNER_TOP,				//위
	PARTNER_RIGHT_TOP,			//오른쪽 위
	PARTNER_RIGHT,				//오른쪽
	PARTNER_RIGHT_BOTTOM,		//오른쪽 아래
	PARTNER_DIRECTION_END
};
enum PARTNER_STATE
{
	PARTNER_IDLE,				//기본상태
	PARTNER_MOVE,				//움직임
	PARTNER_ATTACK,				//공격
	PARTNER_SPECIAL_ATTACK_1,	//스페셜 공격 1
	PARTNER_SPECIAL_ATTACK_2,	//스페셜 공격 2
	PARTNER_HURT,				//피격
	PARTNER_DIE,				//죽었을때?
	PARTNER_STATE_END
};

struct tagPlayerPartner
{
	PARTNER_DIRECTION direction;	//방향
	PARTNER_STATE state;			//상태
	RECT imageRc;					//이미지 덮는 렉트
	RECT rc;						//실제 적용될 렉트 ( 타격 ? 같은거)
	float startX, startY;			//시작점 x, y ( 던전이동에 필요함 )
	float x, y;						//중점 x, y
	float angle;					//앵글
	int idx, idy;					//몇번째 x, y타일에 있는지 인덱스 
	int tileIndex;					//몇번째 타일에 있는지 인덱스
	int currentHp, maxHp;			//현재 체력 , 맥스 체력
	int atk;						//공격력
	int def;						//방어력
	int specialAtk;					//특수공격
	int specialDef;					//특수방어력
};

class player;
class Stage;
class enemyManager;

class playerPartner : public gameNode
{
private: // ## 플레이어 ##
	player* _player;

private: // ## 에너미 정보 ##
	enemyManager* _em;

private: // ## 포켓몬 정보 ##
	pokemon* _partnerStatus;

private: // ## 스테이지 정보 ##
	Stage* _stage;
	
private: // ## 파트너 ## 
	tagPlayerPartner _partner;

private:
	string tempNameIdle;
	string tempNameMove;
	string tempNameAttack;
	string tempNameSpecialAttack;
	string tempNameHurt;

private: // ## 프레임 업뎃 변수 ##
	//기본
	SHORT _idleCount;
	SHORT _idleFrameX, _idleFrameY;

	//움직임
	SHORT _moveCount;
	SHORT _moveFrameX, _moveFrameY;

	//공격
	SHORT _attackCount;
	SHORT _attackFrameX, _attackFrameY;

	//스페셜공격
	SHORT _S_AttackCount;
	SHORT _S_AttackFrameX, _S_AttackFrameY;

	//스페셜공격2
	SHORT _S_AttackCount_2;
	SHORT _S_AttackFrameX_2, _S_AttackFrameY_2;

	//피격
	SHORT _hurtCount;
	SHORT _hurtFrameX, _hurtFrameY;

public:
	playerPartner();
	~playerPartner();

	virtual HRESULT init();
	virtual HRESULT init(string charName);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void valueInit();
	virtual void frameUpdate();
	virtual void draw();
	virtual void partnerTownMove();
	virtual void partnerDgMove();
	
	virtual void townMove();
	virtual void dgMove();

	virtual void setPostion(float startX, float startY);

	void setPlayerMemAdressLink(player* player) { _player = player; }
	void setStageMemAdressLink(Stage* stage) { _stage = stage; }
	void setEmMemAdressLink(enemyManager* em) { _em = em; }
};

