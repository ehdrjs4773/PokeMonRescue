#include "stdafx.h"
#include "Npc.h"
#include "player.h"
#include "inventoryChiled.h"

void inventoryChiled::save()
{
	char str[256];
	sprintf(str, ".//save.load");
	HANDLE file;
	DWORD write;
	file = CreateFile(str, GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == INVALID_HANDLE_VALUE)
	{
		file = CreateFile(str, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	}

	int strlening = strlen(_player->getStatus()->getName().c_str());
	WriteFile(file, &strlening, sizeof(int), &write, NULL);
	char tempstr[128];
	sprintf(tempstr, "%s", _player->getStatus()->getName().c_str());
	WriteFile(file, &tempstr, 128, &write, NULL);

	int tempnum = _vitem.size();
	WriteFile(file, &(*_player->getStatus()), sizeof(pokemon), &write, NULL);
	int tempmoney = _player->getMoney();
	WriteFile(file, &tempmoney, sizeof(int), &write, NULL);
	WriteFile(file, &tempnum, sizeof(int), &write, NULL);

	for (int i = 0; i < tempnum; ++i)
	{
		WriteFile(file, &_vitem[i], sizeof(Item), &write, NULL);
	}

	CloseHandle(file);
}

bool inventoryChiled::load()
{
	_finddata_t fd;
	intptr_t _handle;
	int result = 1;
	_handle = _findfirst(".//*.load", &fd);
	if (_handle == -1)
	{
		_findclose(_handle);
		return false;
	}
	_findclose(_handle);

	char str[256];
	sprintf(str, ".//save.load");
	HANDLE file;
	DWORD read;

	file = CreateFile(str, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	int strlening;
	ReadFile(file, &strlening, sizeof(int), &read, NULL);
	char tempstr[128];
	ReadFile(file, &tempstr,128, &read, NULL);

	_player->init(tempstr);
	int tempnum;
	ReadFile(file, &(*_player->getStatus()), sizeof(pokemon), &read, NULL);
	int tempmoney;
	ReadFile(file, &tempmoney, sizeof(int), &read, NULL);
	_player->setAddMoney(tempmoney);
	ReadFile(file, &tempnum, sizeof(int), &read, NULL);
	_vitem.clear();
	for (int i = 0; i < tempnum; ++i)
	{
		Item* temp;
		temp = new Item;
		ReadFile(file, &(*temp), sizeof(Item), &read, NULL);
		this->setItem(temp);
	}


	CloseHandle(file);

	SCENEMANAGER->init("Stage1");
	_player->setPosition(WINSIZEX / 2, WINSIZEY / 2);

	return true;
}