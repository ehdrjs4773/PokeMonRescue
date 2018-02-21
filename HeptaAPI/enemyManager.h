#pragma once
#include "stdafx.h"
#include "enemy.h"
#include "gameNode.h"




enum ENEMY
{
	ENEMY_CHICORITA,
	ENEMY_DANDEGI,
	ENEMY_POLYGON,
	ENEMY_PURIN,
	ENEMY_GRAENA,
	ENEMY_RUKARIO,
	ENEMY_MANKEY,
	ENEMY_TANGURI,
	ENEMY_ELECTIVIRE
};


//전방선언!!!!!!
class tile;
class Stage;
class player;
class enemyManager : public gameNode
{
private: //전방선언 클래스 선언구간
	vector<tile*> _tile;
	Stage* _stage;
	player* _pl;

private://적객체 관련 생산

	//적의 객체 틀 생성
	enemy*	_chicorita;
	enemy*	_dandegi;
	enemy*	_polygon;
	enemy*	_purin;
	enemy*	 _graena;
	enemy*	_rukario;
	enemy*	_mankey;
	enemy*	_tanguri;
	enemy*	_electivire;
	//적의 객체 틀 생성 완료


	//구조체로 이름을 정해두고 보내서 쉽게 쉽게 가즈아!!!!
	tagImageName	_chicoName;
	tagImageName	_dandegiName;
	tagImageName	_polygonName;
	tagImageName	_purinName;
	
	tagImageName	_graenaName;
	tagImageName	_rukarioName;
	tagImageName	_mankeyName;
	tagImageName	_tanguriName;
	tagImageName	_electivireName;

private://벡터관련 생산

	//적포켓몬들을 담아줄 벡터
	//아직 임시용으로 만들어두었기에 나중에 생성된 포켓몬 전용
	vector<enemy*> _vEnemyPokemon;
	vector<enemy*>::iterator _viEnemyPokemon;

private:
	int _tileCheckX;
	int _tileCheckY;
	

	int _r;
	bool _canAtk;

public:
	enemyManager();
	~enemyManager();


	HRESULT init();


	void imageInit();
	void release();
	void update();
	void render();


	inline vector<enemy*> getVEnemyPokemon() { return _vEnemyPokemon; };
	inline vector<enemy*>::iterator getVIEnemyPokemon() { return _viEnemyPokemon; };	


	inline void setTileMemoryAdressLink(vector<tile*> tiles) { _tile = tiles; }
	inline void setStageMemoryAdressLink(Stage* stage) { _stage = stage; }
	inline void setPlayerMemoryAdressLink(player* pl) { _pl = pl; }


	void enemyTrunManager();
	void enemyAtkManager(int arrNum);
	void enemyMoveManager(int arrNum);
	void enemyBirth(ENEMY enemy, int tileX, int tileY, int level);


	void enemyDead();
};

