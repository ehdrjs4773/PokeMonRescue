#pragma once
#include "gameNode.h"
#include "Npc.h"
#include "StageScene.h"
#include "player.h"
#include "oPeningMovie.h"
#include "Pokemon.h"
#include "shopchildren.h"

class playGround : public gameNode
{
private:
	player* _player;
	pokemon* _pokemon;

public:
	virtual HRESULT init(void);		//초기화 함수
	virtual void release(void);		//메모리 관련 해제
	virtual void update(void);		//업데이트(연산)
	virtual void render(void);		//그려주는 함수

	virtual void imageInitaialization(void); // 이미지 초기화 함수
	playGround();
	~playGround();
};

