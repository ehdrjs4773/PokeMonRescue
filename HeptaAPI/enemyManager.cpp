#include "enemyManager.h"
#include "tile.h"
#define TILEX WINSIZEX / TILESIZEX
#define TILEY WINSIZEY / TILESIZEY



enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{

}


HRESULT enemyManager::init()
{
	imageInit();

	_chicorita = new chicorita;
	_chicorita->init(_chicoName, _tile[TILEX -3 + TILEX * 2].getCenterX() 
		, _tile[TILEX - 3+ TILEX * 2].getCenterY());

	_dandegi = new dandegi;
	_dandegi->init(_dandegiName, _tile[TILEX - 3 + TILEX * 14].getCenterX()
		, _tile[TILEX - 3 + TILEX * 14].getCenterY());


	return S_OK;
}
void enemyManager::release()
{

}
void enemyManager::update()	
{
	

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_chicorita->attack();
	}
	_chicorita->update();
	_dandegi->update();

}
void enemyManager::render()	
{
	_chicorita->render();
	_dandegi->render();
}

