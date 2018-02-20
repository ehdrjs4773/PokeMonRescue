#include "stdafx.h"
#include "Npc.h"
#include "player.h"



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
	_npc1.x = WINSIZEX - 70;
	_npc1.y = WINSIZEY - 135;
	_npc1.rc = RectMakeCenter(_npc1.x, _npc1.y, _npc1.image->getWidth(), _npc1.image->getHeight());
	_npc1.collsionrc = RectMakeCenter(_npc1.x,_npc1.y + 30, _npc1.image->getWidth(), 15);

	_npc2.image = IMAGEMANAGER->findImage("windy");
	_npc2.talk = false;
	_npc2.x = WINSIZEX - 40;
	_npc2.y = WINSIZEY - 135;
	_npc2.rc = RectMakeCenter(_npc2.x, _npc2.y, _npc2.image->getWidth(), _npc2.image->getHeight());
	_npc2.collsionrc = RectMakeCenter(_npc2.x, _npc2.y + 10, _npc2.image->getWidth(), 15);

	_town.inout = true;
	
	_player->init("¸®ÀÚ¸ù", WINSIZEX / 2, WINSIZEY / 2 , true);
	//´Ù ‰ç¾î¿ä Âô±ß ><*


	return S_OK;
}


void Npc::release()
{

}


void Npc::update()
{
	_player->update();
	
	RECT temp;
	if (IntersectRect(&temp, &_npc1.collsionrc, &_player->getRect()))
	{	
		if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
		{
			SCENEMANAGER->changeChild("shopchiled");
			SCENEMANAGER->init("npc");
		}
	}

}


void Npc::render() 
{
	HDC dc = CAMERAMANAGER->getMemDC();
	//Rectangle(dc, _npc1.rc.left, _npc1.rc.top, _npc1.rc.right, _npc1.rc.bottom);
	
	if(_town.inout)
	{
		IMAGEMANAGER->findImage("town")->render(dc, 0, 0);
		_npc1.image->render(dc, _npc1.x - _npc1.image->getWidth() / 2, _npc1.y - _npc1.image->getHeight() / 2);
		_npc2.image->render(dc, _npc2.x - _npc2.image->getWidth() / 2, _npc2.y - _npc2.image->getHeight() / 2);
		Rectangle(dc, _npc1.collsionrc.left, _npc1.collsionrc.top, _npc1.collsionrc.right, _npc1.collsionrc.bottom);
		Rectangle(dc, _player->getRect().left, _player->getRect().top, _player->getRect().right, _player->getRect().bottom);
	}

	if (!_town.inout)
	{
		IMAGEMANAGER->findImage("saveTown")->render(dc, WINSIZEX / 2 - IMAGEMANAGER->findImage("saveTown")->getWidth() / 2, WINSIZEY / 2 - IMAGEMANAGER->findImage("saveTown")->getHeight() / 2);
	}

	_player->render();
}

