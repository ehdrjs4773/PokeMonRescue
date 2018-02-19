#include "stdafx.h"
#include "Npc.h"



Npc::Npc()
{
}


Npc::~Npc()
{

}



HRESULT Npc::init()
{
	_npc1.image = IMAGEMANAGER->findImage("gandy");
	_npc1.talk = false;
	_npc1.x = WINSIZEX / 2;
	_npc1.y = WINSIZEY / 2;
	_npc1.rc = RectMakeCenter(_npc1.x, _npc1.y, _npc1.image->getWidth(), _npc1.image->getHeight());
	_npc1.collsionrc = RectMakeCenter(_npc1.x,_npc1.y + 10, _npc1.image->getWidth(), 15);

	_npc2.image = IMAGEMANAGER->findImage("windy");
	_npc2.talk = false;
	_npc2.x = WINSIZEX / 2 - 50;
	_npc2.y = WINSIZEY / 2;
	_npc2.rc = RectMakeCenter(_npc2.x, _npc2.y, _npc2.image->getWidth(), _npc2.image->getHeight());
	_npc2.collsionrc = RectMakeCenter(_npc2.x, _npc2.y + 10, _npc2.image->getWidth(), 15);


	return S_OK;
}


void Npc::release()
{

}


void Npc::update()
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		EFFECTMANAGER->play("FireT", 100, 100);
	}


	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		SCENEMANAGER->changeChild("shopchiled");
		SCENEMANAGER->init("npc");
	}

	EFFECTMANAGER->update();
}


void Npc::render() 
{
	HDC dc = CAMERAMANAGER->getMemDC();
	Rectangle(dc, _npc1.rc.left, _npc1.rc.top, _npc1.rc.right, _npc1.rc.bottom);
	Rectangle(dc, _npc1.collsionrc.left, _npc1.collsionrc.top, _npc1.collsionrc.right, _npc1.collsionrc.bottom);
	_npc1.image->render(dc, _npc1.x - _npc1.image->getWidth() / 2, _npc1.y - _npc1.image->getHeight() / 2);
	_npc2.image->render(dc, _npc2.x - _npc2.image->getWidth() / 2, _npc2.y - _npc2.image->getHeight() / 2);
	EFFECTMANAGER->render(dc);
}

