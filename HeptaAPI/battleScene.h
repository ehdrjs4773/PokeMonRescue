#pragma once
#include "gameNode.h"
#include <vector>

//�ϴ� �÷��̾���,��Ʈ����,���ʹ����� ���� �̳ѹ�
enum TurnChange
{
	playerTurn = 1,
	partnerTurn,
	enemyTurn
};

enum playerAction	//(�ӽ�)
{
	playerMove = 1,
	playerAttack,
	playerUseSkill,
	playerUseItem
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

	playerAction _playerAction;		
	partnerAction _partnerAction;
	EnemyAction _enemyAction;
	
public:
	battleScene();
	~battleScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

