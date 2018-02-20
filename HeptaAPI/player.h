#pragma once
#include "gameNode.h"
#include "playerPartner.h"
#include "pokemon.h"

#define PLAYER_TOWN_SPEED 5
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
	PLAYER_HURT,				//피격
	PLAYER_DIE,					//죽었을때?
	PLAYER_STATE_END
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
};

class Stage;
class item;

class player : public gameNode
{
private: // ## 맵 정보 ##
	Stage* _stage;

private: // ## 포켓몬 정보 ##
	pokemon* _playerStatus;

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

private: // ## 불값 ##
	bool _isAttack;		//공격햇늬?
	bool _onceMove;		//던전에서는 한번만 움직이게

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
	// 아직안씀
	bool _speedUp;

private: // ## 프레임 돌릴 변수들 ## 
	SHORT _bottomIdleCount;											//바텀 정지상태에 쓸 카운트
	SHORT _bottomIdleFrameX, _bottomIdleFrameY;					//        ""        인덱스
	SHORT _bottomMoveCount;											//바텀 무브상태에 쓸 카운트
	SHORT _bottomMoveFrameX, _bottomMoveFrameY;					//		  ""		인덱스
	SHORT _bottomAttackCount;										//바텀 공격상태에 쓸 카운트
	SHORT _bottomAttackFrameX, _bottomAttackFrameY;					//		  ""		인덱스
	SHORT _bottomSpecialAttackCount;								//바텀 스페셜공격 상태에 쓸 카운트
	SHORT _bottomSpecialAttackFrameX, _bottomSpecialAttackFrameY;	//		  ""		인덱스
	SHORT _bottomHurtCount;											//바텀 피격 상태에 쓸 카운트
	SHORT _bottomHurtFrameX, _bottomHurtFrameY;						//		  ""		인덱스

	SHORT _leftIdleCount;										//왼쪽 정지상태에 쓸 카운트
	SHORT _leftIdleFrameX, _leftIdleFrameY;						//		  ""        인덱스
	SHORT _leftMoveCount;										//왼쪽 무브상태에 쓸 카운트
	SHORT _leftMoveFrameX, _leftMoveFrameY;						//		  ""		인덱스
	SHORT _leftAttackCount;										//왼쪽 공격상태에 쓸 카운트
	SHORT _leftAttackFrameX, _leftAttackFrameY;					//		  ""		인덱스
	SHORT _leftSpecialAttackCount;								//왼쪽 스페셜공격 상태에 쓸 카운트
	SHORT _leftSpecialAttackFrameX, _leftSpecialAttackFrameY;	//		  ""		인덱스
	SHORT _leftHurtCount;										//왼쪽 피격 상태에 쓸 카운트
	SHORT _leftHurtFrameX, _leftHurtFrameY;						//		  ""		인덱스

	SHORT _rightIdleCount;										//오른쪽 정지상태에 쓸 카운트
	SHORT _rightIdleFrameX, _rightIdleFrameY;					//        ""        인덱스
	SHORT _rightMoveCount;										//오른쪽 무브상태에 쓸 카운트
	SHORT _rightMoveFrameX, _rightMoveFrameY;					//		  ""		인덱스
	SHORT _rightAttackCount;									//오른쪽 공격상태에 쓸 카운트
	SHORT _rightAttackFrameX, _rightAttackFrameY;				//		  ""		인덱스
	SHORT _rightSpecialAttackCount;								//오른쪽 스페셜공격 상태에 쓸 카운트
	SHORT _rightSpecialAttackFrameX, _rightSpecialAttackFrameY;	//		  ""		인덱스
	SHORT _rightHurtCount;										//오른쪽 피격 상태에 쓸 카운트
	SHORT _rightHurtFrameX, _rightHurtFrameY;					//		  ""		인덱스

	SHORT _topIdleCount;										//위 정지상태에 쓸 카운트
	SHORT _topIdleFrameX, _topIdleFrameY;						//        ""        인덱스
	SHORT _topMoveCount;										//위 무브상태에 쓸 카운트
	SHORT _topMoveFrameX, _topMoveFrameY;						//		  ""		인덱스
	SHORT _topAttackCount;										//위 공격상태에 쓸 카운트
	SHORT _topAttackFrameX, _topAttackFrameY;					//		  ""		인덱스
	SHORT _topSpecialAttackCount;								//위 스페셜공격 상태에 쓸 카운트
	SHORT _topSpecialAttackFrameX, _topSpecialAttackFrameY;		//		  ""		인덱스
	SHORT _topHurtCount;										//위 피격 상태에 쓸 카운트
	SHORT _topHurtFrameX, _topHurtFrameY;						//		  ""		인덱스

