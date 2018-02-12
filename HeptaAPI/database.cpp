#include "stdafx.h"
#include "database.h"


database::database()
{
}


database::~database()
{

}

HRESULT database::init()
{
	loadDatabasePokemon(".\\textData\\pokemonstatus.txt");

	return S_OK;
}

void database::update()
{
}

void database::release()
{

}


void database::loadDatabasePokemon(string name)
{
	arrFind vTemp;
	vTemp = TXTDATA->txtLoad(name.c_str());

	string str;
	int count = 0;

	for (int i = 0; i < vTemp.size(); ++i)
	{
		//칸막이를 찾았으면
		if (vTemp[i] == "|")
		{
			status* st = new status;	//스테이터스를 할당하고
			str = vTemp[i + 1];			//i를 하나 증가시키면 이름이나옴
			_mTotalStatus.insert(pair<string, status*>(vTemp[i + 1], st)); //여기선 그 포켓몬이름을 키값으로 그릇을만들어주고 

			if (i != 0) count += 7;		
			continue;
		}

		iterStatus mIter = _mTotalStatus.find(str);			//여기서 값을 찾고 집어넣어준다

		if (i == count + 1)								
		{
			mIter->second->name = vTemp[i].c_str();
		}

		else if (i == count + 2) mIter->second->hp = atoi(vTemp[i].c_str());
		else if (i == count + 3) mIter->second->atk = atoi(vTemp[i].c_str());
		else if (i == count + 4) mIter->second->def = atoi(vTemp[i].c_str());
		else if (i == count + 5) mIter->second->specialATK = atoi(vTemp[i].c_str());
		else if (i == count + 6) mIter->second->specialDEF = atoi(vTemp[i].c_str());
	}

	vTemp.clear();
}