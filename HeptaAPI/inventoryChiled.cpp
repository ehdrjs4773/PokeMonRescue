#include "stdafx.h"
#include "inventoryChiled.h"



inventoryChiled::inventoryChiled()
{

}


inventoryChiled::~inventoryChiled()
{

}


HRESULT inventoryChiled::init()
{


	return S_OK;
}

void inventoryChiled::release()
{

}

void inventoryChiled::update() 
{
	if (KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
	{
		SCENEMANAGER->changeChild("ui");
	}
}

void inventoryChiled::render() 
{
	HDC dc = CAMERAMANAGER->getMemDC();
	IMAGEMANAGER->findImage("도구상자")->render(dc, CAMERAMANAGER->getX() + 30, CAMERAMANAGER->getY() + 30);

	if (_vitem.size() == 0) return;
	
	char str[128];
	sprintf(str, "%d", _vitem[0].getPrice());
	TextOut(dc, CAMERAMANAGER->getX() + 100, CAMERAMANAGER->getY() + 100, str, strlen(str));
}



void inventoryChiled::setItem(Item* item)
{
	_vitem.push_back((*item));
}
