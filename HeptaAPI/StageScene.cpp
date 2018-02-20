#include "stdafx.h"
#include "StageScene.h"
#include "player.h"
#include "enemyManager.h"



StageScene::StageScene()
{
}


StageScene::~StageScene()
{

}

HRESULT StageScene::init()
{
	
	IMAGEMANAGER->addFrameImage("tarrain0-0", ".//bmps//map//tarrain0//0.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain0-1", ".//bmps//map//tarrain0//1.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain0-2", ".//bmps//map//tarrain0//2.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain1-0", ".//bmps//map//tarrain1//0.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain1-1", ".//bmps//map//tarrain1//1.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain1-2", ".//bmps//map//tarrain1//2.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain2-0", ".//bmps//map//tarrain2//0.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain2-1", ".//bmps//map//tarrain2//1.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain2-2", ".//bmps//map//tarrain2//2.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("minimap", ".//bmps//map//wallmini.bmp", 96, 96, 16, 16, true, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("objectlist", ".//bmps//map//items.bmp", 240, 24, 10, 1, false, true, RGB(255, 0, 255));

	_nowStage = new Stage;
	_nowStage->init("0-0");

	_em = new enemyManager;

	_player->setStageMemAdressLink(_nowStage);

	_player->init("¸®ÀÚ¸ù");
	_player->setPosition(_nowStage->getPlayerStartUpid().x * 24 + 12, _nowStage->getPlayerStartUpid().y * 24 + 12);

	_em->setStageMemoryAdressLink(_nowStage);
	_em->setTileMemoryAdressLink(_nowStage->getTileAdress());
	_em->setPlayerMemoryAdressLink(_player);

	_em->init();

	CAMERAMANAGER->init(_nowStage->gettileCountX() * TILESIZEX, _nowStage->gettileCountY() * TILESIZEY, WINSIZEX, WINSIZEY, 0, 0, 1);

	return S_OK;
}

void StageScene::release()
{

}

void StageScene::update() 
{
	_player->update();
	_player->dungeonMove();
	_em->update();
	_nowStage->update(_player->getX(), _player->getY());
}

void StageScene::render() 
{
	_nowStage->render();
	_em->render();

	_player->render();
}