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

	//���ڸ�
	IMAGEMANAGER->addFrameImage("���ڸ�_idle", ".\\bmps\\pokemon_state\\���ڸ�_idle.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//�⺻����
	IMAGEMANAGER->addFrameImage("���ڸ�_move", ".\\bmps\\pokemon_state\\���ڸ�_move.bmp"
		, 0, 0, 288, 576, 4, 8, false, true, RGB(255, 0, 255));								//������
	IMAGEMANAGER->addFrameImage("���ڸ�_attack", ".\\bmps\\pokemon_state\\���ڸ�_attack.bmp"
		, 0, 0, 288, 576, 4, 8, false, true, RGB(255, 0, 255));								//����
	IMAGEMANAGER->addFrameImage("���ڸ�_specialAttack", ".\\bmps\\pokemon_state\\���ڸ�_specialAttack.bmp"
		, 0, 0, 144, 576, 2, 8, false, true, RGB(255, 0, 255));								//����Ȱ���
	IMAGEMANAGER->addFrameImage("���ڸ�_hurt", ".\\bmps\\pokemon_state\\���ڸ�_hurt.bmp"
		, 0, 0, 72, 576, 1, 8, false, true, RGB(255, 0, 255));								//�ǰ�

}