#include "gameNode.h"
#include "player.h"
#pragma once

class player;

class pokeinfo : public gameNode
{
	
	player* _player;

public:
	pokeinfo();
	~pokeinfo();

	HRESULT init();
	void release();
	void update();
	void render();

	void setPlayerMemoryAdressLink(player* plays) { _player = plays; }
};

