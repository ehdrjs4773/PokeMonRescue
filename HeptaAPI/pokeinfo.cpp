#include "stdafx.h"
#include "pokeinfo.h"

pokeinfo::pokeinfo()
{
}


pokeinfo::~pokeinfo()
{
}


HRESULT pokeinfo::init()
{
	return S_OK;
}
void	pokeinfo::release()
{

}
void	pokeinfo::update()
{
	if (KEYMANAGER->isOnceKeyDown(PLAYER_CANCLE_KEY))
	{
		SCENEMANAGER->changeChild("ui");
	}
}
void	pokeinfo::render()
{
	HDC dc = CAMERAMANAGER->getMemDC();
	IMAGEMANAGER->findImage("pokeinfo")->render(dc, CAMERAMANAGER->getX() + 30, CAMERAMANAGER->getY() + 30);
	
	

	char str[128];
	sprintf(str, "����ü�� : %d", _player->getCurrentHP());
	TextOut(dc, CAMERAMANAGER->getX() + 60, CAMERAMANAGER->getY() + 100, str, strlen(str));

	char str1[128];
	sprintf(str1, "���� ���� : %d", _player->getLevel());
	TextOut(dc, CAMERAMANAGER->getX() + 60, CAMERAMANAGER->getY() + 120, str1, strlen(str1));

	char str2[128];
	sprintf(str2, "���� ���ݷ�:%d", _player->getAtkDamage());
	TextOut(dc, CAMERAMANAGER->getX() + 60, CAMERAMANAGER->getY() + 140, str2, strlen(str2));

	char str3[128];
	sprintf(str3, "���� ��:%d", _player->getMoney());
	TextOut(dc, CAMERAMANAGER->getX() + 60, CAMERAMANAGER->getY() + 160, str3, strlen(str3));
}