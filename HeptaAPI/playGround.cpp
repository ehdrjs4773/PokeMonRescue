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

	



	SCENEMANAGER->addScene("�ӽþ�", new tempScene);

	SCENEMANAGER->init("�ӽþ�");
	SCENEMANAGER->changeScene("�ӽþ�");
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
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================
	SCENEMANAGER->render();

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
