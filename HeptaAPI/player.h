#pragma once
#include "gameNode.h"
#include "playerPartner.h"
#include "pokemon.h"

#define PLAYER_TOWN_SPEED 3
#define PLAYER_DUNGEON_SPEED 1

//#define MOVE_FRAME_UPDATE_SPEED 5
//#define ATTACK_FRAME_UPDATE_SPEED 5
//#define S_ATTACK_FRAME_UPDATE_SPEED 10
//#define HURT_FRAME_UPDATE_SPEED 20

#define SPEED_UP_KEY 'Z'

#define MAX_PARTNER 3

//플레이어 방향
enum PLAYER_DIRECTION
{
	PLAYER_BOTTOM,				//아래
	PLAYER_LEFT_BOTTOM,			//왼쪽 아래
	PLAYER_LEFT,				//왼쪽
	PLAYER_LEFT_TOP,			//왼쪽 위
	PLAYER_TOP,					//위
	PLAYER_RIGHT_TOP,			//오른쪽 위
	PLAYER_RIGHT,				//오른쪽
	PLAYER_RIGHT_BOTTOM,		//오른쪽 아래
	PLAYER_DIRECTION_END
};

//플레이어 상태
enum PLAYER_STATE
{
	PLAYER_IDLE,				//기본상태
	PLAYER_MOVE,				//움직임
	PLAYER_ATTACK,				//공격
	PLAYER_SPECIAL_ATTACK_1,	//스페셜 공격 1
	PLAYER_SPECIAL_ATTACK_2,	//스페셜 공격 2
	PLAYER_SPECIAL_ATTACK_3,	//스페셜 공격 3
	PLAYER_SPECIAL_ATTACK_4,	//스페셜 공격 4
	PLAYER_HURT,				//피격
	PLAYER_DIE,					//죽었을때?
	PLAYER_STATE_END
};

enum PLAYER_EL
{
	PLAYER_NORMAL,		// 노말	0
	PLAYER_FIRE,		// 불	1
	PLAYER_WATER,		// 물	2
	PLAYER_ELECTRIC,	// 전기	3
	PLAYER_PLANT,		// 풀	4
	PLAYER_ICE,			// 얼음	5
	PLAYER_FIGHT,		// 격투	6
	PLAYER_POISON,		// 독	7
	PLAYER_EARTH,		// 땅	8
	PLAYER_WING,		// 비행	9
	PLAYER_ESPER,		// 에스퍼10
	PLAYER_INSECT,		// 곤충	11
	PLAYER_ROCK,		// 바위	12
	PLAYER_GHOST,		// 고스트13
	PLAYER_DRAGON,		// 드래곤14
	PLAYER_DARK,		// 악	15
	PLAYER_STEEL,		// 강철	16
	PLAYER_END
};

enum playerAction	//(임시)
{
	playerMove = 1,
	playerAttack,
	playerUseSkill,
	playerUseItem,
	playerEnd
};

//플레이어 기본정보들 담을 구조체
struct tagPlayer
{
	PLAYER_DIRECTION direction;		//방향
	PLAYER_STATE state;				//상태
	RECT imageRc;					//이미지 덮는 렉트
	RECT rc;						//실제 적용될 렉트 ( 타격 ? 같은거)
	float startX, startY;			//시작점 x, y ( 던전이동에 필요함 )
	float x, y;						//중점 x, y
	float angle;					//앵글
	int idx, idy;					//몇번째 x, y타일에 있는지 인덱스 
	int tileIndex;					//몇번째 타일에 있는지 인덱스
	int money;						//돈
	int dgNum;						//던전 번호
	float townSpeed;				//마을에서의 속도		
	float dgSpeed;					//던전에서의 속도
	int currentHp;
};

class Stage;
class item;
class enemyManager;
class Npc;
class battleScene;

class player : public gameNode
{
private:
	battleScene * _battle;

private: // ## 맵 정보 ##
	Stage* _stage;
	Npc* _town;

private: // ## 포켓몬 정보 ##
	pokemon* _playerStatus;
	playerAction _playerAction;		//(임시)

private: // ## 에너미 정보 ##
	enemyManager* _em;

private: // ## 파트너 정보 ##
	vector<playerPartner*> _vPartner;
	vector<playerPartner*>::iterator _viPartner;

private:
	tagPlayer _player;		//플레이어

	string tempNameIdle;
	string tempNameMove;
	string tempNameAttack;
	string tempNameSpecialAttack;
	string tempNameHurt;

	string tempNameEl;

private: // ## 불값 ##
	bool _isAttack;		//공격햇늬?
	bool _onceMove;		//던전에서는 한번만 움직이게
	bool _isHurt;		//피격상태늬?

