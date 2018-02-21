#pragma once
#include "gameNode.h"
#include "pokemon.h"

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

private: // ## ���ϸ� ���� ##
	pokemon* _partnerStatus;

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
	//�⺻
	SHORT _idleCount;
	SHORT _idleFrameX, _idleFrameY;

	//������
	SHORT _moveCount;
	SHORT _moveFrameX, _moveFrameY;

	//����
	SHORT _attackCount;
	SHORT _attackFrameX, _attackFrameY;

	//����Ȱ���
	SHORT _S_AttackCount;
	SHORT _S_AttackFrameX, _S_AttackFrameY;

	//����Ȱ���2
	SHORT _S_AttackCount_2;
	SHORT _S_AttackFrameX_2, _S_AttackFrameY_2;

	//�ǰ�
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
};

