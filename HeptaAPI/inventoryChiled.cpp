#include "stdafx.h"
#include "inventoryChiled.h"
#include "player.h"



inventoryChiled::inventoryChiled()
{
	_x = 50;
	_y = 70;
	_itemNum = 0;

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
		if(_itemNum< _vitem.size())
		{
			_itemNum++;
			_y += 23;

			if (_itemNum >= _vitem.size())
			{
				_itemNum = _vitem.size() - 1;
				_y -= 23;
			}

		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_itemNum >= 0)
		{
		    _y -= 23;
			_itemNum--;
		

			if (_itemNum < 0)
			{
				_itemNum = 0;
				_y += 23;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
	{
		
		if(_vitem[_itemNum].getPotionType() == type_hpPotion)
		{
			_player->setCurrentHp(_player->getCurrentHP() + _vitem[_itemNum].getPotionAbillity());

			if (_player->getCurrentHP() > _player->getMaxHP())
			{
				_player->setCurrentHp(_player->getMaxHP());
			}
			_vitem.erase(_vitem.begin() + _itemNum);
		}

		if (SCENEMANAGER->getCurrentScene() != SCENEMANAGER->findScene("npc"))
		{
			if (_vitem[_itemNum].getPotionType() == type_loop)
			{
				_player->setPosition(WINSIZEX / 2, WINSIZEY - 50);
				SCENEMANAGER->changeParent();
				SCENEMANAGER->changeScene("npc");
				SCENEMANAGER->init("npc");
				//CAMERAMANAGER->init(480, 360, WINSIZEX, WINSIZEY);
				_vitem.erase(_vitem.begin() + _itemNum);
			}
		}
		if (_itemNum != 0)
		{
			_y -= 23;
			_itemNum--;
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
		TextOut(dc, CAMERAMANAGER->getX() + 250, CAMERAMANAGER->getY() + 70 + i * 23, str, strlen(str));
		TextOut(dc, CAMERAMANAGER->getX() +100, CAMERAMANAGER->getY() + 70 + i * 23, _vitem[i].getName().c_str(), strlen(_vitem[i].getName().c_str()));
		
		//char str1[128];
		//sprintf(str1, "%d", _itemNum);
		//TextOut(dc, CAMERAMANAGER->getX() + WINSIZEX / 2, CAMERAMANAGER->getY() + WINSIZEY / 2, str1, strlen(str1));
		//char str2[128];
		//sprintf(str2, "%d", _vitem.size());
		//TextOut(dc, CAMERAMANAGER->getX() + WINSIZEX / 2 + 50, CAMERAMANAGER->getY() + WINSIZEY / 2 +50 , str2, strlen(str2));
	}


	if(_vitem.size() > 0)
	{
		IMAGEMANAGER->findImage("point")->render(dc,CAMERAMANAGER->getX() + _x, CAMERAMANAGER->getY() + _y);
	}
}



void inventoryChiled::setItem(Item* item)
{
	_vitem.push_back((*item));
}
