#pragma once
#include "gameNode.h"
#include "Item.h"
#include "shopchildren.h"
#include <vector>

class player;

class inventoryChiled : public gameNode
{

private :
	vector<Item> _vitem;
	vector<Item>::iterator _viItem;
	
	player* _player;

public:
	inventoryChiled();
	~inventoryChiled();


	HRESULT init();
	void release();
	void update();
	void render();


	void setItem(Item* item);


	// 접근자 ~!

	void setInvenPlayerMemAdressLink(player* play) { _player = play; }

	vector<Item> getVitem() { return _vitem; }
	vector<Item>::iterator getViItem() { return _viItem; }

	// 설정자 ~!
	
	//vector<Item> setVitem(Item* item) { _vitem.push_back(item); }

	void save();

	bool load();

};

