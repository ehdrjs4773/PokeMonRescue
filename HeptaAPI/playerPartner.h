#pragma once
#include "gameNode.h"

class playerPartner : public gameNode
{
private:
	

public:
	playerPartner();
	~playerPartner();

	HRESULT init();
	HRESULT init(string charName , float startX , float startY);
	void release();
	void update();
	void render();
};

