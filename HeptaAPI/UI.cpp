#include "stdafx.h"
#include "UI.h"



UI::UI()
{
}


UI::~UI()
{
	
	
}

HRESULT UI::init()
{
	_infoUI[0].img = IMAGEMANAGER->findImage("마을기본메뉴");
	_infoUI[1].img = IMAGEMANAGER->findImage("맵표시");
	_infoUI[2].img = IMAGEMANAGER->findImage("돈표시");
	_infoUI[3].img = IMAGEMANAGER->findImage("도구상자");



	_infoUI[0].rc = RectMakeCenter(100, 100, _infoUI[0].img->getWidth(), _infoUI[0].img->getHeight());
	_infoUI[1].rc = RectMakeCenter(325, 100, _infoUI[1].img->getWidth(), _infoUI[1].img->getHeight());
	_infoUI[2].rc = RectMakeCenter(240, 300, _infoUI[2].img->getWidth(), _infoUI[2].img->getHeight());
	_infoUI[3].rc = RectMake(50, 50, _infoUI[3].img->getWidth(), _infoUI[3].img->getHeight());


	_mainMenu[0] = "도구";
	_mainMenu[1] = "팀";
	_mainMenu[2] = "의뢰리스트";
	//도구 탭 들어가면
	_mainMenu[3] = "도구상자";

	_mainMenu[4] = "팀";

	_isMenu = true;
	
	_infoUI[0].isSelcet = false;
	_infoUI[1].isSelcet = false;
	_infoUI[2].isSelcet = false;


	_selectNum = 0;



	return S_OK;
}

void UI::release()
{

}

void UI::update() 
{
	//플레이어의 지정 키가 아직 없어서 UI 에서 '일단' 지정키를 등록
	//그리고 예외처리

	if (_isMenu || _infoUI[0].isSelcet)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))		// 메뉴 창에서 UP 키를 누르면 셀릭트 아이콘이 위아래로 움직인다.
		{
			_selectNum--;
			if (_selectNum < 0)
				_selectNum = 2;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_selectNum++;
			if (_selectNum > 2)
				_selectNum = 0;
		}

		if (KEYMANAGER->isOnceKeyDown('X'))			//셀렉트 아이콘 움직임에 넘버를 주어서 X 키를 누르면 그 메뉴를 선택하게 된다.
		{
		
			if (_selectNum == 0)
			{
				//_infoUI[0].isSelcet = true;
				//_isMenu = false;
				SCENEMANAGER->changeChild("inventory");
				//SCENEMANAGER->init("npc");
			
			}
			else if (_selectNum == 1)
			{
				//_infoUI[1].isSelcet = true;
				//_isMenu = false;
				SCENEMANAGER->changeChild("pokeinfo");
				

			}
			else
			{
				_infoUI[2].isSelcet = true;
				_isMenu = false;
			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown('C'))			// 플레이어의 지정 키를 누르면 뒤로 가게 처리(지금은 임시로 뒤로가는 키를 부여)
	{
		_isMenu = false;
		if (!_isMenu && _infoUI[0].isSelcet || _infoUI[1].isSelcet || _infoUI[2].isSelcet)
		{
			_infoUI[0].isSelcet = false;
			_infoUI[1].isSelcet = false;
			_infoUI[2].isSelcet = false;

			_isMenu = true;
		}
		if(!_isMenu)
		{
			SCENEMANAGER->changeParent();
		}
	}

}

void UI::render() 
{

	HDC dc = CAMERAMANAGER->getMemDC();
	if (_isMenu) // 메인메뉴 이미지의 불값이 트루가 되면 메인메뉴 이미지 렌더 및 셀렉트 아이콘 렌더
	{
		_infoUI[0].img->render(dc, CAMERAMANAGER->getX() +_infoUI[0].rc.left, CAMERAMANAGER->getY() + _infoUI[0].rc.top);
		_infoUI[1].img->render(dc, CAMERAMANAGER->getX() + _infoUI[1].rc.left, CAMERAMANAGER->getY() + _infoUI[1].rc.top);
		_infoUI[2].img->render(dc, CAMERAMANAGER->getX() + _infoUI[2].rc.left, CAMERAMANAGER->getY() + _infoUI[2].rc.top);

		SetBkMode(dc, TRANSPARENT);
		SetTextColor(dc, WHITE);
		for (int i = 0; i < 3; ++i)
		{
			TextOut(dc, CAMERAMANAGER->getX() + 55, CAMERAMANAGER->getY() +55 + 20 * i, _mainMenu[i].c_str(), strlen(_mainMenu[i].c_str()));
			IMAGEMANAGER->findImage("selectIcon")->render(dc, CAMERAMANAGER->getX()+ 45 , CAMERAMANAGER->getY() +65 + 20 * _selectNum - 6);
		}
	}

	//if (_infoUI[0].isSelcet) // 메인 메뉴에서 _infoUI[0] 배열 (도구) 가 선택되어 트루가 되면 도구상자 UI 렌더
	//{
	//	IMAGEMANAGER->findImage("도구상자")->render(dc, _infoUI[3].rc.left, _infoUI[3].rc.top);
	//	SetBkMode(dc, TRANSPARENT);
	//	SetTextColor(dc, WHITE);
	//	
	//	TextOut(dc, CAMERAMANAGER->getX() +  80, CAMERAMANAGER->getY()+ 60 , _mainMenu[3].c_str(), strlen(_mainMenu[3].c_str()));
	//	IMAGEMANAGER->findImage("selectIcon")->render(dc, CAMERAMANAGER->getX() + 70, CAMERAMANAGER->getY() +100 + 20 * _selectNum - 6);
	//	
	//}
	//

	//if (_infoUI[1].isSelcet)
	//{
	//	IMAGEMANAGER->findImage("pokeinfo")->render(dc, _infoUI[4].rc.left, _infoUI[4].rc.top);
	//	SetBkMode(dc, TRANSPARENT);
	//	SetTextColor(dc, WHITE);
	//
	//	TextOut(dc, CAMERAMANAGER->getX() + 80, CAMERAMANAGER->getY() + 60, _mainMenu[3].c_str(), strlen(_mainMenu[3].c_str()));
	//	IMAGEMANAGER->findImage("selectIcon")->render(dc, CAMERAMANAGER->getX() + 70, CAMERAMANAGER->getY() + 100 + 20 * _selectNum - 6);
	//
	//}
}

