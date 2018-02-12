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
	InfoUI _infoUI[6];

	bool _isMenu;


public:
	UI();
	~UI();

	HRESULT init();
	void release();
	void update();
	void render();


};

