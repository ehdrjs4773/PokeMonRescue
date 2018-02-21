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
	
	_player->init("¸®ÀÚ¸ù");
	_player->setPosition(WINSIZEX / 2 , WINSIZEY - 50);

	//´Ù ‰ç¾î¿ä Âô±ß ><*

	_rc = RectMakeCenter(WINSIZEX / 2 - 60, WINSIZEY / 2 + 10, 30, 30);
	_rc2 = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2+ 130, 50, 30);
	_rc3 = RectMakeCenter(WINSIZEX - 7, WINSIZEY - 25, 15, 50);
	_rc4 = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 - 37, 30, 30);
	_house = false;

	CAMERAMANAGER->init(480, 360, WINSIZEX, WINSIZEY);
	return S_OK;
}


void Npc::release()
{

}


void Npc::update()
{
	_player->update();
	_player->townMove();
	RECT temp;
	if (_town.inout)
	{
		if (IntersectRect(&temp, &_npc1.collsionrc, &_player->getRect()))
		{
			if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
			{
				SCENEMANAGER->changeChild("shopchiled");
				SCENEMANAGER->init("npc");
			}

		}

		if (IntersectRect(&temp, &_rc, &_player->getRect()))
		{
			_town.inout = false;
			_house = true;
			_player->setPosition(_rc2.left + 25, WINSIZEY / 2 + 100);

		}
	}


	if (!_town.inout)
	{
		if (IntersectRect(&temp, &_rc2, &_player->getRect()))
		{
			_town.inout = true;
			_house = false;
			_player->setPosition(_rc.left + 15, WINSIZEY / 2 + 45);
		}
	}


	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		SCENEMANAGER->changeChild("ui");
		SCENEMANAGER->init("npc");
	}

	if (IntersectRect(&temp, &_rc3, &_player->getRect()))
	{
		SCENEMANAGER->init("Stage1");
		SCENEMANAGER->changeScene("Stage1");
	}
	
}


void Npc::render() 
{
	HDC dc = CAMERAMANAGER->getMemDC();
	//Rectangle(dc, _npc1.rc.left, _npc1.rc.top, _npc1.rc.right, _npc1.rc.bottom);

	if(_town.inout)
	{
		IMAGEMANAGER->findImage("townMagenta")->render(dc, 0, 0);
		IMAGEMANAGER->findImage("town")->render(dc, 0, 0);
		_npc1.image->render(dc, _npc1.x - _npc1.image->getWidth() / 2, _npc1.y - _npc1.image->getHeight() / 2);
		_npc2.image->render(dc, _npc2.x - _npc2.image->getWidth() / 2, _npc2.y - _npc2.image->getHeight() / 2);
		Rectangle(dc, _npc1.collsionrc.left, _npc1.collsionrc.top, _npc1.collsionrc.right, _npc1.collsionrc.bottom);
		Rectangle(dc, _player->getRect().left, _player->getRect().top, _player->getRect().right, _player->getRect().bottom);
		Rectangle(dc, _rc.left, _rc.top, _rc.right, _rc.bottom);
	}

	if (!_town.inout)
	{
		IMAGEMANAGER->findImage("alphamap")->alphaRender(CAMERAMANAGER->getMemDC(),	0, 0, 255);
		IMAGEMANAGER->findImage("saveTown")->render(dc, WINSIZEX / 2 - IMAGEMANAGER->findImage("saveTown")->getWidth() / 2, WINSIZEY / 2 - IMAGEMANAGER->findImage("saveTown")->getHeight() / 2);
		Rectangle(dc, _rc2.left, _rc2.top, _rc2.right, _rc2.bottom);
	}
	Rectangle(dc, _rc3.left, _rc3.top, _rc3.right, _rc3.bottom);
	Rectangle(dc, _rc4.left, _rc4.top, _rc4.right, _rc4.bottom);
	_player->render();
}

