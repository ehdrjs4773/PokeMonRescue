#pragma once
#include "gameNode.h"

#define PLAYER_SPEED 2

//�÷��̾� ����
enum PLAYER_DIRECTION
{
	PLAYER_BOTTOM,				//�Ʒ�
	PLAYER_LEFT_BOTTOM,			//���� �Ʒ�
	PLAYER_LEFT,				//����
	PLAYER_LEFT_TOP,			//���� ��
	PLAYER_TOP,					//��
	PLAYER_RIGHT_TOP,			//������ ��
	PLAYER_RIGHT,				//������
	PLAYER_RIGHT_BOTTOM,		//������ �Ʒ�
	PLAYER_DIRECTION_END
};

//�÷��̾� ����
enum PLAYER_STATE
{
	PLAYER_IDLE,				//�⺻����
	PLAYER_MOVE,				//������
	PLAYER_ATTACK,				//����
	PLAYER_SPECIAL_ATTACK_1,	//����� ���� 1
	PLAYER_SPECIAL_ATTACK_2,	//����� ���� 2
	PLAYER_HURT,				//�ǰ�
	PLAYER_DIE,					//�׾�����?
	PLAYER_STATE_END
};

//�÷��̾� �⺻������ ���� ����ü
struct tagPlayer
{
	PLAYER_DIRECTION direction;		//����
	PLAYER_STATE state;				//����
	RECT rc;						//��Ʈ
	RECT hitbox;					//���߿� �� ��Ʈ�ڽ�
	animation* animation;			//�ִϷ����� �� ��
	float x, y;						//���� x, y
	float speed;					//���ǵ�
	float angle;					//�ޱ�
};

class player : public gameNode
{
private:
	tagPlayer _player;		//�÷��̾�

	string tempNameIdle;
	string tempNameMove;
	string tempNameAttack;

private: // ## �Ұ� ##


private: // ## ������ ���� ������ ## 
	SHORT _bottomIdleCount;								//���� �������¿� �� ī��Ʈ
	SHORT _bottomIdleFrameX , _bottomIdleFrameY;		//        ""        �ε���
	SHORT _bottomMoveCount;								//���� ������¿� �� ī��Ʈ
	SHORT _bottomMoveFrameX , _bottomMoveFrameY;		//		  ""		�ε���
	SHORT _bottomAttackCount;							//���� ���ݻ��¿� �� ī��Ʈ
	SHORT _bottomAttackFrameX, _bottomAttackFrameY;		//		  ""		�ε���

	SHORT _leftIdleCount;								//���� �������¿� �� ī��Ʈ
	SHORT _leftIdleFrameX, _leftIdleFrameY;				//		  ""        �ε���
	SHORT _leftMoveCount;								//���� ������¿� �� ī��Ʈ
	SHORT _leftMoveFrameX, _leftMoveFrameY;				//		  ""		�ε���
	SHORT _leftAttackCount;								//���� ���ݻ��¿� �� ī��Ʈ
	SHORT _leftAttackFrameX, _leftAttackFrameY;			//		  ""		�ε���

	SHORT _rightIdleCount;								//������ �������¿� �� ī��Ʈ
	SHORT _rightIdleFrameX, _rightIdleFrameY;			//        ""        �ε���
	SHORT _rightMoveCount;								//������ ������¿� �� ī��Ʈ
	SHORT _rightMoveFrameX, _rightMoveFrameY;			//		  ""		�ε���
	SHORT _rightAttackCount;							//������ ���ݻ��¿� �� ī��Ʈ
	SHORT _rightAttackFrameX, _rightAttackFrameY;		//		  ""		�ε���

	SHORT _topIdleCount;								//�� �������¿� �� ī��Ʈ
	SHORT _topIdleFrameX, _topIdleFrameY;				//        ""        �ε���
	SHORT _topMoveCount;								//�� ������¿� �� ī��Ʈ
	SHORT _topMoveFrameX, _topMoveFrameY;				//		  ""		�ε���
	SHORT _topAttackCount;								//�� ���ݻ��¿� �� ī��Ʈ
	SHORT _topAttackFrameX, _topAttackFrameY;			//		  ""		�ε���

	SHORT _leftBottomIdleCount;									//���ʾƷ� �������¿� �� ī��Ʈ
	SHORT _leftBottomIdleFrameX, _leftBottomIdleFrameY;			//		  ""        �ε���
	SHORT _leftBottomMoveCount;									//���ʾƷ� ������¿� �� ī��Ʈ
	SHORT _leftBottomMoveFrameX, _leftBottomMoveFrameY;			//		  ""		�ε���
	SHORT _leftBottomAttackCount;								//���ʾƷ� ���ݻ��¿� �� ī��Ʈ
	SHORT _leftBottomAttackFrameX, _leftBottomAttackFrameY;		//		  ""		�ε���

	SHORT _leftTopIdleCount;									//������ �������¿� �� ī��Ʈ
	SHORT _leftTopIdleFrameX, _leftTopIdleFrameY;				//		  ""        �ε���
	SHORT _leftTopMoveCount;									//������ ������¿� �� ī��Ʈ
	SHORT _leftTopMoveFrameX, _leftTopMoveFrameY;				//		  ""		�ε���
	SHORT _leftTopAttackCount;									//������ ���ݻ��¿� �� ī��Ʈ
	SHORT _leftTopAttackFrameX, _leftTopAttackFrameY;			//		  ""		�ε���

	SHORT _rightTopIdleCount;									//�������� �������¿� �� ī��Ʈ
	SHORT _rightTopIdleFrameX, _rightTopIdleFrameY;				//		  ""        �ε���
	SHORT _rightTopMoveCount;									//�������� ������¿� �� ī��Ʈ
	SHORT _rightTopMoveFrameX, _rightTopMoveFrameY;				//		  ""		�ε���
	SHORT _rightTopAttackCount;									//�������� ���ݻ��¿� �� ī��Ʈ
	SHORT _rightTopAttackFrameX, _rightTopAttackFrameY;			//		  ""		�ε���

	SHORT _rightBottomIdleCount;								//�������� �������¿� �� ī��Ʈ
	SHORT _rightBottomIdleFrameX, _rightBottomIdleFrameY;		//		  ""        �ε���
	SHORT _rightBottomMoveCount;								//�������� ������¿� �� ī��Ʈ
	SHORT _rightBottomMoveFrameX, _rightBottomMoveFrameY;		//		  ""		�ε���
	SHORT _rightBottomAttackCount;								//�������� ���ݻ��¿� �� ī��Ʈ
	SHORT _rightBottomAttackFrameX, _rightBottomAttackFrameY;	//		  ""		�ε���

public:
	player();
	~player();

	virtual HRESULT init();
	//Ű�� , ������ X, Y;
	virtual HRESULT init(string charName, float startX , float startY);		//�����ӷ��� ¯¯��
	virtual void release();
	virtual void update();
	virtual void render();

	void townMove();		//�������� �̵�
	void dungeonMove();		//�������� �̵�

	
	void playerMove();		//�������� �ʹ��� ���� ������ 
	void FrameUpdate();		//������ �������°͵� �ʹ� �� ���� ������
	void valueInit();		//���� �ʱ�ȭ�� ��
	void draw();			//�׸��°͵� ��
	void correction();		//�����۾�

	//������
	PLAYER_DIRECTION getPlayerDirection() { return _player.direction; }		//����
	PLAYER_STATE getPlayerState() { return _player.state; }					//����
};

