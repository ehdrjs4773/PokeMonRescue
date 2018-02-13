#pragma once
#include "gameNode.h"

#define PLAYER_SPEED 2

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
	RECT rc;						//렉트
	RECT hitbox;					//나중에 쓸 히트박스
	animation* animation;			//애니랜더에 쓸 거
	float x, y;						//중점 x, y
	float speed;					//스피드
	float angle;					//앵글
};

class player : public gameNode
{
private:
	tagPlayer _player;		//플레이어

	string tempNameIdle;
	string tempNameMove;
	string tempNameAttack;

private: // ## 불값 ##


private: // ## 프레임 돌릴 변수들 ## 
	SHORT _bottomIdleCount;								//바텀 정지상태에 쓸 카운트
	SHORT _bottomIdleFrameX , _bottomIdleFrameY;		//        ""        인덱스
	SHORT _bottomMoveCount;								//바텀 무브상태에 쓸 카운트
	SHORT _bottomMoveFrameX , _bottomMoveFrameY;		//		  ""		인덱스
	SHORT _bottomAttackCount;							//바텀 공격상태에 쓸 카운트
	SHORT _bottomAttackFrameX, _bottomAttackFrameY;		//		  ""		인덱스

	SHORT _leftIdleCount;								//왼쪽 정지상태에 쓸 카운트
	SHORT _leftIdleFrameX, _leftIdleFrameY;				//		  ""        인덱스
	SHORT _leftMoveCount;								//왼쪽 무브상태에 쓸 카운트
	SHORT _leftMoveFrameX, _leftMoveFrameY;				//		  ""		인덱스
	SHORT _leftAttackCount;								//왼쪽 공격상태에 쓸 카운트
	SHORT _leftAttackFrameX, _leftAttackFrameY;			//		  ""		인덱스

	SHORT _rightIdleCount;								//오른쪽 정지상태에 쓸 카운트
	SHORT _rightIdleFrameX, _rightIdleFrameY;			//        ""        인덱스
	SHORT _rightMoveCount;								//오른쪽 무브상태에 쓸 카운트
	SHORT _rightMoveFrameX, _rightMoveFrameY;			//		  ""		인덱스
	SHORT _rightAttackCount;							//오른쪽 공격상태에 쓸 카운트
	SHORT _rightAttackFrameX, _rightAttackFrameY;		//		  ""		인덱스

	SHORT _topIdleCount;								//위 정지상태에 쓸 카운트
	SHORT _topIdleFrameX, _topIdleFrameY;				//        ""        인덱스
	SHORT _topMoveCount;								//위 무브상태에 쓸 카운트
	SHORT _topMoveFrameX, _topMoveFrameY;				//		  ""		인덱스
	SHORT _topAttackCount;								//위 공격상태에 쓸 카운트
	SHORT _topAttackFrameX, _topAttackFrameY;			//		  ""		인덱스

	SHORT _leftBottomIdleCount;									//왼쪽아래 정지상태에 쓸 카운트
	SHORT _leftBottomIdleFrameX, _leftBottomIdleFrameY;			//		  ""        인덱스
	SHORT _leftBottomMoveCount;									//왼쪽아래 무브상태에 쓸 카운트
	SHORT _leftBottomMoveFrameX, _leftBottomMoveFrameY;			//		  ""		인덱스
	SHORT _leftBottomAttackCount;								//왼쪽아래 공격상태에 쓸 카운트
	SHORT _leftBottomAttackFrameX, _leftBottomAttackFrameY;		//		  ""		인덱스

	SHORT _leftTopIdleCount;									//왼쪽위 정지상태에 쓸 카운트
	SHORT _leftTopIdleFrameX, _leftTopIdleFrameY;				//		  ""        인덱스
	SHORT _leftTopMoveCount;									//왼쪽위 무브상태에 쓸 카운트
	SHORT _leftTopMoveFrameX, _leftTopMoveFrameY;				//		  ""		인덱스
	SHORT _leftTopAttackCount;									//왼쪽위 공격상태에 쓸 카운트
	SHORT _leftTopAttackFrameX, _leftTopAttackFrameY;			//		  ""		인덱스

	SHORT _rightTopIdleCount;									//오른쪽위 정지상태에 쓸 카운트
	SHORT _rightTopIdleFrameX, _rightTopIdleFrameY;				//		  ""        인덱스
	SHORT _rightTopMoveCount;									//오른쪽위 무브상태에 쓸 카운트
	SHORT _rightTopMoveFrameX, _rightTopMoveFrameY;				//		  ""		인덱스
	SHORT _rightTopAttackCount;									//오른쪽위 공격상태에 쓸 카운트
	SHORT _rightTopAttackFrameX, _rightTopAttackFrameY;			//		  ""		인덱스

	SHORT _rightBottomIdleCount;								//오른쪽위 정지상태에 쓸 카운트
	SHORT _rightBottomIdleFrameX, _rightBottomIdleFrameY;		//		  ""        인덱스
	SHORT _rightBottomMoveCount;								//오른쪽위 무브상태에 쓸 카운트
	SHORT _rightBottomMoveFrameX, _rightBottomMoveFrameY;		//		  ""		인덱스
	SHORT _rightBottomAttackCount;								//오른쪽위 공격상태에 쓸 카운트
	SHORT _rightBottomAttackFrameX, _rightBottomAttackFrameY;	//		  ""		인덱스

public:
	player();
	~player();

	virtual HRESULT init();
	//키값 , 시작점 X, Y;
	virtual HRESULT init(string charName, float startX , float startY);		//프레임렌더 짱짱맨
	virtual void release();
	virtual void update();
	virtual void render();

	void townMove();		//마을에서 이동
	void dungeonMove();		//던전에서 이동

	
	void playerMove();		//무브패턴 너무길어서 따로 빼놓음 
	void FrameUpdate();		//프레임 돌리려는것도 너무 길어서 따로 빼놓음
	void valueInit();		//변수 초기화도 김
	void draw();			//그리는것도 김
	void correction();		//보정작업

	//접근자
	PLAYER_DIRECTION getPlayerDirection() { return _player.direction; }		//방향
	PLAYER_STATE getPlayerState() { return _player.state; }					//상태
};

