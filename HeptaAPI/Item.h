#pragma once
#include "gameNode.h"

enum type
{
	type_hpPotion,
	type_ppPotion,
	type_skillItem,
	type_junk,
	type_loop,
	type_END
};

struct item
{
	string name;
	string skillname;
	string mapname;
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
	void setItem(string name, string map, int setx, int sety, type Type);

	inline type getPotionType() { return _item.Type; }				// Ÿ�� ���� �Լ� (�������� PP�������� ���)
	inline int getPotionAbillity() { return _item.abillity; }		// �ɷ� ���� �Լ� (50 ä���ִ��� 100ä���ִ���)
	inline int getPrice() { return _item.price; }					// ���� ���� �Լ�
	inline string getName() { return _item.name; }					// �̸� ���� �Լ�
	inline int getNum() { return _item.num; }						// ���� ���� �Լ�

	Item();
	~Item();
};

