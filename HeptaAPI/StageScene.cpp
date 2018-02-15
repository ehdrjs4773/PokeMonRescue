#include "stdafx.h"
#include "StageScene.h"



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

	_nowStage = new Stage;
	_nowStage->init("0-0");

	_playerpt.x = WINSIZEX / 2;
	_playerpt.y = WINSIZEY / 2;

	return S_OK;
}

void StageScene::release()
{

}

void StageScene::update() 
{
	_nowStage->update();
}

void StageScene::render() 
{
	_nowStage->render(RectMakeCenter(_playerpt.x, _playerpt.y, WINSIZEX, WINSIZEY), _playerpt.x, _playerpt.y);
}