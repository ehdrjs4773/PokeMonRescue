#pragma once
#include "gameNode.h"
#include "player.h"


class player;
class Stage;

enum type				// 스킬 타입 지정
{
	type_Nomal,         // 노말 타입
	type_Fire,			// 불 타입
	type_Ice,			// 얼음 타입
	type_Water,			// 물 타입
	type_Electric,		// 전기 타입
	type_Psychic,		// 에스퍼 타입
	type_Grass,			// 풀 타입
	type_Earth,			// 땅 타입
	type_Fly,			// 비행 타입
	type_Ghost,			// 고스트 타입
	type_Dragoon,		// 드래곤 타입
	type_Dark,			// 악 타입
	type_Fairy,			// 페어리 타입
	type_Steel,			// 강철 타입
	type_Rock,			// 바위 타입
	type_bug,			// 벌레 타입
	type_Sprattle,		// 격투 타입
	type_Poison,			// 독 타입
	type_End
};



struct skillInfo
{
	char* name;				// 스킬 이름
	image* image;			// 스킬 이미지
	RECT rc;			    // 스킬 박스 생성
	float x;				// 스킬 x 좌표
	float y;				// 스킬 y 좌표
	int count;				// 스킬 카운트
	int currentFramex;		// 스킬 프레임 
	type type;				// 스킬 타입
	float damege;			// 스킬 대미지
};




class Skill : public gameNode
{
private :
	
	player* _player;
	Stage* _stage;
	skillInfo _skill;
	

public:
	
	virtual HRESULT init(char* name, int x, int y, type type);
	virtual void release();
	virtual void update();
	virtual void render();


	Skill();
	~Skill();

	void setStageMemoryAdressLink(Stage* stages) { _stage = stages; }
	void setPlayerMemoryAdressLink(player* plays) { _player = plays; }


};

