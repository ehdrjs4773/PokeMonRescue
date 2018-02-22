#include "enemyManager.h"
void enemyManager::imageInit()
{

	_chicoName.pokemonName	=	"ġ�ڸ�Ÿ";
	_chicoName.attackImage	=	"CHICORITA_ATTACK";
	_chicoName.idleImage	=	"CHICORITA_IDLE";
	_chicoName.moveImage	=	"CHICORITA_MOVE";
	_chicoName.hurtImage	=	"CHICORITA_HURTS";

	IMAGEMANAGER->addFrameImage(_chicoName.idleImage, ".//enemyImage//Chicorita_Idle.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_chicoName.moveImage, ".//enemyImage//Chicorita_Move.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_chicoName.attackImage, ".//enemyImage//Chicorita_Move.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_chicoName.hurtImage, ".//enemyImage//Chicorita_Hurts.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));


	_dandegiName.pokemonName =	"�ܵ���";
	_dandegiName.idleImage	 =	"DANDEGI_IDLE";
	_dandegiName.moveImage	 =	"DANDEGI_MOVE";
	_dandegiName.attackImage =	"DANDEGI_ATTACK";
	_dandegiName.hurtImage	 =	"DANDEGI_HURTS";

	IMAGEMANAGER->addFrameImage(_dandegiName.idleImage, ".//enemyImage//Dandegi_Idle.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_dandegiName.moveImage, ".//enemyImage//Dandegi_Move.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_dandegiName.attackImage, ".//enemyImage//Dandegi_Attack.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_dandegiName.hurtImage, ".//enemyImage//Dandegi_Hurts.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ܵ��⽺ų", ".//enemyImage//Dandegi_Skill.BMP", 120, 960, 2, 8, true, true, RGB(255, 0, 255));


	_polygonName.pokemonName =	 "������";
	_polygonName.idleImage	 =	 "POLYGON_IDLE";
	_polygonName.moveImage	 =	 "POLYGON_MOVE";
	_polygonName.attackImage =	 "POLYGON_ATTACK";
	_polygonName.hurtImage	 =	 "POLYGON_HURTS";

	IMAGEMANAGER->addFrameImage(_polygonName.idleImage, ".//enemyImage//Polygon_Idle.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_polygonName.moveImage, ".//enemyImage//Polygon_Move.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_polygonName.attackImage, ".//enemyImage//Polygon_Attack.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_polygonName.hurtImage, ".//enemyImage//Polygon_Hurts.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));

	_purinName.pokemonName = "Ǫ��";
	_purinName.idleImage = "PURIN_IDLE";
	_purinName.moveImage = "PURIN_MOVE";
	_purinName.attackImage = "PURIN_ATTACK";
	_purinName.hurtImage = "PURIN_HURTS";

	IMAGEMANAGER->addFrameImage(_purinName.idleImage, ".//enemyImage//Purin_Idle.BMP", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_purinName.moveImage, ".//enemyImage//Purin_Move.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_purinName.attackImage, ".//enemyImage//Purin_Attack.BMP", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_purinName.hurtImage, ".//enemyImage//Purin_Hurts.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));


	//������ �̹��� ����

	//�׶󿡳�
	_graenaName.pokemonName = "�׶󿡳�";
	_graenaName.idleImage = "GRAENA_IDLE";
	_graenaName.moveImage = "GRAENA_MOVE";
	_graenaName.attackImage = "GRAENA_ATTACK";
	_graenaName.hurtImage = "GRAENA_HURTS";

	IMAGEMANAGER->addFrameImage(_graenaName.idleImage, ".//enemyImage//�׶󿡳�IDLE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_graenaName.moveImage, ".//enemyImage//�׶󿡳�MOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_graenaName.attackImage, ".//enemyImage//�׶󿡳�ATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_graenaName.hurtImage, ".//enemyImage//�׶󿡳�HURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//�׶󿡳�


	//��ī����
	_rukarioName.pokemonName = "��ī����";
	_rukarioName.idleImage = "RUKARIO_IDLE";
	_rukarioName.moveImage = "RUKARIO_MOVE";
	_rukarioName.attackImage = "RUKARIO_ATTACK";
	_rukarioName.hurtImage = "RUKARIO_HURTS";

	IMAGEMANAGER->addFrameImage(_rukarioName.idleImage, ".//enemyImage//��ī����IDLE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_rukarioName.moveImage, ".//enemyImage//��ī����MOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_rukarioName.attackImage, ".//enemyImage//��ī����ATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_rukarioName.hurtImage, ".//enemyImage//��ī����HURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//��ī����


	//��Ű
	_mankeyName.pokemonName = "������";
	_mankeyName.idleImage = "MANKEY_IDLE";
	_mankeyName.moveImage = "MANKEY_MOVE";
	_mankeyName.attackImage = "MANKEY_ATTACK";
	_mankeyName.hurtImage = "MANKEY_HURTS";

	IMAGEMANAGER->addFrameImage(_mankeyName.idleImage, ".//enemyImage//��ŰIDLE.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_mankeyName.moveImage, ".//enemyImage//��ŰMOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_mankeyName.attackImage, ".//enemyImage//��ŰATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_mankeyName.hurtImage,  ".//enemyImage//��ŰHURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//��Ű


	//������
	_tanguriName.pokemonName = "�ֱ���";
	_tanguriName.idleImage = "TANGURI_IDLE";
	_tanguriName.moveImage = "TANGURI_MOVE";
	_tanguriName.attackImage = "TANGURI_ATTACK";
	_tanguriName.hurtImage = "TANGURI_HURTS";

	IMAGEMANAGER->addFrameImage(_tanguriName.idleImage, ".//enemyImage//�ֱ���IDLE.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_tanguriName.moveImage, ".//enemyImage//�ֱ���MOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_tanguriName.attackImage, ".//enemyImage//�ֱ���ATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_tanguriName.hurtImage, ".//enemyImage//�ֱ���HURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//������

	//����Ű��
	_electivireName.pokemonName = "����Ű��";
	_electivireName.idleImage = "ELECTIVIRE_IDLE";
	_electivireName.moveImage = "ELECTIVIRE_MOVE";
	_electivireName.attackImage = "ELECTIVIRE_ATTACK";
	_electivireName.hurtImage = "ELECTIVIRE_HURTS";

	IMAGEMANAGER->addFrameImage(_electivireName.idleImage, ".//enemyImage//����Ű��IDLE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_electivireName.moveImage, ".//enemyImage//����Ű��MOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_electivireName.attackImage, ".//enemyImage//����Ű��ATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_electivireName.hurtImage, ".//enemyImage//����Ű��HURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//����Ű��


	//����Ű��
	_bossName.pokemonName = "�ܵ���";
	_bossName.idleImage = "LEKUJA_IDLE";
	_bossName.moveImage = "ELECTIVIRE_MOVE";
	_bossName.attackImage = "LEKUJA_ATTACK";
	_bossName.hurtImage = "LEKUJA_HURTS";

	IMAGEMANAGER->addFrameImage(_bossName.idleImage, ".//enemyImage//LEKUJA_IDLEbmp.bmp", 360, 960, 3,
		8, true, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(_bossName.attackImage, ".//enemyImage//LEKUJA_Attack.bmp", 240, 960, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_bossName.hurtImage, ".//enemyImage//LEKUJA_HURTS.bmp", 120, 960, 1,
		8, true, true, RGB(255, 0, 255));




	IMAGEMANAGER->addFrameImage("Sleep", ".//enemyImage//LEKUJA_SLEEP.bmp", 120, 240, 1,
		2, true, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("HyperBeam", ".//enemyImage//LEKUJA_HYPERBEAM.bmp", 360, 120, 3,
		1, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Beam", ".//enemyImage//HYPERBEAM.bmp", 120, 480, 1,
		4, true, true, RGB(255, 0, 255));

	//����Ű��



}