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
	
	SCENEMANAGER->init("npc");

	SCENEMANAGER->addScene("Opening", new oPeningMovie);
	
	//SCENEMANAGER->init("Opening");
	
	SCENEMANAGER->addScene("Stage1", new StageScene);
	SCENEMANAGER->addChildScene("npc", "shopchiled", new shopchildren);
	((StageScene*)SCENEMANAGER->findScene("Stage1")->currentScene)->setPlayerMemAdressLink(_player);
	SCENEMANAGER->init("Stage1");
	SCENEMANAGER->changeScene("Stage1");
	

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
