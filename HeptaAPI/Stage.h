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
	//리스폰 타일
	vector<tile*>		_respontiles;

	//플레이어 시작 좌표
	POINT				_playerStartUpid;
	POINT				_playerStartDownid;

	RECT				_renderrc;

public:
	Stage();
	~Stage();

	HRESULT init(string name);
	void release();
	//플레이어 좌표 입력
	void update(int playerx, int playery);
	void render();

	void load(string name);

	//가로 타일 갯수
	int gettileCountX() { return _tileCountX; }
	//세로 타일 갯수
	int gettileCountY() { return _tileCountY; }
	//백터 타일
	vector<tile*> getTileAdress() { return _tiles; }
	//맵 이름
	string getMapName() { return _name; }
	//맵 속성
	TERRAIN getTarrain() { return _terrain; }

	//플레이어 시작 좌표
	POINT getPlayerStartUpid() { return _playerStartUpid; }
	POINT getPlayerStartDownid() { return _playerStartDownid; }

	//리스폰 타일 추출
	vector<tile*> getrespontile() { return _respontiles; }
};

