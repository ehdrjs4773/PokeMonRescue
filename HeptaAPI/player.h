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

enum playerAction	//(�ӽ�)
{
	playerMove = 1,
	playerAttack,
	playerUseSkill,
	playerUseItem
};

//�÷��̾� �⺻������ ���� ����ü
struct tagPlayer
{
	PLAYER_DIRECTION direction;		//����
	PLAYER_STATE state;				//����
	RECT imageRc;					//�̹��� ���� ��Ʈ
	RECT rc;						//���� ����� ��Ʈ ( Ÿ�� ? ������)
	float startX, startY;			//������ x, y ( �����̵��� �ʿ��� )
	float x, y;						//���� x, y
	float angle;					//�ޱ�
	int idx, idy;					//���° x, yŸ�Ͽ� �ִ��� �ε��� 
	int tileIndex;					//���° Ÿ�Ͽ� �ִ��� �ε���
	int money;						//��
	int dgNum;						//���� ��ȣ
	float townSpeed;				//���������� �ӵ�		
	float dgSpeed;					//���������� �ӵ�
};

class Stage;
class item;
class enemyManager;
class Npc;

class player : public gameNode
{
private: // ## �� ���� ##
	Stage* _stage;
	Npc* _town;

private: // ## ���ϸ� ���� ##
	pokemon* _playerStatus;
	playerAction _playerAction;		//(�ӽ�)

private: // ## ���ʹ� ���� ##
	enemyManager* _em;

private: // ## ��Ʈ�� ���� ##
	vector<playerPartner*> _vPartner;
	vector<playerPartner*>::iterator _viPartner;

private:
	tagPlayer _player;		//�÷��̾�

	string tempNameIdle;
	string tempNameMove;
	string tempNameAttack;
	string tempNameSpecialAttack;
	string tempNameHurt;

private: // ## �Ұ� ##
	bool _isAttack;		//�����޴�?
	bool _onceMove;		//���������� �ѹ��� �����̰�

	// �����̵��� �ʿ��� �Ұ�
	// ������ �� �ִ�? ( �տ� ���� �ִ�? )
	bool _isBottomMove;
	bool _isLeftBottomMove;
	bool _isLeftMove;
	bool _isLeftTopMove;
	bool _isTopMove;
	bool _isRightTopMove;
	bool _isRightMove;
	bool _isRightBottomMove;
	
	bool _isWallCrash;			//���� �ε�����?

private: // ## ������ ���� ������ ## 
	SHORT _bottomIdleCount;											//���� �������¿� �� ī��Ʈ
	SHORT _bottomIdleFrameX, _bottomIdleFrameY;					//        ""        �ε���
	SHORT _bottomMoveCount;											//���� ������¿� �� ī��Ʈ
	SHORT _bottomMoveFrameX, _bottomMoveFrameY;					//		  ""		�ε���
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
	player();
	~player();

	virtual HRESULT init();
	//Ű�� , ������ X, Y;
	virtual HRESULT init(string charName);
	virtual void release();
	virtual void update();
	virtual void render();

	void townMove();		//�������� �̵�
	void dungeonMove();		//�������� �̵�

	void playerTownMove();	//�������� �ʹ��� ���� ������ 
	void playerDgMove();
	void FrameUpdate();		//������ �������°͵� �ʹ� �� ���� ������
	void valueInit();		//���� �ʱ�ȭ�� ��
	void dgMoveValueInit();	//���� ������ �Ұ� �ʱ�ȭ
	void draw();			//�׸��°͵� ��
	void correction();		//�����۾�
	void pixelCollision();	//�ȼ��浹
	void tileCheak();		//Ÿ�ϰ���

	void addPartner(pokemon* p);	//��Ʈ�� �߰� �Լ�

	//������
	inline PLAYER_DIRECTION getPlayerDirection() { return (PLAYER_DIRECTION)_player.direction; }		//����
	inline PLAYER_STATE getPlayerState() { return (PLAYER_STATE)_player.state; }						//����
	inline RECT getRect() { return _player.rc; }									//��Ʈ
	inline float getPlayerAngle() { return _player.angle; }							//�ޱ۰�
	inline float getX() { return _player.x; }										//�÷��̾� ���� X
	inline float getY() { return _player.y; }										//�÷��̾� ���� Y

	inline int getPlayerTileIndexX() { return _player.idx; }						//�ε��� X
	inline int getPlayerTileIndexY() { return _player.idy; }						//�ε��� Y

	inline int getMoney() { return _player.money; }									//��

	inline int getCurrentHP() { return _playerStatus->getCurrentHP(); }				//����ü��
	inline int getMaxHP() { return _playerStatus->getMaxHP(); }						//��üü��
	inline int getMaxExp() { return _playerStatus->getMaxEXP(); }					//��ü����ġ
	inline int getCurrentExp() { return _playerStatus->getCurrentEXP(); }			//�������ġ
	inline int getAtkDamage() { return _playerStatus->getAtk(); }					//���ݷ�
	inline int getDef() { return _playerStatus->getDef(); }							//����
	inline int getSpecialAtk() { return _playerStatus->getSpecialATK(); }			//����Ȱ��ݷ�
	inline int getSpecialDef() { return _playerStatus->getSpecialDef(); }			//����ȹ���
	inline int getLevel() { return _playerStatus->getLevel(); }						//����
	inline playerAction getPlayerAction() { return _playerAction; }					//�׼� �̳� (�ӽ�)

	//������																			
	void setStageMemAdressLink(Stage* stage) { _stage = stage; }					//��������
	void setEmMemAdressLink(enemyManager* em) { _em = em; }
	void setTownMapMemAdressLink(Npc* map) { _town = map; }
	

	void setX(float x) { _player.x = x; }											//X��ǥ ����
	void setY(float y) { _player.y = y; }											//Y��ǥ ����

	void setAddMoney(int money) { _player.money = money; }							//��

	inline int getDungeonNum() { return _player.dgNum; }							//�����ѹ� ��
	void setDungeonNum(int dgNum) { _player.dgNum = dgNum; }						//�����ѹ� ��

	void setPosition(float startX, float startY);									//��ǥ����

	inline playerAction setPlayerAction(playerAction playerAction) { _playerAction = playerAction; }//�׼� �̳� (�ӽ�)
};

