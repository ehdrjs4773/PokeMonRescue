#pragma once
#include "gameNode.h"
#include <vector>

class player;

//�ϴ� �÷��̾���,��Ʈ����,���ʹ����� ���� �̳ѹ�
enum TurnChange
{
	playerTurn = 1,
	partnerTurn,
	enemyTurn
};



enum partnerAction	//(�ӽ�)
{
	partnerMove = 1,
	partnerAttack,
	partnerUseSkill
};

enum EnemyAction	//(�ӽ�)
{
	EnemyMove = 1,
	EnemyAttack,
	EnemyUseSkill
};

class battleScene
{
private:
	TurnChange _battleTrun;

	
	partnerAction _partnerAction;
	EnemyAction _enemyAction;

	player*		  _player;
	
public:
	battleScene();
	~battleScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void setPlayerMemAdressLink(player* player) { _player = player; }
};

