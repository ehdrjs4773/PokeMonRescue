#include "stdafx.h"
#include "player.h"

void player::save()
{
	char str[256];
	sprintf(str, ".//map//save.load");
	HANDLE file;
	DWORD write;
	file = CreateFile(str, GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == INVALID_HANDLE_VALUE)
	{
		file = CreateFile(str, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	}

	WriteFile(file, &_playerStatus, sizeof(pokemon), &write, NULL);
	int partnersize = _vPartner.size();
	WriteFile(file, &partnersize, sizeof(int), &write, NULL);
	for (int i = 0; i < _vPartner.size(); ++i)
	{
		WriteFile(file, &(*_vPartner[i]), sizeof(playerPartner), &write, NULL);
	}

}

void player::load()
{
	char str[256];
	sprintf(str, ".//map//save.load");
	HANDLE file;
	DWORD read;

	file = CreateFile(str, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, &_playerStatus, sizeof(pokemon), &read, NULL);
	int partnersize;
	ReadFile(file, &partnersize, sizeof(int), &read, NULL);
	for (int i = 0; i < partnersize; ++i)
	{
		playerPartner* temp;
		_vPartner.push_back(temp);
		ReadFile(file, &(*_vPartner[i]), sizeof(playerPartner), &read, NULL);
	}

}