#pragma once
#include "gameNode.h"
#include <vector>
#include "Stage.h"

class player;
class enemyManager;

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



class battleScene : public gameNode
{
private:
	TurnChange _battleTrun;

	
	partnerAction _partnerAction;
	//

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

