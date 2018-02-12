#include "tempScene.h"



tempScene::tempScene()
{
}


tempScene::~tempScene()
{

}


HRESULT tempScene::init()
{
	_em = new enemyManager;
	_em->init();

	return S_OK;
}
void tempScene::release()
{

}
void tempScene::update() 
{
	_em->update();
}
void tempScene::render() 
{
	_em->render();
}