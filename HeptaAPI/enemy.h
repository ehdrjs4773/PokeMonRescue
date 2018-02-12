#pragma once
#include "stdafx.h"
#include "gameNode.h";
#include "Pokemon.h"
//�ӽ����ϸ�


class enemy : public gameNode
{
private:
	int idleIndex;
	int _count;

protected:
	//�������� ������Ƽ�� ����Ŭ�������� �ڽŲ� ������ �ǵ��ϼ� �ֵ���
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

