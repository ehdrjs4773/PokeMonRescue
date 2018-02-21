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
	_findclose(_handle);
	if (_handle == -1)
	{
		return false;
	}

	char str[256];
	sprintf(str, ".//save.load");
	HANDLE file;
	DWORD read;

	file = CreateFile(str, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	int tempnum = _vitem.size();
	ReadFile(file, &(*_player->getStatus()), sizeof(pokemon), &read, NULL);
	int tempmoney;
	ReadFile(file, &tempmoney, sizeof(int), &read, NULL);
	_player->setAddMoney(tempmoney);
	ReadFile(file, &tempnum, sizeof(int), &read, NULL);
	for (int i = 0; i < tempnum; ++i)
	{
		Item temp;
		_vitem.push_back(temp);
		ReadFile(file, &_vitem[i], sizeof(Item), &read, NULL);
	}


	CloseHandle(file);
	return true;
}