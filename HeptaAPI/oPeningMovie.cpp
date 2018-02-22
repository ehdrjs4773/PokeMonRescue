#include "stdafx.h"
#include "oPeningMovie.h"
#include "oPeningSelect.h"
#include "player.h"
#include "Npc.h"
#include "inventoryChiled.h"
#include "UI.h"
#include "pokeinfo.h"
#include "battleScene.h"
#include "Ending.h"



oPeningMovie::oPeningMovie()
{
}


oPeningMovie::~oPeningMovie()
{
}

HRESULT oPeningMovie::init()
{
	RECT         rt;
	char szAVIFilename[] = "pkr.wmv";
	if (hWndAVI)
	{
		MCIWndClose(hWndAVI);
		MCIWndDestroy(hWndAVI);
		hWndAVI = 0;
	}

	hWndAVI = MCIWndCreate(_hWnd, _hInstance,
		MCIWNDF_NOTIFYANSI | MCIWNDF_NOMENU |
		MCIWNDF_NOTIFYALL | MCIWNDF_NOPLAYBAR,
		szAVIFilename);

	if (hWndAVI)
	{
		GetClientRect(_hWnd, &rt);
		SetWindowPos(hWndAVI, NULL, 0, 0, rt.right, rt.bottom, SWP_NOZORDER | SWP_NOMOVE);
		MCIWndPlay(hWndAVI);
	}

	return S_OK;
}
void oPeningMovie::release()
{
	DestroyWindow(hWndAVI);
	KillTimer(_hWnd, 1);
}

void oPeningMovie::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		DIALOGUE->loadingTextFile(".\\textData\\opening_sin.txt");
		DIALOGUE->setPoint(PointMake(100, WINSIZEY - 50));
	
		_player = new player;

		SCENEMANAGER->addScene("npc", new Npc);
		SCENEMANAGER->addChildScene("npc", "inventory", new inventoryChiled);
		SCENEMANAGER->addChildScene("npc", "ui", new UI);

		_player->setTownMapMemAdressLink((Npc*)SCENEMANAGER->findScene("npc")->currentScene);

		SCENEMANAGER->addScene("Stage1", new battleScene);						//°ÇÇÏ²¨ µ¥½º!

		SCENEMANAGER->addChildScene("npc", "ui", new UI);
		SCENEMANAGER->addChildScene("npc", "inventory", new inventoryChiled);
		SCENEMANAGER->addChildScene("npc", "shopchiled", new shopchildren);
		SCENEMANAGER->addChildScene("npc", "pokeinfo", new pokeinfo);
		//ending
		SCENEMANAGER->addScene("ending", new Ending);

		map<string, gameNode*>::iterator tempInven = SCENEMANAGER->findScene("npc")->children.find("inventory");
		map<string, gameNode*>::iterator tempIter = SCENEMANAGER->findScene("npc")->children.find("shopchiled");
		map<string, gameNode*>::iterator tempInfo = SCENEMANAGER->findScene("npc")->children.find("pokeinfo");
		map<string, gameNode*>::iterator tempUi = SCENEMANAGER->findScene("npc")->children.find("ui");
		SCENEMANAGER->addChildScene("Stage1", "ui", tempUi->second);
		SCENEMANAGER->addChildScene("Stage1", "inventory", tempInven->second);

		((pokeinfo*)tempInfo->second)->setPlayerMemoryAdressLink(_player);
		((shopchildren*)tempIter->second)->setPlayerMemoryAdressLink(_player);
		((shopchildren*)tempIter->second)->setInventoryMemoryAdressLink((inventoryChiled*)tempInven->second);
		((inventoryChiled*)tempInven->second)->setInvenPlayerMemAdressLink(_player);
		((Npc*)SCENEMANAGER->findScene("npc")->currentScene)->setPlayerMemoryAdressLink(_player);

		((battleScene*)SCENEMANAGER->findScene("Stage1")->currentScene)->setPlayerMemAdressLink(_player);	//°ÇÇÏ²¨ µ¥½º!


		SCENEMANAGER->addScene("openingSelect", new oPeningSelect);
		((oPeningSelect*)SCENEMANAGER->findScene("openingSelect")->currentScene)->setPlayerMemoryAdressLink(_player);

		SCENEMANAGER->changeScene("openingSelect");
		SCENEMANAGER->init("openingSelect");

		//SCENEMANAGER->changeScene("Stage1");
		//SCENEMANAGER->init("Stage1");
		this->release();
	}
}
void oPeningMovie::render()
{
}