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


//전방선언!!!!!!
class tile;
class enemyManager : public gameNode
{
private:

	tile* _tile;


	chicorita*		_chicorita;
	dandegi*		_dandegi;
	polygon*		_polygon;
	purin*			_purin;




	//건하 이미지감사
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
	//적포켓몬들을 담아줄 벡터
	//아직 임시용으로 만들어두었기에 나중에 생성된 포켓몬 전용
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

