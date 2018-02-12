#pragma once
#include "stdafx.h"
#include "enemy.h"
#include "chicorita.h"
#include "dandegi.h"
#include "gameNode.h"


class enemyManager : public gameNode
{
private:

	chicorita* _chicorita;
	dandegi* _dandegi;


	tagImageName _chicoName;
	tagImageName _dandegiName;
	tagImageName _polygonName;
	tagImageName _purinName;

private:
	//적포켓몬들을 담아줄 벡터
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

};

