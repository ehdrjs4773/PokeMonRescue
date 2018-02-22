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

	//SCENEMANAGER->addScene("Stage1", new StageScene);						//�׽�Ʈ�� ����!
	SCENEMANAGER->addScene("Stage1", new battleScene);						//���ϲ� ����!
	
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



	//((StageScene*)SCENEMANAGER->findScene("Stage1")->currentScene)->setPlayerMemAdressLink(_player);	//�׽�Ʈ�� ����!
	((battleScene*)SCENEMANAGER->findScene("Stage1")->currentScene)->setPlayerMemAdressLink(_player);	//���ϲ� ����!
	SCENEMANAGER->init("Stage1");
	SCENEMANAGER->init("npc");

	SCENEMANAGER->addScene("Opening", new oPeningMovie);
	SCENEMANAGER->addScene("openingSelect", new oPeningSelect);
	((oPeningSelect*)SCENEMANAGER->findScene("openingSelect")->currentScene)->setPlayerMemoryAdressLink(_player);

	SCENEMANAGER->init("Opening");

	SCENEMANAGER->changeScene("Opening");
	

	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();

}

//����
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

	
}

//�׸��°�.......
void playGround::render(void)
{
	//������ PeekMessage ����
	if (SCENEMANAGER->getCurrentScene() == SCENEMANAGER->findScene("Opening")) return;

	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================
	SCENEMANAGER->render();
	CAMERAMANAGER->render(getMemDC());
	TIMEMANAGER->render(getMemDC());

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
