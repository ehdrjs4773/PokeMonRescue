#pragma once
#include "gameNode.h"


struct npc
{
	image* image;
	RECT rc;
	int x;
	int y;
	RECT collsionrc;
	bool talk;
};

struct town
{
	bool inout;
	
};

class player;


class Npc : public gameNode
{
private:
	
	npc _npc1;		// 일단 시험 삼아 만든 상인 1
	npc _npc2;		// 일단 시험 삼아 만든 상인 2
	
	town _town;		// 타운이죠~
	bool _house;	// 하우스 들어갔나요오~
	RECT _rc;		// 입구 죠~
	RECT _rc2;		// 출구 죠~

	player* _player;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void setPlayerMemoryAdressLink(player* play) { _player = play; }


	Npc();
	~Npc();
};

