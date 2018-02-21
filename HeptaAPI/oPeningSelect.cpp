#include "stdafx.h"
#include "oPeningSelect.h"
#include "inventoryChiled.h"



oPeningSelect::oPeningSelect()
{
}


oPeningSelect::~oPeningSelect()
{

}


HRESULT oPeningSelect::init(void)
{
	map<string, gameNode*>::iterator tmepIter = SCENEMANAGER->findScene("npc")->children.find("inventory");
	if (((inventoryChiled*)tmepIter->second)->load())
	{
		SCENEMANAGER->changeScene("npc");
		SCENEMANAGER->init("npc");
		return S_OK;
	}

	IMAGEMANAGER->addImage("�۹��", ".\\bmps\\oPeningSelect\\openingDialogue.bmp", 320, 58, false, true, MAGENTA);
	IMAGEMANAGER->addImage("���", ".\\bmps\\oPeningSelect\\Mail.bmp", 480, 360, false, true, MAGENTA);
	IMAGEMANAGER->addImage("name", ".\\bmps\\oPeningSelect\\SelectName.bmp", 252, 353, false, true, MAGENTA);
	IMAGEMANAGER->addImage("select", ".\\bmps\\oPeningSelect\\selectImg.bmp", 15, 15, false, true, MAGENTA);

	_startingMonster[0] = "���ڸ�";
	_startingMonster[1] = "���α�";
	_startingMonster[2] = "�̻��ؾ�";
	_startingMonster[3] = "���ڸ�";
	_startingMonster[4] = "���α�";
	_startingMonster[5] = "�̻��ؾ�";
	_startingMonster[6] = "���ڸ�";
	_startingMonster[7] = "���α�";

	_Opening = Opening_One;
	_selectNum = 0;
	_isSelect = false;
	_dialogueTime = 0;

	return S_OK;
}

void oPeningSelect::render(void)
{
	switch (_Opening)
	{
	case Opening_One:
		IMAGEMANAGER->findImage("���")->render(CAMERAMANAGER->getMemDC(), 0, 0);
		IMAGEMANAGER->findImage("�۹��")->render(CAMERAMANAGER->getMemDC(), WINSIZEX / 2 - 160, WINSIZEY - 58);
		DIALOGUE->render(CAMERAMANAGER->getMemDC());
		break;
	case Opening_Two:
		IMAGEMANAGER->findImage("���")->render(CAMERAMANAGER->getMemDC(), 0, 0);
		IMAGEMANAGER->render("name", CAMERAMANAGER->getMemDC(), 130, 0);

		TextOut(CAMERAMANAGER->getMemDC(), 180, 30, "�����ؾߵ� �� ����", strlen("�����ؾߵ� �� ����"));
		TextOut(CAMERAMANAGER->getMemDC(), 180, 50, "�̸��� �����ϼ���", strlen("�̸��� �����ϼ���"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 100, "�ֵ���", strlen("�ֵ���"));
		TextOut(CAMERAMANAGER->getMemDC(), 220,130, "������", strlen("������"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 160, "������", strlen("������"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 190, "�ڱ�ȭ", strlen("�ڱ�ȭ"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 220, "������", strlen("������"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 250, "���ؿ�", strlen("���ؿ�"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 280, "�����", strlen("�����"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 310, "������", strlen("������"));

		IMAGEMANAGER->render("select", CAMERAMANAGER->getMemDC(), 170, 100+ 30*_selectNum);
		


		break;
	case Opening_Three: case Opening_Four:
		IMAGEMANAGER->findImage("���")->render(CAMERAMANAGER->getMemDC(), 0, 0);
		IMAGEMANAGER->findImage("�۹��")->render(CAMERAMANAGER->getMemDC(), WINSIZEX / 2 - 160, WINSIZEY - 58);
		DIALOGUE->render(CAMERAMANAGER->getMemDC());
		break;


	default:
		break;
	}
}

void oPeningSelect::update(void)
{
	keyControl();

	switch (_Opening)
	{
	case Opening_One:
		if (DIALOGUE->getCurrentLine() >= 15)
		{

				_Opening = Opening_Two;
			
		}
			break;
	case Opening_Two:
		if (!_isSelect)
		{

		}
		else  _Opening = Opening_Three;

		
		break;
	case Opening_Three:
		if (DIALOGUE->getCurrentLine() == 34)
		{
			_Opening = Opening_Four;
		}
		break;

	case Opening_Four:

		break;


	}

	DIALOGUE->update();

}
void oPeningSelect::release(void)
{

}

void oPeningSelect::keyControl(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_selectNum--;
		if (_selectNum < 0)
			_selectNum = 7;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_selectNum++;
		if (_selectNum > 7)
			_selectNum = 0;
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_SELECT_KEY))
	{
		switch (_Opening)
		{
		case Opening_One:
			if (DIALOGUE->getCurrentLine() <= 32) DIALOGUE->setCurrentLine(DIALOGUE->getCurrentLine() + 2);
			break;
		case Opening_Two:
			if (_selectNum == 0)
			{
				_isSelect = true;
			}
			else if (_selectNum == 1)
			{
				_isSelect = true;
			}
			else if (_selectNum == 2)
			{
				_isSelect = true;
			}
			else if (_selectNum == 3)
			{
				_isSelect = true;
			}
			else if (_selectNum == 4)
			{
				_isSelect = true;
			}
			else if (_selectNum == 5)
			{
				_isSelect = true;
			}
			else if (_selectNum == 6)
			{
				_isSelect = true;
			}
			else if (_selectNum == 7)
			{
				_isSelect = true;
			}
			break;
		case Opening_Three:
			if (DIALOGUE->getCurrentLine() <= 32) DIALOGUE->setCurrentLine(DIALOGUE->getCurrentLine() + 2);
			break;
		case Opening_Four:
			SCENEMANAGER->changeScene("npc");
			SCENEMANAGER->init("npc");
			break;
		}

	}
}