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
	int					_tileCountX;
	int					_tileCountY;
	vector<tile*>		_tiles;
	string				_name;
	TERRAIN				_terrain;

	//플레이어 시작 좌표
	POINT				_playerIndexPt;

public:
	Stage();
	~Stage();

	HRESULT init(string name);
	void release();
	void update();
	void render(RECT nowrc, int x, int y);

	void load(string name);


	int gettileCountX() { return _tileCountX; }
	int gettileCountY() { return _tileCountY; }
	vector<tile*> getTileAdress() { return _tiles; }
	string getMapName() { return _name; }
	TERRAIN getTarrain() { return _terrain; }

	//플레이어 시작 좌표
	POINT getPlayerStartpt() { return _playerIndexPt; }
};

