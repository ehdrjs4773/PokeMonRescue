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
	//유아이 사용 스트럭트
	InfoUI _infoUI[10];

	// 플레이어가 지정 키를 누르면 메뉴 유아이를 띄워줄 불값
	bool _isMenu;
	// 메뉴 유아이 가 띄워지면 메뉴 선택 변수
	int _selectNum;
	// 메뉴 이름 스트링
	string _mainMenu[10];

public:
	UI();
	~UI();

	HRESULT init();
	void release();
	void update();
	void render();


};

