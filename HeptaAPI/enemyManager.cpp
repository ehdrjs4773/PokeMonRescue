#include "enemyManager.h"



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
	_chicorita->init(_chicoName, WINSIZEX / 2, WINSIZEY / 2);

	_dandegi = new dandegi;
	_dandegi->init(_dandegiName, 200, 200);


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