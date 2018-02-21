#pragma once
#include "gameNode.h"
#include "Stage.h"

class player;
class enemyManager;
class StageScene : public gameNode
{
private:
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
	StageScene();
	~StageScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void StageUpDown();

	//플레이어 메모리 설정
	void setPlayerMemAdressLink(player* player) { _player = player; }
};

