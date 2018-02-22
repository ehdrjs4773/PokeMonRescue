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
	_infoUI[0].img = IMAGEMANAGER->findImage("�����⺻�޴�");
	_infoUI[1].img = IMAGEMANAGER->findImage("��ǥ��");
	_infoUI[2].img = IMAGEMANAGER->findImage("��ǥ��");
	_infoUI[3].img = IMAGEMANAGER->findImage("��������");



	_infoUI[0].rc = RectMakeCenter(100, 100, _infoUI[0].img->getWidth(), _infoUI[0].img->getHeight());
	_infoUI[1].rc = RectMakeCenter(325, 100, _infoUI[1].img->getWidth(), _infoUI[1].img->getHeight());
	_infoUI[2].rc = RectMakeCenter(240, 300, _infoUI[2].img->getWidth(), _infoUI[2].img->getHeight());
	_infoUI[3].rc = RectMake(50, 50, _infoUI[3].img->getWidth(), _infoUI[3].img->getHeight());


	_mainMenu[0] = "����";
	_mainMenu[1] = "��";
	_mainMenu[2] = "�Ƿڸ���Ʈ";
	//���� �� ����
	_mainMenu[3] = "��������";

	_mainMenu[4] = "��";

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
	//�÷��̾��� ���� Ű�� ���� ��� UI ���� '�ϴ�' ����Ű�� ���
	//�׸��� ����ó��

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
		if(!_isMenu)
		{
			SCENEMANAGER->changeParent();
		}
	}

}

void UI::render() 
{

	HDC dc = CAMERAMANAGER->getMemDC();
	if (_isMenu) // ���θ޴� �̹����� �Ұ��� Ʈ�簡 �Ǹ� ���θ޴� �̹��� ���� �� ����Ʈ ������ ����
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

	//if (_infoUI[0].isSelcet) // ���� �޴����� _infoUI[0] �迭 (����) �� ���õǾ� Ʈ�簡 �Ǹ� �������� UI ����
	//{
	//	IMAGEMANAGER->findImage("��������")->render(dc, _infoUI[3].rc.left, _infoUI[3].rc.top);
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

