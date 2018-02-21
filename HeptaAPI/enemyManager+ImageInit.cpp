#include "enemyManager.h"
void enemyManager::imageInit()
{

	_chicoName.pokemonName	=	"치코리타";
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


	_dandegiName.pokemonName =	"단데기";
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
	IMAGEMANAGER->addFrameImage("단데기스킬", ".//enemyImage//Dandegi_Skill.BMP", 120, 960, 2, 8, true, true, RGB(255, 0, 255));


	_polygonName.pokemonName =	 "폴리곤";
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

	_purinName.pokemonName = "푸린";
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


	//건하의 이미지 영역

	//그라에나
	_graenaName.pokemonName = "그라에나";
	_graenaName.idleImage = "GRAENA_IDLE";
	_graenaName.moveImage = "GRAENA_MOVE";
	_graenaName.attackImage = "GRAENA_ATTACK";
	_graenaName.hurtImage = "GRAENA_HURTS";

	IMAGEMANAGER->addFrameImage(_graenaName.idleImage, ".//enemyImage//그라에나IDLE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_graenaName.moveImage, ".//enemyImage//그라에나MOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_graenaName.attackImage, ".//enemyImage//그라에나ATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_graenaName.hurtImage, ".//enemyImage//그라에나HURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//그라에나


	//루카리오
	_rukarioName.pokemonName = "루카리오";
	_rukarioName.idleImage = "RUKARIO_IDLE";
	_rukarioName.moveImage = "RUKARIO_MOVE";
	_rukarioName.attackImage = "RUKARIO_ATTACK";
	_rukarioName.hurtImage = "RUKARIO_HURTS";

	IMAGEMANAGER->addFrameImage(_rukarioName.idleImage, ".//enemyImage//루카리오IDLE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_rukarioName.moveImage, ".//enemyImage//루카리오MOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_rukarioName.attackImage, ".//enemyImage//루카리오ATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_rukarioName.hurtImage, ".//enemyImage//루카리오HURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//루카리오


	//망키
	_mankeyName.pokemonName = "성원숭";
	_mankeyName.idleImage = "MANKEY_IDLE";
	_mankeyName.moveImage = "MANKEY_MOVE";
	_mankeyName.attackImage = "MANKEY_ATTACK";
	_mankeyName.hurtImage = "MANKEY_HURTS";

	IMAGEMANAGER->addFrameImage(_mankeyName.idleImage, ".//enemyImage//망키IDLE.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_mankeyName.moveImage, ".//enemyImage//망키MOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_mankeyName.attackImage, ".//enemyImage//망키ATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_mankeyName.hurtImage,  ".//enemyImage//망키HURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//망키


	//탕구리
	_tanguriName.pokemonName = "텅구리";
	_tanguriName.idleImage = "TANGURI_IDLE";
	_tanguriName.moveImage = "TANGURI_MOVE";
	_tanguriName.attackImage = "TANGURI_ATTACK";
	_tanguriName.hurtImage = "TANGURI_HURTS";

	IMAGEMANAGER->addFrameImage(_tanguriName.idleImage, ".//enemyImage//텅구리IDLE.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_tanguriName.moveImage, ".//enemyImage//텅구리MOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_tanguriName.attackImage, ".//enemyImage//텅구리ATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_tanguriName.hurtImage, ".//enemyImage//텅구리HURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//탕구리

	//에레키블
	_electivireName.pokemonName = "에레키블";
	_electivireName.idleImage = "ELECTIVIRE_IDLE";
	_electivireName.moveImage = "ELECTIVIRE_MOVE";
	_electivireName.attackImage = "ELECTIVIRE_ATTACK";
	_electivireName.hurtImage = "ELECTIVIRE_HURTS";

	IMAGEMANAGER->addFrameImage(_electivireName.idleImage, ".//enemyImage//에레키블IDLE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_electivireName.moveImage, ".//enemyImage//에레키블MOVE.bmp", 216, 576, 3,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_electivireName.attackImage, ".//enemyImage//에레키블ATK.bmp", 144, 576, 2,
		8, true, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(_electivireName.hurtImage, ".//enemyImage//에레키블HURT.bmp", 72, 576, 1,
		8, true, true, RGB(255, 0, 255));
	//에레키블

}