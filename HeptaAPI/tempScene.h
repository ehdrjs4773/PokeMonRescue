#pragma once
#include "stdafx.h"
#include "gameNode.h"
#include "enemyManager.h"

class tempScene : public gameNode
{
private:
	enemyManager* _em;

public:
	tempScene();
	~tempScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

