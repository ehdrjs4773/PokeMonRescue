#pragma once
#include "gameNode.h"

enum PARTNER_DIRECTION
{
	PARTNER_BOTTOM,				//�Ʒ�
	PARTNER_LEFT_BOTTOM,		//���� �Ʒ�
	PARTNER_LEFT,				//����
	PARTNER_LEFT_TOP,			//���� ��
	PARTNER_TOP,				//��
	PARTNER_RIGHT_TOP,			//������ ��
	PARTNER_RIGHT,				//������
	PARTNER_RIGHT_BOTTOM,		//������ �Ʒ�
	PARTNER_DIRECTION_END
};
enum PARTNER_STATE
{
	PARTNER_IDLE,				//�⺻����
	PARTNER_MOVE,				//������
	PARTNER_ATTACK,				//����
	PARTNER_SPECIAL_ATTACK_1,	//����� ���� 1
	PARTNER_SPECIAL_ATTACK_2,	//����� ���� 2
	PARTNER_HURT,				//�ǰ�
	PARTNER_DIE,				//�׾�����?
	PARTNER_STATE_END
};

struct tagPlayerPartner
{
	PARTNER_DIRECTION direction;	//����
	PARTNER_STATE state;			//����
	RECT imageRc;					//�̹��� ���� ��Ʈ
	RECT rc;						//���� ����� ��Ʈ ( Ÿ�� ? ������)
	float startX, startY;			//������ x, y ( �����̵��� �ʿ��� )
	float x, y;						//���� x, y
	float angle;					//�ޱ�
	int idx, idy;					//���° x, yŸ�Ͽ� �ִ��� �ε��� 
	int tileIndex;					//���° Ÿ�Ͽ� �ִ��� �ε���
	int currentHp, maxHp;			//���� ü�� , �ƽ� ü��
	int atk;						//���ݷ�
	int def;						//����
	int specialAtk;					//Ư������
	int specialDef;					//Ư������
};

class player;
class Stage;

class playerPartner : public gameNode
{
private: // ## �÷��̾� ##
	player* _player;

private: // ## �������� ���� ##
	Stage* _stage;
	
private: // ## ��Ʈ�� ## 
	tagPlayerPartner _partner;

private:
	string tempNameIdle;
	string tempNameMove;
	string tempNameAttack;
	string tempNameSpecialAttack;
	string tempNameHurt;

private: // ## ������ ���� ���� ##
	SHORT _bottomIdleCount;											//���� �������¿� �� ī��Ʈ
	SHORT _bottomIdleFrameX, _bottomIdleFrameY;						//        ""        �ε���
	SHORT _bottomMoveCount;											//���� ������¿� �� ī��Ʈ
	SHORT _bottomMoveFrameX, _bottomMoveFrameY;						//		  ""		�ε���
	SHORT _bottomAttackCount;										//���� ���ݻ��¿� �� ī��Ʈ
	SHORT _bottomAttackFrameX, _bottomAttackFrameY;					//		  ""		�ε���
	SHORT _bottomSpecialAttackCount;								//���� ����Ȱ��� ���¿� �� ī��Ʈ
	SHORT _bottomSpecialAttackFrameX, _bottomSpecialAttackFrameY;	//		  ""		�ε���
	SHORT _bottomHurtCount;											//���� �ǰ� ���¿� �� ī��Ʈ
	SHORT _bottomHurtFrameX, _bottomHurtFrameY;						//		  ""		�ε���

	SHORT _leftIdleCount;										//���� �������¿� �� ī��Ʈ
	SHORT _leftIdleFrameX, _leftIdleFrameY;						//		  ""        �ε���
	SHORT _leftMoveCount;										//���� ������¿� �� ī��Ʈ
	SHORT _leftMoveFrameX, _leftMoveFrameY;						//		  ""		�ε���
	SHORT _leftAttackCount;										//���� ���ݻ��¿� �� ī��Ʈ
	SHORT _leftAttackFrameX, _leftAttackFrameY;					//		  ""		�ε���
	SHORT _leftSpecialAttackCount;								//���� ����Ȱ��� ���¿� �� ī��Ʈ
	SHORT _leftSpecialAttackFrameX, _leftSpecialAttackFrameY;	//		  ""		�ε���
	SHORT _leftHurtCount;										//���� �ǰ� ���¿� �� ī��Ʈ
	SHORT _leftHurtFrameX, _leftHurtFrameY;						//		  ""		�ε���

	SHORT _rightIdleCount;										//������ �������¿� �� ī��Ʈ
	SHORT _rightIdleFrameX, _rightIdleFrameY;					//        ""        �ε���
	SHORT _rightMoveCount;										//������ ������¿� �� ī��Ʈ
	SHORT _rightMoveFrameX, _rightMoveFrameY;					//		  ""		�ε���
	SHORT _rightAttackCount;									//������ ���ݻ��¿� �� ī��Ʈ
	SHORT _rightAttackFrameX, _rightAttackFrameY;				//		  ""		�ε���
	SHORT _rightSpecialAttackCount;								//������ ����Ȱ��� ���¿� �� ī��Ʈ
	SHORT _rightSpecialAttackFrameX, _rightSpecialAttackFrameY;	//		  ""		�ε���
	SHORT _rightHurtCount;										//������ �ǰ� ���¿� �� ī��Ʈ
	SHORT _rightHurtFrameX, _rightHurtFrameY;					//		  ""		�ε���

