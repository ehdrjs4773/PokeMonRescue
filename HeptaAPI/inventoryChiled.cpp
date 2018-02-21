#include "stdafx.h"
#include "inventoryChiled.h"
#include "player.h"



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
	
	
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_vitem.size() > 0)
		{
			
		}
	}

}

void inventoryChiled::render() 
{
	HDC dc = CAMERAMANAGER->getMemDC();
	IMAGEMANAGER->findImage("도구상자")->render(dc, CAMERAMANAGER->getX() + 30, CAMERAMANAGER->getY() + 30);

	if (_vitem.size() == 0) return;
	
	for(int i = 0; i < _vitem.size(); i++)
	{
		char str[128];
		sprintf(str, "%d", _vitem[i].getPrice());
		TextOut(dc, CAMERAMANAGER->getX() + 250, CAMERAMANAGER->getY() + 70 + i * 20, str, strlen(str));
		TextOut(dc, CAMERAMANAGER->getX() +100, CAMERAMANAGER->getY() + 70 + i * 20, _vitem[i].getName().c_str(), strlen(_vitem[i].getName().c_str()));
	}


	for (int i = 0; i < _vitem.size(); ++i)
	{
		IMAGEMANAGER->findImage("point")->render(dc, 50, 70);
	}
}



void inventoryChiled::setItem(Item* item)
{
	_vitem.push_back((*item));
}
