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
	_infoUI[3].img = IMAGEMANAGER->addImage("��������", ".\\bmps\\UI\\�����޴�UI.bmp", 267, 278, false, true, MAGENTA);

	IMAGEMANAGER->addImage("selectIcon", ".\\bmps\\UI\\selectIcon.bmp", 7, 7, false, true, MAGENTA);
	

	_infoUI[0].rc = RectMakeCenter(100, 100, _infoUI[0].img->getWidth(), _infoUI[0].img->getHeight());
	_infoUI[1].rc = RectMakeCenter(325, 100, _infoUI[1].img->getWidth(), _infoUI[1].img->getHeight());
	_infoUI[2].rc = RectMakeCenter(240, 300, _infoUI[2].img->getWidth(), _infoUI[2].img->getHeight());
	_infoUI[3].rc = RectMake(50, 50, _infoUI[3].img->getWidth(), _infoUI[3].img->getHeight());


	_mainMenu[0] = "����";
	_mainMenu[1] = "��";
	_mainMenu[2] = "�Ƿڸ���Ʈ";
	//���� �� ����
	_mainMenu[3] = "��������";

	_isMenu = false;
	
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
	//�÷��̾��� ���� Ű�� ���� ��� UI ���� '�ϴ�' ����Ű�� ���
	//�׸��� ����ó��
	if (!_isMenu && !_infoUI[0].isSelcet && !_infoUI[1].isSelcet && !_infoUI[2].isSelcet)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_isMenu = true;					//X Ű�� ������ �޴� �������� �Ұ��� Ʈ�簡 �ȴ�.
		}
		
	}
	

	if (_isMenu || _infoUI[0].isSelcet)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))		// �޴� â���� UP Ű�� ������ ����Ʈ �������� ���Ʒ��� �����δ�.
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

		if (KEYMANAGER->isOnceKeyDown('X'))			//����Ʈ ������ �����ӿ� �ѹ��� �־ X Ű�� ������ �� �޴��� �����ϰ� �ȴ�.
		{
			if (_selectNum == 0)
			{
				_infoUI[0].isSelcet = true;
				_isMenu = false;
			}
			else if (_selectNum == 1)
			{
				_infoUI[1].isSelcet = true;
				_isMenu = false;
			}
			else
			{
				_infoUI[2].isSelcet = true;
				_isMenu = false;
			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown('C'))			// �÷��̾��� ���� Ű�� ������ �ڷ� ���� ó��(������ �ӽ÷� �ڷΰ��� Ű�� �ο�)
	{
		_isMenu = false;
		if (!_isMenu && _infoUI[0].isSelcet || _infoUI[1].isSelcet || _infoUI[2].isSelcet)
		{
			_infoUI[0].isSelcet = false;
			_infoUI[1].isSelcet = false;
			_infoUI[2].isSelcet = false;

			_isMenu = true;
		}
	}

}

void UI::render() 
{
	if (_isMenu) // ���θ޴� �̹����� �Ұ��� Ʈ�簡 �Ǹ� ���θ޴� �̹��� ���� �� ����Ʈ ������ ����
	{
		IMAGEMANAGER->findImage("�����⺻�޴�")->render(getMemDC(), _infoUI[0].rc.left, _infoUI[0].rc.top);
		IMAGEMANAGER->findImage("��ǥ��")->render(getMemDC(), _infoUI[1].rc.left, _infoUI[1].rc.top);
		IMAGEMANAGER->findImage("��ǥ��")->render(getMemDC(), _infoUI[2].rc.left, _infoUI[2].rc.top);

		SetBkMode(getMemDC(), TRANSPARENT);
		SetTextColor(getMemDC(), WHITE);
		for (int i = 0; i < 3; ++i)
		{
			TextOut(getMemDC(), 55, 55 + 20 * i, _mainMenu[i].c_str(), strlen(_mainMenu[i].c_str()));
			IMAGEMANAGER->findImage("selectIcon")->render(getMemDC(), 45 , 65 + 20 * _selectNum - 6);
		}
	}

	if (_infoUI[0].isSelcet) // ���� �޴����� _infoUI[0] �迭 (����) �� ���õǾ� Ʈ�簡 �Ǹ� �������� UI ����
	{
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), _infoUI[3].rc.left, _infoUI[3].rc.top);
		SetBkMode(getMemDC(), TRANSPARENT);
		SetTextColor(getMemDC(), WHITE);
		
		TextOut(getMemDC(), 80, 60 , _mainMenu[3].c_str(), strlen(_mainMenu[3].c_str()));
		IMAGEMANAGER->findImage("selectIcon")->render(getMemDC(), 70, 100 + 20 * _selectNum - 6);
		
	}

}

