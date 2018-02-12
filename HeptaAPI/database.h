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

//���� �̱��� DB �����д�
class database : public singletonBase <database>
{
private:
	//�ؽ�Ʈ�����͸� �ֱ����� ����
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

