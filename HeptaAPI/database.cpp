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
		//ĭ���̸� ã������
		if (vTemp[i] == "|")
		{
			status* st = new status;	//�������ͽ��� �Ҵ��ϰ�
			str = vTemp[i + 1];			//i�� �ϳ� ������Ű�� �̸��̳���
			_mTotalStatus.insert(pair<string, status*>(vTemp[i + 1], st)); //���⼱ �� ���ϸ��̸��� Ű������ �׸���������ְ� 

			if (i != 0) count += 7;		
			continue;
		}

		iterStatus mIter = _mTotalStatus.find(str);			//���⼭ ���� ã�� ����־��ش�

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