#include "stdafx.h"
#include "Item.h"



Item::Item()
{
}


Item::~Item()
{
}


HRESULT Item::init()
{
	

	return S_OK;
}


void Item::setPotion(string name, int num, int ability, int price, type Type)
{
	_item.name = name;
	_item.num = num;
	_item.abillity = ability;
	_item.price = price;
	_item.Type = Type;
}

void Item::setSkillItem(string name, string skillname, int num, int price, type Type)
{
	_item.name = name;
	_item.skillname = skillname;
	_item.num = num;
	_item.price = price;
	_item.Type = Type;
}

void Item::setItem(string name, string map, int setx, int sety, type Type, int price)
{
	_item.name = name;
	_item.mapname = map;
	_item.price = price;
	_item.Type = Type;
}
