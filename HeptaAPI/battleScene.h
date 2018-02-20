#pragma once
#include "gameNode.h"
#include <vector>

//일단 플레이어턴,파트너턴,에너미턴을 만들 이넘문
enum TurnChange
{
	playerTurn = 1,
	partnerTurn,
	enemyTurn
};

enum playerAction	//(임시)
{
	playerMove = 1,
	playerAttack,
	playerUseSkill,
	playerUseItem
};

enum partnerAction	//(임시)
{
	partnerMove = 1,
	partnerAttack,
	partnerUseSkill
};

enum EnemyAction	//(임시)
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

