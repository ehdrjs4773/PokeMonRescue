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
		
																							
	// 상점 이미지 초기화

	IMAGEMANAGER->addImage("shopMenu", ".\\bmps\\npc\\shopmenu.bmp", 175, 194, false, true, MAGENTA);
	IMAGEMANAGER->addImage("대화창", ".\\bmps\\npc\\대화창.bmp", 450, 98, false, true, MAGENTA);
	IMAGEMANAGER->addImage("상점씬", ".\\bmps\\npc\\상점씬.bmp", 450, 326, false, true, MAGENTA);
	IMAGEMANAGER->addImage("point", ".\\bmps\\npc\\포인트.bmp", 14, 21, false, true, MAGENTA);
	IMAGEMANAGER->addImage("shop", ".\\bmps\\npc\\shop.bmp", 156, 98, false, true, MAGENTA);


	//	마을 이미지 초기화
	IMAGEMANAGER->addImage("town", ".\\bmps\\map\\townmap.bmp", 480, 360, false, true, MAGENTA);
	IMAGEMANAGER->addImage("townMagenta", ".\\bmps\\map\\townmapcrash.bmp", 480, 360, false, true, MAGENTA);
	IMAGEMANAGER->addImage("saveTown", ".\\bmps\\map\\savemap.bmp", 480, 360, false, true, MAGENTA);
	IMAGEMANAGER->addImage("saveTownMagenta", ".\\bmps\\map\\savemapcrash.bmp", 480, 360, false, true, MAGENTA);


	// 던전용 이미지 초기화

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
	
	//포켓몬 이미지
	IMAGEMANAGER->addFrameImage("리자몽_idle", ".\\bmps\\pokemon_state\\리자몽_idle.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//기본상태
	IMAGEMANAGER->addFrameImage("리자몽_move",".\\bmps\\pokemon_state\\리자몽_move.bmp"
		, 0, 0, 288, 576, 4, 8, false, true, RGB(255, 0, 255));								//움직임
	IMAGEMANAGER->addFrameImage("리자몽_attack", ".\\bmps\\pokemon_state\\리자몽_attack.bmp"
		, 0, 0, 288, 576, 4, 8, false, true, RGB(255, 0, 255));								//공격
	IMAGEMANAGER->addFrameImage("리자몽_specialAttack",".\\bmps\\pokemon_state\\리자몽_specialAttack.bmp"
		, 0, 0, 144, 576, 2, 8, false, true, RGB(255, 0, 255));								//스페셜공격
	IMAGEMANAGER->addFrameImage("리자몽_hurt", ".\\bmps\\pokemon_state\\리자몽_hurt.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//피격

	IMAGEMANAGER->addFrameImage("지라치_idle", ".\\bmps\\pokemon_state\\지라치_idle.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//기본상태
	IMAGEMANAGER->addFrameImage("지라치_move", ".\\bmps\\pokemon_state\\지라치_move.bmp"
		, 0, 0, 216, 576, 3, 8, false, true, RGB(255, 0, 255));								//움직임
	IMAGEMANAGER->addFrameImage("지라치_attack", ".\\bmps\\pokemon_state\\지라치_attack.bmp"
		, 0, 0, 144, 576, 2, 8, false, true, RGB(255, 0, 255));								//공격
	IMAGEMANAGER->addFrameImage("지라치_specialAttack", ".\\bmps\\pokemon_state\\지라치_specialAttack.bmp"
		, 0, 0, 144, 576, 2, 8, false, true, RGB(255, 0, 255));								//스페셜공격
	IMAGEMANAGER->addFrameImage("지라치_hurt", ".\\bmps\\pokemon_state\\지라치_hurt.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//피격


	// UI 이미지 초기화 

	IMAGEMANAGER->addImage("마을기본메뉴", ".\\bmps\\UI\\마을기본메뉴UI.bmp", 148, 118, false, true, MAGENTA);
	IMAGEMANAGER->addImage("맵표시", ".\\bmps\\UI\\맵표시UI.bmp", 267, 58, false, true, MAGENTA);
	IMAGEMANAGER->addImage("돈표시", ".\\bmps\\UI\\하단돈표시UI.bmp", 416, 88, false, true, MAGENTA);
	IMAGEMANAGER->addImage("도구상자", ".\\bmps\\UI\\도구메뉴UI.bmp", 267, 278, false, true, MAGENTA);
	IMAGEMANAGER->addImage("selectIcon", ".\\bmps\\UI\\selectIcon.bmp", 7, 7, false, true, MAGENTA);

	//포켓인포
	IMAGEMANAGER->addImage("pokeinfo", ".\\bmps\\UI\\Pokeinfo.bmp", 267, 278, false, true, MAGENTA);


}