	SHORT _leftBottomIdleCount;												//왼쪽아래 정지상태에 쓸 카운트
	SHORT _leftBottomIdleFrameX, _leftBottomIdleFrameY;						//		  ""        인덱스
	SHORT _leftBottomMoveCount;												//왼쪽아래 무브상태에 쓸 카운트
	SHORT _leftBottomMoveFrameX, _leftBottomMoveFrameY;						//		  ""		인덱스
	SHORT _leftBottomAttackCount;											//왼쪽아래 공격상태에 쓸 카운트
	SHORT _leftBottomAttackFrameX, _leftBottomAttackFrameY;					//		  ""		인덱스
	SHORT _leftBottomSpecialAttackCount;									//왼쪽아래 스페셜공격 상태에 쓸 카운트
	SHORT _leftBottomSpecialAttackFrameX, _leftBottomSpecialAttackFrameY;	//		  ""		인덱스
	SHORT _leftBottomHurtCount;												//왼쪽아래 피격 상태에 쓸 카운트
	SHORT _leftBottomHurtFrameX, _leftBottomHurtFrameY;						//		  ""		인덱스

	SHORT _leftTopIdleCount;											//왼쪽위 정지상태에 쓸 카운트
	SHORT _leftTopIdleFrameX, _leftTopIdleFrameY;						//		  ""        인덱스
	SHORT _leftTopMoveCount;											//왼쪽위 무브상태에 쓸 카운트
	SHORT _leftTopMoveFrameX, _leftTopMoveFrameY;						//		  ""		인덱스
	SHORT _leftTopAttackCount;											//왼쪽위 공격상태에 쓸 카운트
	SHORT _leftTopAttackFrameX, _leftTopAttackFrameY;					//		  ""		인덱스
	SHORT _leftTopSpecialAttackCount;									//왼쪽위 스페셜공격 상태에 쓸 카운트
	SHORT _leftTopSpecialAttackFrameX, _leftTopSpecialAttackFrameY;		//		  ""		인덱스
	SHORT _leftTopHurtCount;											//왼쪽위 피격 상태에 쓸 카운트
	SHORT _leftTopHurtFrameX, _leftTopHurtFrameY;						//		  ""		인덱스

	SHORT _rightTopIdleCount;											//오른쪽위 정지상태에 쓸 카운트
	SHORT _rightTopIdleFrameX, _rightTopIdleFrameY;						//		  ""        인덱스
	SHORT _rightTopMoveCount;											//오른쪽위 무브상태에 쓸 카운트
	SHORT _rightTopMoveFrameX, _rightTopMoveFrameY;						//		  ""		인덱스
	SHORT _rightTopAttackCount;											//오른쪽위 공격상태에 쓸 카운트
	SHORT _rightTopAttackFrameX, _rightTopAttackFrameY;					//		  ""		인덱스
	SHORT _rightTopSpecialAttackCount;									//오른쪽위 스페셜공격 상태에 쓸 카운트
	SHORT _rightTopSpecialAttackFrameX, _rightTopSpecialAttackFrameY;	//		  ""		인덱스
	SHORT _rightTopHurtCount;											//오른쪽위 피격 상태에 쓸 카운트
	SHORT _rightTopHurtFrameX, _rightTopHurtFrameY;						//		  ""		인덱스

	SHORT _rightBottomIdleCount;											//오른쪽아래 정지상태에 쓸 카운트
	SHORT _rightBottomIdleFrameX, _rightBottomIdleFrameY;					//		  ""        인덱스
	SHORT _rightBottomMoveCount;											//오른쪽아래 무브상태에 쓸 카운트
	SHORT _rightBottomMoveFrameX, _rightBottomMoveFrameY;					//		  ""		인덱스
	SHORT _rightBottomAttackCount;											//오른쪽아래 공격상태에 쓸 카운트
	SHORT _rightBottomAttackFrameX, _rightBottomAttackFrameY;				//		  ""		인덱스
	SHORT _rightBottomSpecialAttackCount;									//오른쪽아래 스페셜공격 상태에 쓸 카운트
	SHORT _rightBottomSpecialAttackFrameX, _rightBottomSpecialAttackFrameY;	//		  ""		인덱스
	SHORT _rightBottomHurtCount;											//오른쪽아래 피격 상태에 쓸 카운트
	SHORT _rightBottomHurtFrameX, _rightBottomHurtFrameY;					//		  ""		인덱스

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

	void addPartner(pokemon* p);	//파트너 추가 함수

	//접근자
	inline PLAYER_DIRECTION getPlayerDirection() { return (PLAYER_DIRECTION)_player.direction; }		//방향
	inline PLAYER_STATE getPlayerState() { return (PLAYER_STATE)_player.state; }						//상태
	inline RECT getRect() { return _player.rc; }									//렉트
	inline float getPlayerAngle() { return _player.angle; }							//앵글값
	inline float getX() { return _player.x; }										//플레이어 센터 X
	inline float getY() { return _player.y; }										//플레이어 센터 Y

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

	//설정자																			
	void setStageMemAdressLink(Stage* stage) { _stage = stage; }					//스테이지

	void setX(float x) { _player.x = x; }											//X좌표 설정
	void setY(float y) { _player.y = y; }											//Y좌표 설정

	void setAddMoney(int money) { _player.money = money; }							//돈

	inline int getDungeonNum() { return _player.dgNum; }							//던전넘버 겟
	void setDungeonNum(int dgNum) { _player.dgNum = dgNum; }						//던전넘버 셋

	void setPosition(float startX, float startY);									//좌표설정
};

