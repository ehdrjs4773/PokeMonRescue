#include "stdafx.h"
#include "Skill.h"



Skill::Skill()
{
}


Skill::~Skill()
{


}


 HRESULT Skill::init(char* name, int x, int y)
{
	 _skill.count = 0;
	 _skill.currentFramex = 0;
	 _skill.name = name;
	 _skill.x = x;
	 _skill.y = y;
	 _skill.rc = RectMakeCenter(_skill.x, _skill.y, _skill.image->getFrameWidth(), _skill.image->getFrameHeight());

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