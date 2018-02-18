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


//���漱��!!!!!!
class tile;
class enemyManager : public gameNode
{
private:

	tile* _tile;


	chicorita*		_chicorita;
	dandegi*		_dandegi;
	polygon*		_polygon;
	purin*			_purin;




	//���� �̹�������
	graena*			 _graena;
	rukario*		_rukario;
	mankey*			_mankey;
	tanguri*		_tanguri;
	electivire*		_electivire;


	tagImageName	_chicoName;
	tagImageName	_dandegiName;
	tagImageName	_polygonName;
	tagImageName	_purinName;
	
	tagImageName	_graenaName;
	tagImageName	_rukarioName;
	tagImageName	_mankeyName;
	tagImageName	_tanguriName;
	tagImageName	_electivireName;

	 

private:
	//�����ϸ���� ����� ����
	//���� �ӽÿ����� �����ξ��⿡ ���߿� ������ ���ϸ� ����
	vector<enemy*> _vEnemyPokemon;
	vector<enemy*>::iterator _viEnemyPokemon;



	


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

	inline void setTileMemoryAdressLink(tile* tiles) { _tile = tiles; }
	void enemyMoveManager();

};

