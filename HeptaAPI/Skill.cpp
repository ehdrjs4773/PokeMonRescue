#include "stdafx.h"
#include "Skill.h"



Skill::Skill()
{
}


Skill::~Skill()
{


}


 HRESULT Skill::init()
{
	 _skill.count = 0;
	 _skill.currentFramex = 0;
	 _skill.name = NULL;
	 _skill.x = 0;
	 _skill.y = 0;
	 _skill.rc = RectMakeCenter(_skill.x, _skill.y, _skill.image.getFrameWidth(), _skill.image.getFrameHeight());



	 return S_OK;
}

 void Skill::release()
{


}

 void Skill::update() 
{


}

 void Skill::render() 
{


}
 void Skill::setSkillEffect(char* name, int x, int y)
 {
	 IMAGEMANAGER->findImage(name)->frameRender(getMemDC(), x, y, _skill.currentFramex, 1);
 }