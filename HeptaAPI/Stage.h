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
	//������ Ÿ��
	vector<tile*>		_respontiles;

	//�÷��̾� ���� ��ǥ
	POINT				_playerStartUpid;
	POINT				_playerStartDownid;

	RECT				_renderrc;

	image*				_minimap;

public:
	Stage();
	~Stage();

	HRESULT init(string name);
	void release();
	//�÷��̾� ��ǥ �Է�
	void update(int playerx, int playery);
	void render();

	void load(string name);

	//���� Ÿ�� ����
	int gettileCountX() { return _tileCountX; }
	//���� Ÿ�� ����
	int gettileCountY() { return _tileCountY; }
	//���� Ÿ��
	vector<tile*> getTileAdress() { return _tiles; }
	//�� �̸�
	string getMapName() { return _name; }
	//�� �Ӽ�
	TERRAIN getTarrain() { return _terrain; }

	//�÷��̾� ���� ��ǥ
	POINT getPlayerStartUpid() { return _playerStartUpid; }
	POINT getPlayerStartDownid() { return _playerStartDownid; }

	//������ Ÿ�� ����
	vector<tile*> getrespontile() { return _respontiles; }

	image* getminimap() { return _minimap; }

	
};

