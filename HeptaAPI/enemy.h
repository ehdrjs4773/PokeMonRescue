#pragma once
#include "stdafx.h"
#include "gameNode.h";
#include "Pokemon.h"
//임시포켓몬


class enemy : public gameNode
{
private:
	int idleIndex;
	int _count;

protected:
	//귀차느니 프로텍티로 아이클래스들이 자신꺼 스스로 건들일수 있도록
	tagTempPokemon _pokemon;


public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(tagImageName PokemonName, float x, float y);
	void release();
	void update();
	void render();


	void keyControl();
	void setState();
	void enemyMove();

	tagTempPokemon getPokemon() { return _pokemon; }
		
};

