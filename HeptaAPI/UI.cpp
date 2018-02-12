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
	_infoUI[0].img = IMAGEMANAGER->addImage("�����⺻�޴�", ".\\bmps\\UI\\�����⺻�޴�UI.bmp", 148, 118, false, true, MAGENTA);
	_infoUI[1].img = IMAGEMANAGER->addImage("��ǥ��", ".\\bmps\\UI\\��ǥ��UI.bmp", 267, 58, false, true, MAGENTA);
	_infoUI[2].img = IMAGEMANAGER->addImage("��ǥ��", ".\\bmps\\UI\\�ϴܵ�ǥ��UI.bmp", 416, 88, false, true, MAGENTA);
	

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
		IMAGEMANAGER->findImage("�����⺻�޴�")->render(getMemDC(), _infoUI[0].rc.left, _infoUI[0].rc.top);
		IMAGEMANAGER->findImage("��ǥ��")->render(getMemDC(), _infoUI[1].rc.left, _infoUI[1].rc.top);
		IMAGEMANAGER->findImage("��ǥ��")->render(getMemDC(), _infoUI[2].rc.left, _infoUI[2].rc.top);
	}
}

