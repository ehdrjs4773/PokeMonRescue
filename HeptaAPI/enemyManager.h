#pragma once
#include "stdafx.h"
#include "enemy.h"
#include "chicorita.h"
#include "dandegi.h"
#include "gameNode.h"


//전방선언!!!!!!
class tile;
class enemyManager : public gameNode
{
private:
	chicorita* _chicorita;
	dandegi* _dandegi;

	tile* _tile;

	tagImageName _chicoName;
	tagImageName _dandegiName;
	tagImageName _polygonName;
	tagImageName _purinName;

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


	vector<enemy*> getVEnemyPokemon() { return _vEnemyPokemon; };
	vector<enemy*>::iterator getVIEnemyPokemon() { return _viEnemyPokemon; };	

	void setTileMemoryAdressLink(tile* tiles) { _tile = tiles; }

};

