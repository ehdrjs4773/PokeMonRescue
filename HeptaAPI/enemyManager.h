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
	ENEMY_ELECTIVIRE,
	BOSS
};


enum ENEMYACTION
{
	enemyMove = 1,
	enemyAttack,
	enemyUseSkill,
	enemyEnd,
};


//���漱��!!!!!!
class tile;
class Stage;
class player;
class battleScene;

class enemyManager : public gameNode
{
private: //���漱�� Ŭ���� ���𱸰�
	vector<tile*> _tile;
	Stage* _stage;
	player* _pl;
	battleScene* _bs;

private://����ü ���� ����

	//���� ��ü Ʋ ����
	enemy*	_chicorita;
	enemy*	_dandegi;
	enemy*	_polygon;
	enemy*	_purin;
	enemy*	 _graena;
	enemy*	_rukario;
	enemy*	_mankey;
	enemy*	_tanguri;
	enemy*	_electivire;
	//���� ��ü Ʋ ���� �Ϸ�


	//����ü�� �̸��� ���صΰ� ������ ���� ���� �����!!!!
	tagImageName	_chicoName;
	tagImageName	_dandegiName;
	tagImageName	_polygonName;
	tagImageName	_purinName;
	
	tagImageName	_graenaName;
	tagImageName	_rukarioName;
	tagImageName	_mankeyName;
	tagImageName	_tanguriName;
	tagImageName	_electivireName;
	tagImageName	_bossName;

	ENEMYACTION _enemyAction;

private://���Ͱ��� ����

	//�����ϸ���� ����� ����
	//���� �ӽÿ����� �����ξ��⿡ ���߿� ������ ���ϸ� ����
	vector<enemy*> _vEnemyPokemon;
	vector<enemy*>::iterator _viEnemyPokemon;

private:
	int _tileCheckX;
	int _tileCheckY;
	int _selectSkill;

	int* _pMapNum;
	int _mapNum;
	
	int* _pFloorNum;
	int _floorNum;
	
	int _r;
	bool _canAtk;

	bool _enemyTurn;

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

	void soundInit();

	inline void setTileMemoryAdressLink(vector<tile*> tiles) { _tile = tiles; }
	inline void setStageMemoryAdressLink(Stage* stage) { _stage = stage; }
	inline void setPlayerMemoryAdressLink(player* pl) { _pl = pl; }
	inline void setBattleSceneAdressLink(battleScene* bs) { _bs = bs; }

	inline void getMapNum(int* mapNum) { _pMapNum = mapNum ; }
	inline void getFloorNum(int* floorNum) { _pFloorNum = floorNum; }


	inline ENEMYACTION getEnemyAction() { return _enemyAction; }
	inline void setEnemyAction(ENEMYACTION enemyAction) { _enemyAction = enemyAction; }


	void enemyTrunManager();
	void enemyAtkManager(int arrNum);
	void enemyMoveManager(int arrNum);
	void enemyBirth(ENEMY enemy, int tileX, int tileY, int level);


	void enemyDead();
};

