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

	//리자몽
	IMAGEMANAGER->addFrameImage("리자몽_idle", ".\\bmps\\pokemon_state\\리자몽_idle.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//기본상태
	IMAGEMANAGER->addFrameImage("리자몽_move", ".\\bmps\\pokemon_state\\리자몽_move.bmp"
		, 0, 0, 288, 576, 4, 8, false, true, RGB(255, 0, 255));								//움직임
	IMAGEMANAGER->addFrameImage("리자몽_attack", ".\\bmps\\pokemon_state\\리자몽_attack.bmp"
		, 0, 0, 288, 576, 4, 8, false, true, RGB(255, 0, 255));								//공격
	IMAGEMANAGER->addFrameImage("리자몽_specialAttack", ".\\bmps\\pokemon_state\\리자몽_specialAttack.bmp"
		, 0, 0, 144, 576, 2, 8, false, true, RGB(255, 0, 255));								//스페셜공격
	IMAGEMANAGER->addFrameImage("리자몽_hurt", ".\\bmps\\pokemon_state\\리자몽_hurt.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//피격

}