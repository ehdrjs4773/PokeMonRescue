#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class pokemon;

struct status
{
public:
	string name;
	int element;
	int hp;
	int atk;
	int def;
	int specialATK;
	int specialDEF;

	status() {};
	~status() {};
};

//내부 싱글톤 DB 만들어둔다
class database : public singletonBase <database>
{
private:
	//텍스트데이터를 넣기위한 벡터
	typedef vector<string> arrFind;				
	typedef vector<string>::iterator iterFind;

	typedef map<string, status*> arrStatus;
	typedef map<string, status*>::iterator iterStatus;

	arrStatus _mTotalStatus;



public:
	database();
	~database();

	void loadDatabasePokemon(string name);

	status* getElementData(string str) { return _mTotalStatus.find(str)->second; }


	HRESULT init();
	void update();
	void release();
};

