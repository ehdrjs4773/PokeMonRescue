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
	_infoUI[0].img = IMAGEMANAGER->addImage("마을기본메뉴", ".\\bmps\\UI\\마을기본메뉴UI.bmp", 148, 118, false, true, MAGENTA);
	_infoUI[1].img = IMAGEMANAGER->addImage("맵표시", ".\\bmps\\UI\\맵표시UI.bmp", 267, 58, false, true, MAGENTA);
	_infoUI[2].img = IMAGEMANAGER->addImage("돈표시", ".\\bmps\\UI\\하단돈표시UI.bmp", 416, 88, false, true, MAGENTA);
	

	_infoUI[0].rc = RectMakeCenter(100, 100, _infoUI[0].img->getWidth(), _infoUI[0].img->getHeight());
	_infoUI[1].rc = RectMakeCenter(325, 100, _infoUI[1].img->getWidth(), _infoUI[1].img->getHeight());
	_infoUI[2].rc = RectMakeCenter(240, 300, _infoUI[2].img->getWidth(), _infoUI[2].img->getHeight());


	_isMenu = true;


	return S_OK;
}

void UI::release()
{

}

void UI::update() 
{

}

void UI::render() 
{
	if (_isMenu)
	{
		IMAGEMANAGER->findImage("마을기본메뉴")->render(getMemDC(), _infoUI[0].rc.left, _infoUI[0].rc.top);
		IMAGEMANAGER->findImage("맵표시")->render(getMemDC(), _infoUI[1].rc.left, _infoUI[1].rc.top);
		IMAGEMANAGER->findImage("돈표시")->render(getMemDC(), _infoUI[2].rc.left, _infoUI[2].rc.top);
	}
}

