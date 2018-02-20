#pragma once
#include "gameNode.h"

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

class playerPartner : public gameNode
{
private: // ## 플레이어 ##
	player* _player;

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
	SHORT _bottomIdleCount;											//바텀 정지상태에 쓸 카운트
	SHORT _bottomIdleFrameX, _bottomIdleFrameY;						//        ""        인덱스
	SHORT _bottomMoveCount;											//바텀 무브상태에 쓸 카운트
	SHORT _bottomMoveFrameX, _bottomMoveFrameY;						//		  ""		인덱스
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
};

