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
	
	SCENEMANAGER->addScene("npc", new Npc);
	_player->setTownMapMemAdressLink((Npc*)SCENEMANAGER->findScene("npc")->currentScene);

	//SCENEMANAGER->addScene("Stage1", new StageScene);						//테스트용 데스!
	SCENEMANAGER->addScene("Stage1", new battleScene);						//건하꺼 데스!
	
	SCENEMANAGER->addChildScene("npc", "ui", new UI);
	SCENEMANAGER->addChildScene("npc", "inventory", new inventoryChiled);
	SCENEMANAGER->addChildScene("npc", "shopchiled", new shopchildren);
	SCENEMANAGER->addChildScene("npc", "pokeinfo", new pokeinfo);

	map<string, gameNode*>::iterator tempInven = SCENEMANAGER->findScene("npc")->children.find("inventory");
	map<string, gameNode*>::iterator tempIter = SCENEMANAGER->findScene("npc")->children.find("shopchiled");
	map<string, gameNode*>::iterator tempInfo = SCENEMANAGER->findScene("npc")->children.find("pokeinfo");
	//SCENEMANAGER->addScene("Stage1", new StageScene);
	SCENEMANAGER->addChildScene("Stage1", "ui", tempIter->second);
	SCENEMANAGER->addChildScene("Stage1", "inventory", tempInven->second);

	((pokeinfo*)tempInfo->second)->setPlayerMemoryAdressLink(_player);
	((shopchildren*)tempIter->second)->setPlayerMemoryAdressLink(_player);
	((shopchildren*)tempIter->second)->setInventoryMemoryAdressLink((inventoryChiled*)tempInven->second);
	((inventoryChiled*)tempInven->second)->setInvenPlayerMemAdressLink(_player);
	((Npc*)SCENEMANAGER->findScene("npc")->currentScene)->setPlayerMemoryAdressLink(_player);
	//((StageScene*)SCENEMANAGER->findScene("Stage1")->currentScene)->setPlayerMemAdressLink(_player);



	//((StageScene*)SCENEMANAGER->findScene("Stage1")->currentScene)->setPlayerMemAdressLink(_player);	//테스트용 데스!
	((battleScene*)SCENEMANAGER->findScene("Stage1")->currentScene)->setPlayerMemAdressLink(_player);	//건하꺼 데스!
	SCENEMANAGER->init("Stage1");
	SCENEMANAGER->init("npc");

	SCENEMANAGER->addScene("Opening", new oPeningMovie);
	SCENEMANAGER->addScene("openingSelect", new oPeningSelect);

	SCENEMANAGER->init("Opening");

	SCENEMANAGER->changeScene("Opening");
	

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
