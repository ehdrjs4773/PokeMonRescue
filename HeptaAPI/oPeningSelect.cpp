#include "stdafx.h"
#include "oPeningSelect.h"
#include "inventoryChiled.h"
#include "player.h"



oPeningSelect::oPeningSelect()
{
}


oPeningSelect::~oPeningSelect()
{

}


HRESULT oPeningSelect::init(void)
{
	map<string, gameNode*>::iterator tmepIter = SCENEMANAGER->findScene("npc")->children.find("inventory");
	bool temptemp = ((inventoryChiled*)tmepIter->second)->load();
	if (temptemp)
	{
		SCENEMANAGER->changeScene("npc");
		SCENEMANAGER->init("npc");
		return S_OK;
	}
	SOUNDMANAGER->play("오프닝", 0.75, true);

	CAMERAMANAGER->init(WINSIZEX, WINSIZEY, WINSIZEX, WINSIZEY, 0, 0, 1);

	IMAGEMANAGER->addImage("글배경", ".\\bmps\\oPeningSelect\\openingDialogue.bmp", 320, 58, false, true, MAGENTA);
	IMAGEMANAGER->addImage("배경", ".\\bmps\\oPeningSelect\\Mail.bmp", 480, 360, false, true, MAGENTA);
	IMAGEMANAGER->addImage("name", ".\\bmps\\oPeningSelect\\SelectName.bmp", 252, 353, false, true, MAGENTA);
	IMAGEMANAGER->addImage("select", ".\\bmps\\oPeningSelect\\selectImg.bmp", 15, 15, false, true, MAGENTA);

	_startingMonster[0] = "리자몽";
	_startingMonster[1] = "뮤";
	_startingMonster[2] = "지라치";
	_startingMonster[3] = "리자몽";
	_startingMonster[4] = "리자몽";
	_startingMonster[5] = "리자몽";
	_startingMonster[6] = "리자몽";
	_startingMonster[7] = "리자몽";

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
		IMAGEMANAGER->findImage("배경")->render(CAMERAMANAGER->getMemDC(), 0, 0);
		IMAGEMANAGER->findImage("글배경")->render(CAMERAMANAGER->getMemDC(), WINSIZEX / 2 - 160, WINSIZEY - 58);
		DIALOGUE->render(CAMERAMANAGER->getMemDC());
		break;
	case Opening_Two:
		IMAGEMANAGER->findImage("배경")->render(CAMERAMANAGER->getMemDC(), 0, 0);
		IMAGEMANAGER->render("name", CAMERAMANAGER->getMemDC(), 130, 0);

		TextOut(CAMERAMANAGER->getMemDC(), 180, 30, "구조해야될 것 같은", strlen("구조해야될 것 같은"));
		TextOut(CAMERAMANAGER->getMemDC(), 180, 50, "이름을 선택하세요", strlen("이름을 선택하세요"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 100, "최동건", strlen("최동건"));
		TextOut(CAMERAMANAGER->getMemDC(), 220,130, "정동윤", strlen("정동윤"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 160, "정경훈", strlen("정경훈"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 190, "박근화", strlen("박근화"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 220, "이정민", strlen("이정민"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 250, "이준우", strlen("이준우"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 280, "배건하", strlen("배건하"));
		TextOut(CAMERAMANAGER->getMemDC(), 220, 310, "한재윤", strlen("한재윤"));

		IMAGEMANAGER->render("select", CAMERAMANAGER->getMemDC(), 170, 100+ 30*_selectNum);
		


		break;
	case Opening_Three: case Opening_Four:
		IMAGEMANAGER->findImage("배경")->render(CAMERAMANAGER->getMemDC(), 0, 0);
		IMAGEMANAGER->findImage("글배경")->render(CAMERAMANAGER->getMemDC(), WINSIZEX / 2 - 160, WINSIZEY - 58);
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
		if (DIALOGUE->getCurrentLine() >= 24)
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
		if (DIALOGUE->getCurrentLine() == 30)
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

			_player->init(_startingMonster[_selectNum].c_str());
			SCENEMANAGER->init("Stage1");
			_player->setPosition(WINSIZEX / 2, WINSIZEY / 2);
			if (SOUNDMANAGER->isPlaySound("오프닝"))
			{
				SOUNDMANAGER->stop("오프닝");
			}
			SCENEMANAGER->changeScene("npc");
			SCENEMANAGER->init("npc");
			break;
		}

	}
}