#include "stdafx.h"
#include "playGround.h"



void playGround::imageInitaialization(void)
{

	// ��ų �̹��� �ʱ�ȭ

	EFFECTMANAGER->addEffect("ember", ".\\bmps\\skill\\ember.bmp", 192, 19, 16, 19, 1.0f, 0.1f ,1);
	EFFECTMANAGER->addEffect("blastkick", ".\\bmps\\skill\\blastkick.bmp", 630, 40, 63, 40, 1.0f, 0.5f, 1);
	EFFECTMANAGER->addEffect("fireMeteo", ".\\bmps\\skill\\fireMeteo.bmp", 4466, 140, 154, 140, 1.0f, 0.5f, 1);
	EFFECTMANAGER->addEffect("iceShot", ".\\bmps\\skill\\iceshot.bmp", 320, 48, 32, 48, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("overhite", ".\\bmps\\skill\\overhite.bmp", 384, 42, 12, 1, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("FireT", ".\\bmps\\skill\\�Ҵ빮��.bmp", 1560, 52, 60, 52, 1.0f, 0.5f, 1);


	// npc �̹��� �ʱ�ȭ

	IMAGEMANAGER->addImage("gandy", ".\\bmps\\npc\\����.bmp", 16, 23, false, true, MAGENTA);
	IMAGEMANAGER->addImage("windy", ".\\bmps\\npc\\����.bmp", 22, 30, false, true, MAGENTA);
		
																							
	// ���� �̹��� �ʱ�ȭ

	IMAGEMANAGER->addImage("shopMenu", ".\\bmps\\npc\\shopmenu.bmp", 175, 194, false, true, MAGENTA);
	IMAGEMANAGER->addImage("��ȭâ", ".\\bmps\\npc\\��ȭâ.bmp", 450, 98, false, true, MAGENTA);
	IMAGEMANAGER->addImage("������", ".\\bmps\\npc\\������.bmp", 450, 326, false, true, MAGENTA);
	IMAGEMANAGER->addImage("point", ".\\bmps\\npc\\����Ʈ.bmp", 14, 21, false, true, MAGENTA);
	IMAGEMANAGER->addImage("shop", ".\\bmps\\npc\\shop.bmp", 156, 98, false, true, MAGENTA);


	//	���� �̹��� �ʱ�ȭ
	IMAGEMANAGER->addImage("town", ".\\bmps\\map\\townmap.bmp", 480, 360, false, true, MAGENTA);
	IMAGEMANAGER->addImage("townMagenta", ".\\bmps\\map\\townmapcrash.bmp", 480, 360, false, true, MAGENTA);
	IMAGEMANAGER->addImage("saveTown", ".\\bmps\\map\\savemap.bmp", 480, 360, false, true, MAGENTA);
	IMAGEMANAGER->addImage("saveTownMagenta", ".\\bmps\\map\\savemapcrash.bmp", 480, 360, false, true, MAGENTA);


	// ������ �̹��� �ʱ�ȭ

	IMAGEMANAGER->addFrameImage("tarrain0-0", ".//bmps//map//tarrain0//0.bmp", 384, 384, 16, 16, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("tarrain0-1", ".//bmps//map//tarrain0//1.bmp", 384, 384, 16, 16, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("tarrain0-2", ".//bmps//map//tarrain0//2.bmp", 384, 384, 16, 16, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("tarrain1-0", ".//bmps//map//tarrain1//0.bmp", 384, 384, 16, 16, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("tarrain1-1", ".//bmps//map//tarrain1//1.bmp", 384, 384, 16, 16, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("tarrain1-2", ".//bmps//map//tarrain1//2.bmp", 384, 384, 16, 16, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("tarrain2-0", ".//bmps//map//tarrain2//0.bmp", 384, 384, 16, 16, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("tarrain2-1", ".//bmps//map//tarrain2//1.bmp", 384, 384, 16, 16, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("tarrain2-2", ".//bmps//map//tarrain2//2.bmp", 384, 384, 16, 16, false, true, MAGENTA);

	IMAGEMANAGER->addFrameImage("minimap", ".//bmps//map//wallmini.bmp", 96, 96, 16, 16, true, true, MAGENTA);

	IMAGEMANAGER->addFrameImage("objectlist", ".//bmps//map//items.bmp", 240, 24, 10, 1, false, true, MAGENTA);
	IMAGEMANAGER->addImage("alphamap", ".\\bmps\\map\\usingalpha.bmp", 480, 360, true, true, MAGENTA);
	
	//���ϸ� �̹���
	IMAGEMANAGER->addFrameImage("���ڸ�_idle", ".\\bmps\\pokemon_state\\���ڸ�_idle.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//�⺻����
	IMAGEMANAGER->addFrameImage("���ڸ�_move",".\\bmps\\pokemon_state\\���ڸ�_move.bmp"
		, 0, 0, 288, 576, 4, 8, false, true, RGB(255, 0, 255));								//������
	IMAGEMANAGER->addFrameImage("���ڸ�_attack", ".\\bmps\\pokemon_state\\���ڸ�_attack.bmp"
		, 0, 0, 288, 576, 4, 8, false, true, RGB(255, 0, 255));								//����
	IMAGEMANAGER->addFrameImage("���ڸ�_specialAttack",".\\bmps\\pokemon_state\\���ڸ�_specialAttack.bmp"
		, 0, 0, 144, 576, 2, 8, false, true, RGB(255, 0, 255));								//����Ȱ���
	IMAGEMANAGER->addFrameImage("���ڸ�_hurt", ".\\bmps\\pokemon_state\\���ڸ�_hurt.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//�ǰ�

}