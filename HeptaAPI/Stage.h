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

class Stage : public gameNode
{
private:
	int			_tileCountX;
	int			_tileCountY;
	tile*		_tiles;
	string		_name;
	TERRAIN		_terrain;

	//플레이어 시작 좌표
	POINT		_playerIndexPt;

	//에너미 매니저
	enemyManager* _em;

public:
	Stage();
	~Stage();

	HRESULT init(string name);
	void release();
	void update();
	void render();

	void load(string name);


	int gettileCountX() { return _tileCountX; }
	int gettileCountY() { return _tileCountY; }
	tile* getTileAdress() { return _tiles; }
	string getMapName() { return _name; }
	TERRAIN getTarrain() { return _terrain; }

	//플레이어 시작 좌표
	POINT getPlayerStartpt() { return _playerIndexPt; }
};

