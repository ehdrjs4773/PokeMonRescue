#pragma once
#include "gameNode.h"

enum type
{
	type_hpPotion,
	type_ppPotion,
	type_skillItem
};

struct item
{
	char* name;
	int num;
	int abillity;
	int price;
	type Type;
};


class Item : public gameNode
{
private :

	item _item;

public:


	HRESULT init();
	
	void setPotion(char* name, int num, int ability, int price, type Type);
	void setSkillItem(char* name, int num, int price, type Type);


	inline type getPotionType() { return _item.Type; }



	Item();
	~Item();
};

