#include "gameNode.h"
#pragma once

const int Opening_Speed = 3;


enum OpeningScene
{
	Opening_One,
	Opening_Two,
	Opening_Three,
	Opening_Four,
	Opening_Five,
	Opening_END
};

class oPeningSelect : public gameNode
{
private:
	OpeningScene _Opening;

	string _startingMonster[8];
	int _selectNum;
	int _dialogueTime;
	bool _isSelect;


public:
	oPeningSelect();
	~oPeningSelect();

	HRESULT init(void);
	void render(void);
	void update(void);
	void release(void);

	void keyControl(void);

};

