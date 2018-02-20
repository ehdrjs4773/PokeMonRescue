#pragma once
#include "stdafx.h"
#include "enemy.h"
#include "gameNode.h"



#include "chicorita.h"
#include "dandegi.h"
#include "polygon.h"
#include "purin.h"
#include "rukario.h"

#include "mankey.h"
#include "tanguri.h"
#include "graena.h"
#include "electivire.h"


enum ENEMY
{
	ENEMY_CHICORITA,
	ENEMY_DANDEGI,
	ENEMY_POLYGON,
	ENEMY_PURIN,
	ENEMY_GRAENA,
	ENEMY_RUKARIO,
	ENEMY_MANKEY,
	ENEMY_TANGURI,
	ENEMY_ELECTIVIRE
};


//���漱��!!!!!!
class tile;
class Stage;
class player;
class enemyManager : public gameNode
{
private: //���漱�� Ŭ���� ���𱸰�
	vector<tile*> _tile;
	Stage* _stage;
	player* _pl;

private://����ü ���� ����

	//���� ��ü Ʋ ����
	chicorita*		_chicorita;
	dandegi*		_dandegi;
	polygon*		_polygon;
	purin*			_purin;
	graena*			 _graena;
	rukario*		_rukario;
	mankey*			_mankey;
	tanguri*		_tanguri;
	electivire*		_electivire;
	//���� ��ü Ʋ ���� �Ϸ�


	//����ü�� �̸��� ���صΰ� ������ ���� ���� �����!!!!
	tagImageName	_chicoName;
	tagImageName	_dandegiName;
	tagImageName	_polygonName;
	tagImageName	_purinName;
	
	tagImageName	_graenaName;
	tagImageName	_rukarioName;
	tagImageName	_mankeyName;
	tagImageName	_tanguriName;
	tagImageName	_electivireName;

private://���Ͱ��� ����

	//�����ϸ���� ����� ����
	//���� �ӽÿ����� �����ξ��⿡ ���߿� ������ ���ϸ� ����
	vector<enemy*> _vEnemyPokemon;
	vector<enemy*>::iterator _viEnemyPokemon;

private:
	int _tileCheckX;
	int _tileCheckY;
	

	bool _canAtk;

public:
	enemyManager();
	~enemyManager();


	HRESULT init();


	void imageInit();
	void release();
	void update();
	void render();


	inline vector<enemy*> getVEnemyPokemon() { return _vEnemyPokemon; };
	inline vector<enemy*>::iterator getVIEnemyPokemon() { return _viEnemyPokemon; };	


	inline void setTileMemoryAdressLink(vector<tile*> tiles) { _tile = tiles; }
	inline void setStageMemoryAdressLink(Stage* stage) { _stage = stage; }
	inline void setPlayerMemoryAdressLink(player* pl) { _pl = pl; }


	void enemyTrunManager();
	void enemyAtkManager(int arrNum);
	void enemyMoveManager(int arrNum);
	void enemyBirth(ENEMY enemy, int tileX, int tileY, int level);


	void enemyDead();
};

