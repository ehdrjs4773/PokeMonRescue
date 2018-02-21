#pragma once
#include "gameNode.h"
#include <vector>
#include "Stage.h"

class player;
class enemyManager;

//일단 플레이어턴,파트너턴,에너미턴을 만들 이넘문
enum TurnChange
{
	playerTurn = 1,
	partnerTurn,
	enemyTurn
};

enum partnerAction	//(임시)
{
	partnerMove = 1,
	partnerAttack,
	partnerUseSkill
};

enum EnemyAction	//(임시)
{
	enemyMove = 1,
	enemyAttack,
	enemyUseSkill
};

class battleScene : public gameNode
{
private:
	TurnChange _battleTrun;

	
	partnerAction _partnerAction;
	EnemyAction _enemyAction;

	Stage*		  _nowStage;
	player*		  _player;
	enemyManager* _em;

private:
	int				_mapNum;
	int				_alphaMap;
	int				_floor;
	int				DungoenNum;
	bool			UpId;
	bool			DownId;

public:
	battleScene();
	~battleScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void StageUpDown();

	void setPlayerMemAdressLink(player* player) { _player = player; }
};

