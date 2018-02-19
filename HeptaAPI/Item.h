#pragma once
#include "gameNode.h"

enum type
{
	type_hpPotion,
	type_ppPotion,
	type_skillItem,
	type_junk,
	type_END
};

struct item
{
	string name;
	string skillname;
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
	
	void setPotion(string name, int num, int ability, int price, type Type);
	void setSkillItem(string name, string skillname,int num, int price, type Type);


	inline type getPotionType() { return _item.Type; }				// 타입 접근 함수 (열매인지 PP포션인지 등등)
	inline int getPotionAbillity() { return _item.abillity; }		// 능력 접근 함수 (50 채워주는지 100채워주는지)
	inline int getPrice() { return _item.price; }					// 가격 접근 함수
	inline int getNum() { return _item.num; }						// 갯수 접근 함수

	Item();
	~Item();
};

