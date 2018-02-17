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
	vector<tile*>		_respontiles;

	//�÷��̾� ���� ��ǥ
	POINT				_playerStartUpid;
	POINT				_playerStartDownid;

	RECT				_renderrc;

public:
	Stage();
	~Stage();

	HRESULT init(string name);
	void release();
	void update(int playerx, int playery);
	void render();

	void load(string name);


	int gettileCountX() { return _tileCountX; }
	int gettileCountY() { return _tileCountY; }
	vector<tile*> getTileAdress() { return _tiles; }
	string getMapName() { return _name; }
	TERRAIN getTarrain() { return _terrain; }

	//�÷��̾� ���� ��ǥ
	POINT getPlayerStartUpid() { return _playerStartUpid; }
	POINT getPlayerStartDownid() { return _playerStartDownid; }
};

