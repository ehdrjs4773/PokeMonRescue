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
	
	npc _npc1;			// �ϴ� ���� ��� ���� ���� 1
	npc _npc2;			// �ϴ� ���� ��� ���� ���� 2
	
	town _town;			// Ÿ������~
	bool _house;		// �Ͽ콺 �������~
	RECT _rc;			// �Ա� ��~
	RECT _rc2;			// �ⱸ ��~
	RECT _rc3;			// �������� �Ա���~
	RECT _rc4;			// ���̺���~
	bool _issaveload;	// ���̺�ε�â ����~
	int _saveloadselect;// ���̺�ε� ��������~
	bool _notload;		// ���̺������� ����~

	player* _player;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void setPlayerMemoryAdressLink(player* play) { _player = play; }
	
	// �� �� ��~
	inline bool getHouse() { return _house; }
	

	Npc();
	~Npc();
};

