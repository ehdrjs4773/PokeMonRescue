#pragma once
#include "gameNode.h"
#include "Stage.h"

class StageScene : public gameNode
{
private:
	Stage* _nowStage;

	int _mapNum;
	int _floor;

public:
	StageScene();
	~StageScene();

	HRESULT init();
	void release();
	void update();
	void render();


	//void setPlayerAdress();
	//void serEnemyManagerAdress();
};

