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
	PLAYER_SPECIAL_ATTACK_3,	//����� ���� 3
	PLAYER_SPECIAL_ATTACK_4,	//����� ���� 4
	PLAYER_HURT,				//�ǰ�
	PLAYER_DIE,					//�׾�����?
	PLAYER_STATE_END
};

enum playerAction	//(�ӽ�)
{
	playerMove = 1,
	playerAttack,
	playerUseSkill,
	playerUseItem,
	playerEnd
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
	bool _isHurt;		//�ǰݻ��´�?

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

	//����Ȱ���3
	SHORT _S_AttackCount_3;
	SHORT _S_AttackFrameX_3, _S_AttackFrameY_3;

	//����Ȱ���4
	SHORT _S_AttackCount_4;
	SHORT _S_AttackFrameX_4, _S_AttackFrameY_4;

	//�ǰ�
	SHORT _hurtCount;
	SHORT _hurtFrameX, _hurtFrameY;


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

	inline pokemon* getStatus() { return _playerStatus; }							//���ϸ� ����

	//������																			
	void setStageMemAdressLink(Stage* stage) { _stage = stage; }					//��������
	void setEmMemAdressLink(enemyManager* em) { _em = em; }
	void setTownMapMemAdressLink(Npc* map) { _town = map; }
	void setBattleSceneMemory(battleScene* b) { _battle = b; }
	
	void setX(float x) { _player.x = x; }											//X��ǥ ����
	void setY(float y) { _player.y = y; }											//Y��ǥ ����

	void setCurrentHp(int hp) { _playerStatus->setCurrentHP(hp); }					//ü��
	void setCurrentExp(int exp) { _playerStatus->setCurrentEXP(exp); }				//����ġ
	void setAddMoney(int money) { _player.money = money; }							//��

	inline int getDungeonNum() { return _player.dgNum; }							//�����ѹ� ��
	void setDungeonNum(int dgNum) { _player.dgNum = dgNum; }						//�����ѹ� ��

	void setPosition(float startX, float startY);									//��ǥ����

	inline void setPlayerAction(playerAction playerAction) { _playerAction = playerAction; }//�׼� �̳� (�ӽ�)
	

};

