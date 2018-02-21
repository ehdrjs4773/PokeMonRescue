#pragma once
#include "gameNode.h"
#include "Item.h"
#include "shopchildren.h"
#include <vector>


class inventoryChiled : public gameNode
{

private :
	vector<Item> _vitem;
	vector<Item>::iterator _viItem;
	

public:
	inventoryChiled();
	~inventoryChiled();


	HRESULT init();
	void release();
	void update();
	void render();


	void setItem(Item* item);


	// 접근자 ~!

	vector<Item> getVitem() { return _vitem; }
	vector<Item>::iterator getViItem() { return _viItem; }

	// 설정자 ~!
	
	//vector<Item> setVitem(Item* item) { _vitem.push_back(item); }

};

