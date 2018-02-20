#pragma once
#include "gameNode.h"
#include "Npc.h"
#include "StageScene.h"
#include "player.h"
#include "oPeningMovie.h"
#include "Pokemon.h"
#include "shopchildren.h"


class playGround : public gameNode
{
private:
	player* _player;
	Npc* _npc;
	shopchildren* _shop;


public:

	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�

	virtual void imageInitaialization(void); // �̹��� �ʱ�ȭ �Լ�
	playGround();
	~playGround();
};

