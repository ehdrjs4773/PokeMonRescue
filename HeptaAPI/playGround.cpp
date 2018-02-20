#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{

}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);

	this->imageInitaialization();

	_player = new player;
	_pokemon = new pokemon;

	_player->setPokemonMemAdressLink(_pokemon);
	

	SCENEMANAGER->addScene("npc", new Npc);

	SCENEMANAGER->addScene("Opening", new oPeningMovie);
	
	//SCENEMANAGER->init("Opening");
	
	SCENEMANAGER->addScene("Stage1", new StageScene);
	SCENEMANAGER->addChildScene("npc", "shopchiled", new shopchildren);
	
	map<string, gameNode*>::iterator tempIter = SCENEMANAGER->findScene("npc")->children.find("shopchiled");
	((shopchildren*)tempIter->second)->setPlayerMemoryAdressLink(_player);
	((Npc*)SCENEMANAGER->findScene("npc")->currentScene)->setPlayerMemoryAdressLink(_player);
	((StageScene*)SCENEMANAGER->findScene("Stage1")->currentScene)->setPlayerMemAdressLink(_player);
	SCENEMANAGER->init("Stage1");
	SCENEMANAGER->init("npc");
	SCENEMANAGER->changeScene("Stage1");
	

	return S_OK;
}

//메모리 관련 삭제
void playGround::release(void)
{
	gameNode::release();

}

//연산
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

	
}

//그리는거.......
void playGround::render(void)
{
	//오프닝 PeekMessage 방지
	if (SCENEMANAGER->getCurrentScene() == SCENEMANAGER->findScene("Opening")) return;

	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 =========================
	SCENEMANAGER->render();
	CAMERAMANAGER->render(getMemDC());
	TIMEMANAGER->render(getMemDC());

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
