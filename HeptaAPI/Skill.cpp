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
	 _skill.count = 0;															// ������ ī��Ʈ(���Ͼ��°Ͱ���)
	 _skill.currentFramex = 0;													// ������ x (�������� ���Ͼ���)
	 _skill.name = name;														// ��ų �̸�
	 _skill.x = x;																// ��ų ��ǥ	X
	 _skill.y = y;																// ��ų ��ǥ y
	 _skill.type = type;														// ���ϸ� �Ӽ� ����
	 _skill.rc = RectMakeCenter(_skill.x, _skill.y,			
		 _skill.image->getFrameWidth(), _skill.image->getFrameHeight());		// ��ų ��Ʈ	

	 //_skill.damege = ?? ���� ���ϸ� ������ Ư�� ������� �����;���.

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