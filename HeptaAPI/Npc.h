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

class Npc : public gameNode
{
private:
	
	npc _npc1;	// �ϴ� ���� ��� ���� ���� 1
	npc _npc2;	// �ϴ� ���� ��� ���� ���� 2


public:

	HRESULT init();
	void release();
	void update();
	void render();


	Npc();
	~Npc();
};