	// 던전이동시 필요한 불값
	// 움직일 수 있니? ( 앞에 벽이 있니? )
	bool _isBottomMove;
	bool _isLeftBottomMove;
	bool _isLeftMove;
	bool _isLeftTopMove;
	bool _isTopMove;
	bool _isRightTopMove;
	bool _isRightMove;
	bool _isRightBottomMove;
	
	bool _isWallCrash;			//벽에 부딪혔니?

private: // ## 프레임 돌릴 변수들 ## 
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

	//스페셜공격3
	SHORT _S_AttackCount_3;
	SHORT _S_AttackFrameX_3, _S_AttackFrameY_3;

	//스페셜공격4
	SHORT _S_AttackCount_4;
	SHORT _S_AttackFrameX_4, _S_AttackFrameY_4;

	//피격
	SHORT _hurtCount;
	SHORT _hurtFrameX, _hurtFrameY;


public:
	player();
	~player();

	virtual HRESULT init();
	//키값 , 시작점 X, Y;
	virtual HRESULT init(string charName);
	virtual void release();
	virtual void update();
	virtual void render();

	void townMove();		//마을에서 이동
	void dungeonMove();		//던전에서 이동

	void playerTownMove();	//무브패턴 너무길어서 따로 빼놓음 
	void playerDgMove();
	void FrameUpdate();		//프레임 돌리려는것도 너무 길어서 따로 빼놓음
	void valueInit();		//변수 초기화도 김
	void dgMoveValueInit();	//던전 움직임 불값 초기화
	void draw();			//그리는것도 김
	void correction();		//보정작업
	void pixelCollision();	//픽셀충돌
	void tileCheak();		//타일검출
	void effects();

	//void addPartner(pokemon* p);	//파트너 추가 함수
	//void addPartner(string charName);	//파트너 추가 함수

	//접근자
	inline PLAYER_DIRECTION getPlayerDirection() { return (PLAYER_DIRECTION)_player.direction; }		//방향
	inline PLAYER_STATE getPlayerState() { return (PLAYER_STATE)_player.state; }						//상태
	inline RECT getRect() { return _player.rc; }									//렉트
	inline float getPlayerAngle() { return _player.angle; }							//앵글값
	inline float getX() { return _player.x; }										//플레이어 센터 X
	inline float getY() { return _player.y; }										//플레이어 센터 Y
	inline bool getIsAttack() { return _isAttack; }									//공격햇늬?

	inline int getPlayerTileIndexX() { return _player.idx; }						//인덱스 X
	inline int getPlayerTileIndexY() { return _player.idy; }						//인덱스 Y

	inline int getMoney() { return _player.money; }									//돈

	inline int getCurrentHP() { return _playerStatus->getCurrentHP(); }				//현재체력
	inline int getMaxHP() { return _playerStatus->getMaxHP(); }						//전체체력
	inline int getMaxExp() { return _playerStatus->getMaxEXP(); }					//전체경험치
	inline int getCurrentExp() { return _playerStatus->getCurrentEXP(); }			//현재경험치
	inline int getAtkDamage() { return _playerStatus->getAtk(); }					//공격력
	inline int getDef() { return _playerStatus->getDef(); }							//방어력
	inline int getSpecialAtk() { return _playerStatus->getSpecialATK(); }			//스페셜공격력
	inline int getSpecialDef() { return _playerStatus->getSpecialDef(); }			//스페셜방어력
	inline int getLevel() { return _playerStatus->getLevel(); }						//레벨

	inline playerAction getPlayerAction() { return _playerAction; }					//액션 이넘 (임시)

	inline pokemon* getStatus() { return _playerStatus; }							//포켓몬 정보

	//설정자																			
	void setStageMemAdressLink(Stage* stage) { _stage = stage; }					//스테이지
	void setEmMemAdressLink(enemyManager* em) { _em = em; }
	void setTownMapMemAdressLink(Npc* map) { _town = map; }
	void setBattleSceneMemory(battleScene* b) { _battle = b; }
	
	void setX(float x) { _player.x = x; }											//X좌표 설정
	void setY(float y) { _player.y = y; }											//Y좌표 설정

	void setCurrentHp(int hp) { _playerStatus->setCurrentHP(hp); }					//체력
	void setCurrentExp(int exp) { _playerStatus->setCurrentEXP(exp); }				//경험치
	void setAddMoney(int money) { _player.money = money; }							//돈

	inline int getDungeonNum() { return _player.dgNum; }							//던전넘버 겟
	void setDungeonNum(int dgNum) { _player.dgNum = dgNum; }						//던전넘버 셋

	void setPosition(float startX, float startY);									//좌표설정

	inline void setPlayerAction(playerAction playerAction) { _playerAction = playerAction; }//액션 이넘 (임시)
	
	//파트너 겟셋
	vector<playerPartner*> getVPartner() { return _vPartner;}
	vector<playerPartner*>::iterator getViPartner() { return _viPartner;}

};

