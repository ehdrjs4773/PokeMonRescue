#include "stdafx.h"
#include "playGround.h"



void playGround::imageInitaialization(void)
{

	// 스킬 이미지 초기화

	EFFECTMANAGER->addEffect("ember", ".\\bmps\\skill\\ember.bmp", 192, 19, 16, 19, 1.0f, 0.1f ,1);
	EFFECTMANAGER->addEffect("blastkick", ".\\bmps\\skill\\blastkick.bmp", 630, 40, 63, 40, 1.0f, 0.5f, 1);
	EFFECTMANAGER->addEffect("fireMeteo", ".\\bmps\\skill\\fireMeteo.bmp", 4466, 140, 154, 140, 1.0f, 0.5f, 1);
	EFFECTMANAGER->addEffect("iceShot", ".\\bmps\\skill\\iceshot.bmp", 320, 48, 32, 48, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("overhite", ".\\bmps\\skill\\overhite.bmp", 384, 42, 12, 1, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("FireT", ".\\bmps\\skill\\불대문자.bmp", 1560, 52, 60, 52, 1.0f, 0.5f, 1);


	// npc 이미지 초기화

	IMAGEMANAGER->addImage("gandy", ".\\bmps\\npc\\가디.bmp", 16, 23, false, true, MAGENTA);
	IMAGEMANAGER->addImage("windy", ".\\bmps\\npc\\윈디.bmp", 22, 30, false, true, MAGENTA);

}