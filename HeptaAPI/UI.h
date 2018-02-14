#pragma once
#include "gameNode.h"

struct InfoUI
{
	RECT rc;
	image* img;
	BOOL isSelcet;
};

class UI : public gameNode
{

private:
	//������ ��� ��Ʈ��Ʈ
	InfoUI _infoUI[10];

	// �÷��̾ ���� Ű�� ������ �޴� �����̸� ����� �Ұ�
	bool _isMenu;
	// �޴� ������ �� ������� �޴� ���� ����
	int _selectNum;
	// �޴� �̸� ��Ʈ��
	string _mainMenu[10];

public:
	UI();
	~UI();

	HRESULT init();
	void release();
	void update();
	void render();


};

