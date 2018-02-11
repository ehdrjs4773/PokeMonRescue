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


void Item::setPotion(char* name, int num, int ability, int price, type Type)
{
	_item.name = name;
	_item.num = num;
	_item.abillity = ability;
	_item.price = price;
	_item.Type = Type;
}

void Item::setSkillItem(char* name, int num, int price, type Type)
{
	_item.name = name;
	_item.num = num;
	_item.price = price;
	_item.Type = Type;
}