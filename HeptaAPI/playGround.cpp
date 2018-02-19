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
	
	SCENEMANAGER->init("npc");

	SCENEMANAGER->addScene("Opening", new oPeningMovie);
	
	//SCENEMANAGER->init("Opening");
	
	SCENEMANAGER->addScene("Stage1", new StageScene);
	((StageScene*)SCENEMANAGER->findScene("Stage1")->currentScene)->setPlayerMemAdressLink(_player);
	SCENEMANAGER->init("Stage1");
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
