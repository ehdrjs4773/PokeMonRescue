#include "stdafx.h"
#include "Skill.h"



Skill::Skill()
{
}


Skill::~Skill()
{


}


 HRESULT Skill::init(char* name, int x, int y, type type)
{
	 _skill.count = 0;															// 프레임 카운트(쓸일없는것같음)
	 _skill.currentFramex = 0;													// 프레임 x (마찬가지 쓸일없음)
	 _skill.name = name;														// 스킬 이름
	 _skill.x = x;																// 스킬 좌표	X
	 _skill.y = y;																// 스킬 좌표 y
	 _skill.type = type;														// 포켓몬 속성 대입
	 _skill.rc = RectMakeCenter(_skill.x, _skill.y,			
		 _skill.image->getFrameWidth(), _skill.image->getFrameHeight());		// 스킬 렉트	

	 //_skill.damege = ?? 현재 포켓몬 정보의 특수 대미지를 가져와야함.

	 return S_OK;
}

 void Skill::release()
{

}

 void Skill::update() 
{
	//_skill.count++;
	//
	//if (_skill.count % 10 == 0)
	//{
	//	 if (_skill.currentFramex > _skill.image->getMaxFrameX()) _skill.currentFramex = 0;
	//	 _skill.currentFramex++;
	//	 _skill.count = 0;
	//}
}

 void Skill::render() 
{
	 //IMAGEMANAGER->findImage(_skill.name)->frameRender(getMemDC(), _skill.x, _skill.y, _skill.currentFramex, 1);
}