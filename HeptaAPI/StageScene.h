#pragma once
#include "gameNode.h"
#include "Stage.h"

class player;

class StageScene : public gameNode
{
private:
	Stage* _nowStage;
	player* _player;

	int _mapNum;
	int _floor;

	POINT _playerpt;

public:
	StageScene();
	~StageScene();

	HRESULT init();
	void release();
	void update();
	void render();

	//플레이어 메모리 설정
	void setPlayerMemAdressLink(player* player) { _player = player; }

	//void serEnemyManagerAdress();
};