	SHORT _topIdleCount;										//�� �������¿� �� ī��Ʈ
	SHORT _topIdleFrameX, _topIdleFrameY;						//        ""        �ε���
	SHORT _topMoveCount;										//�� ������¿� �� ī��Ʈ
	SHORT _topMoveFrameX, _topMoveFrameY;						//		  ""		�ε���
	SHORT _topAttackCount;										//�� ���ݻ��¿� �� ī��Ʈ
	SHORT _topAttackFrameX, _topAttackFrameY;					//		  ""		�ε���
	SHORT _topSpecialAttackCount;								//�� ����Ȱ��� ���¿� �� ī��Ʈ
	SHORT _topSpecialAttackFrameX, _topSpecialAttackFrameY;		//		  ""		�ε���
	SHORT _topHurtCount;										//�� �ǰ� ���¿� �� ī��Ʈ
	SHORT _topHurtFrameX, _topHurtFrameY;						//		  ""		�ε���

	SHORT _leftBottomIdleCount;												//���ʾƷ� �������¿� �� ī��Ʈ
	SHORT _leftBottomIdleFrameX, _leftBottomIdleFrameY;						//		  ""        �ε���
	SHORT _leftBottomMoveCount;												//���ʾƷ� ������¿� �� ī��Ʈ
	SHORT _leftBottomMoveFrameX, _leftBottomMoveFrameY;						//		  ""		�ε���
	SHORT _leftBottomAttackCount;											//���ʾƷ� ���ݻ��¿� �� ī��Ʈ
	SHORT _leftBottomAttackFrameX, _leftBottomAttackFrameY;					//		  ""		�ε���
	SHORT _leftBottomSpecialAttackCount;									//���ʾƷ� ����Ȱ��� ���¿� �� ī��Ʈ
	SHORT _leftBottomSpecialAttackFrameX, _leftBottomSpecialAttackFrameY;	//		  ""		�ε���
	SHORT _leftBottomHurtCount;												//���ʾƷ� �ǰ� ���¿� �� ī��Ʈ
	SHORT _leftBottomHurtFrameX, _leftBottomHurtFrameY;						//		  ""		�ε���

	SHORT _leftTopIdleCount;											//������ �������¿� �� ī��Ʈ
	SHORT _leftTopIdleFrameX, _leftTopIdleFrameY;						//		  ""        �ε���
	SHORT _leftTopMoveCount;											//������ ������¿� �� ī��Ʈ
	SHORT _leftTopMoveFrameX, _leftTopMoveFrameY;						//		  ""		�ε���
	SHORT _leftTopAttackCount;											//������ ���ݻ��¿� �� ī��Ʈ
	SHORT _leftTopAttackFrameX, _leftTopAttackFrameY;					//		  ""		�ε���
	SHORT _leftTopSpecialAttackCount;									//������ ����Ȱ��� ���¿� �� ī��Ʈ
	SHORT _leftTopSpecialAttackFrameX, _leftTopSpecialAttackFrameY;		//		  ""		�ε���
	SHORT _leftTopHurtCount;											//������ �ǰ� ���¿� �� ī��Ʈ
	SHORT _leftTopHurtFrameX, _leftTopHurtFrameY;						//		  ""		�ε���

	SHORT _rightTopIdleCount;											//�������� �������¿� �� ī��Ʈ
	SHORT _rightTopIdleFrameX, _rightTopIdleFrameY;						//		  ""        �ε���
	SHORT _rightTopMoveCount;											//�������� ������¿� �� ī��Ʈ
	SHORT _rightTopMoveFrameX, _rightTopMoveFrameY;						//		  ""		�ε���
	SHORT _rightTopAttackCount;											//�������� ���ݻ��¿� �� ī��Ʈ
	SHORT _rightTopAttackFrameX, _rightTopAttackFrameY;					//		  ""		�ε���
	SHORT _rightTopSpecialAttackCount;									//�������� ����Ȱ��� ���¿� �� ī��Ʈ
	SHORT _rightTopSpecialAttackFrameX, _rightTopSpecialAttackFrameY;	//		  ""		�ε���
	SHORT _rightTopHurtCount;											//�������� �ǰ� ���¿� �� ī��Ʈ
	SHORT _rightTopHurtFrameX, _rightTopHurtFrameY;						//		  ""		�ε���

	SHORT _rightBottomIdleCount;											//�����ʾƷ� �������¿� �� ī��Ʈ
	SHORT _rightBottomIdleFrameX, _rightBottomIdleFrameY;					//		  ""        �ε���
	SHORT _rightBottomMoveCount;											//�����ʾƷ� ������¿� �� ī��Ʈ
	SHORT _rightBottomMoveFrameX, _rightBottomMoveFrameY;					//		  ""		�ε���
	SHORT _rightBottomAttackCount;											//�����ʾƷ� ���ݻ��¿� �� ī��Ʈ
	SHORT _rightBottomAttackFrameX, _rightBottomAttackFrameY;				//		  ""		�ε���
	SHORT _rightBottomSpecialAttackCount;									//�����ʾƷ� ����Ȱ��� ���¿� �� ī��Ʈ
	SHORT _rightBottomSpecialAttackFrameX, _rightBottomSpecialAttackFrameY;	//		  ""		�ε���
	SHORT _rightBottomHurtCount;											//�����ʾƷ� �ǰ� ���¿� �� ī��Ʈ
	SHORT _rightBottomHurtFrameX, _rightBottomHurtFrameY;					//		  ""		�ε���

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

