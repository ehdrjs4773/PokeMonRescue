#pragma once
#include "gameNode.h"
#include "tile.h"
#include "enemyManager.h"

enum TERRAIN
{
	TERRAIN_FOREST,
	TERRAIN_ICE,
	TERRAIN_MAGMA,
	TERRAIN_NONE
};

class Stage1 : public gameNode
{
private:
	int			_tileCountX;
	int			_tileCountY;
	tile*		_tiles;
	string		_name;
	TERRAIN		_terrain;

	//�÷��̾� ���� ��ǥ
	POINT		_playerIndexPt;

	//���ʹ� �Ŵ���
	enemyManager* _em;

public:
	Stage1();
	~Stage1();

	HRESULT init();
	void release();
	void update();
	void render();

	void load();
};

