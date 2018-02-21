#pragma once
#include "gameNode.h"
#include "Item.h"
#include <vector>




struct shop
{
	RECT rc;				// 첫 번째 상점 창
	RECT rc2;				// 두 번째 상점 창
	image* shopimage;		// 첫 번째 이미지
	image* pointimage;		// 포인트 이미지
	RECT point;				// 포인트 박스
	int x;					// 창 좌표 x
	int y;					// 창 좌표 y
	bool buy;				// 사기 선택했는지?
	bool sell;				// 팔기 선택했는지?
	bool allSell;			// 전부 팔기 선택 했는지?		
};


struct shopbuy
{
	RECT rc;
	RECT rc2;
	image* buyimage;
	image* buyimage2;
	int x;
	int y;
	int x2;
	int y2;
	bool buySelect;
};

enum shopinfo
{
	shopinfo_buy,		// 상점 사기
	shopinfo_sell,		// 상점 팔기
	shopinfo_allSell,	// 상점 전부 팔기
	shopinfo_talk,		// 상점 얘기하기
	shopinfo_exit,		// 상점 나가기
	shopinfo_END		// 상점 인포 끝
};

enum shopClick
{
	shop_info,
	shop_buy,
	shop_sell,
	shop_allsell,
	shop_talk,
	shop_exit,
	shop_end
};

enum itembuy
{
	item_potion,
	item_ppPotion,
	item_skill,
	item_end
};


enum select
{
	buy,
	no,
	end
};

struct itemSelcet
{
	bool potionSelcet;
	bool ppPotionSelect;
	bool skillSelcet;
};

class player;
class inventoryChiled;


class shopchildren : public gameNode
{

private :

	vector<Item*> _vitem;
	vector<Item*>::iterator _viItem;

	select _sele;
	shopinfo _shopinfo;		// 상점 상태
	shopClick _shopClick;	// 상점 선택
	itembuy _itembuy;		// 아이템 선택
	itemSelcet _itemSelcet;
	player* _player;		// 전방 플레이어 선언
	Item _item;
	inventoryChiled* _inven; // 인벤토리 선언	



	shopbuy _shopbuy;		// 상점 사기
	shop _shop;				// 상점

public:


	HRESULT init();
	void release();
	void update();
	void render();

	void keyMove();

	void setPlayerMemoryAdressLink(player* plays) { _player = plays; }
	void setInventoryMemoryAdressLink(inventoryChiled* inven) { _inven = inven; }


	shopchildren();
	~shopchildren();
};

