#include "enemyManager.h"



void enemyManager::imageInit()
{

	_chicoName.attackImage = "CHICORITA_ATTACK";
	_chicoName.idleImage= "CHICORITA_IDLE";
	_chicoName.moveImage = "CHICORITA_MOVE";
	_chicoName.hurtImage= "CHICORITA_HURTS";

	IMAGEMANAGER->addFrameImage(_chicoName.idleImage, ".//enemyImage//Chicorita_Idle.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_chicoName.moveImage, ".//enemyImage//Chicorita_Move.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_chicoName.attackImage, ".//enemyImage//Chicorita_Move.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_chicoName.hurtImage, ".//enemyImage//Chicorita_Hurts.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));


	_dandegiName.idleImage = "DANDEGI_IDLE";
	_dandegiName.moveImage = "DANDEGI_MOVE";
	_dandegiName.attackImage = "DANDEGI_ATTACK";
	_dandegiName.hurtImage = "DANDEGI_HURTS";

	IMAGEMANAGER->addFrameImage(_dandegiName.idleImage, ".//enemyImage//Dandegi_Idle.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_dandegiName.moveImage, ".//enemyImage//Dandegi_Move.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_dandegiName.attackImage, ".//enemyImage//Dandegi_Attack.BMP", 288, 576, 4,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_dandegiName.hurtImage, ".//enemyImage//Dandegi_Hurts.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));



	_polygonName.idleImage = "POLYGON_IDLE";
	_polygonName.moveImage = "POLYGON_MOVE";
	_polygonName.attackImage = "POLYGON_ATTACK";
	_polygonName.hurtImage = "POLYGON_HURTS";

	IMAGEMANAGER->addFrameImage(_polygonName.idleImage, ".//enemyImage//Polygon_Idle.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_polygonName.moveImage, ".//enemyImage//Polygon_Move.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_polygonName.attackImage, ".//enemyImage//Polygon_Attack.BMP", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_polygonName.hurtImage, ".//enemyImage//Polygon_Hurts.BMP", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));


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

}
