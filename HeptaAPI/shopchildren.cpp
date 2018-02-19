#include "stdafx.h"
#include "shopchildren.h"



shopchildren::shopchildren()
{

}


shopchildren::~shopchildren()
{

}

HRESULT shopchildren::init()
{

	// ���� �⺻ �� �ʱ�ȭ =================================//
	_shop.shopimage = IMAGEMANAGER->findImage("shopMenu");
	_shop.x = 300;
	_shop.y = 150;
	_shop.rc = RectMake(_shop.x, _shop.y, _shop.shopimage->getWidth(), _shop.shopimage->getHeight());

	_shop.pointimage = IMAGEMANAGER->findImage("point");
	_shop.point = RectMake(_shop.rc.left + 20, _shop.rc.top + 25, _shop.pointimage->getWidth(), _shop.pointimage->getHeight());

	_shopinfo = shopinfo_buy;
	_shopClick = shop_info;
	_itembuy = item_potion;
	_shopbuy.buySelect = false;

	//_item->init(); �ؾ��ϳ� ���ؾ��ϳ�?
	//=====================================================//

	// ���� ��� �ʱ�ȭ ====================================//

	_shopbuy.buySelect = false;
	_shopbuy.x = 10;
	_shopbuy.y = 10;
	_shopbuy.x2 = 320;
	_shopbuy.y2 = 43;
	_shopbuy.buyimage = IMAGEMANAGER->findImage("������");
	_shopbuy.buyimage2 = IMAGEMANAGER->findImage("shop");
	_shopbuy.rc = RectMake(_shopbuy.x, _shopbuy.y, _shopbuy.buyimage->getWidth(), _shopbuy.buyimage->getHeight());
	_shopbuy.rc2 = RectMake(_shopbuy.x2, _shopbuy.y2, _shopbuy.buyimage2->getWidth(), _shopbuy.buyimage2->getHeight());
	_sele = buy;
	
	_itemSelcet.potionSelcet = false;
	_itemSelcet.ppPotionSelect = false;
	_itemSelcet.skillSelcet = false;


	return S_OK;
}
void shopchildren::release()
{

}


void shopchildren::update()
{
	keyMove();
	if (!_shopbuy.buySelect)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			switch (_shopinfo)
			{
			case shopinfo_buy:
				_shopClick = shop_buy;
				_shopbuy.buySelect = true;
				break;
			case shopinfo_sell:
				// UI ������
				break;
			case shopinfo_allSell:
				// �ʿ���°� ���� �Ĵ°ǵ� �׷��� �ֳ�?
				break;
			case shopinfo_talk:
				// ��ȭ�� ����?
				break;
			case shopinfo_exit:
				SCENEMANAGER->changeParent();
				break;
			}
		}
	}



	if (_shopbuy.buySelect)
	{
		if(KEYMANAGER->isOnceKeyDown('X'))
		{
			switch (_itembuy)
			{
			case item_potion:
				_itemSelcet.potionSelcet = true;
				break;
			case item_ppPotion:
				_itemSelcet.ppPotionSelect = true;
				break;
			case item_skill:
				_itemSelcet.skillSelcet = true;
				break;
			case item_end:
				break;
			}
		}
	}

	if (_itembuy == item_potion)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			switch (_sele)
			{
			case buy :

				break;
			case no :

				break;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		if(!_itemSelcet.potionSelcet && !_itemSelcet.ppPotionSelect && !_itemSelcet.skillSelcet)
		{
			switch (_shopClick)
			{
				case shop_info :
					SCENEMANAGER->changeParent();
					break;
				case shop_buy :
					_shopClick = shop_info;
					_shopbuy.buySelect = false;
					break;
				case shop_sell : 
					break;
				case shop_allsell : 
					break;
				case shop_talk : 
					break;
				case shop_exit : 
					break;
			}
		}
		switch (_itembuy)
		{
		case item_potion:
			_itemSelcet.potionSelcet = false;
			break;
		case item_ppPotion:
			_itemSelcet.ppPotionSelect = false;
			break;
		case item_skill:
			_itemSelcet.skillSelcet = false;
			break;
		case item_end:
			break;
		}


	}
}


void shopchildren::render()	
{
	HDC dc = CAMERAMANAGER->getMemDC();

	switch (_shopClick)																	// ���ʿ� ���� Ŭ���߳�!
	{	
	case shop_info :																	// �⺻ �� 
		_shop.shopimage->render(dc, _shop.x, _shop.y);
		
		switch (_shopinfo)
		{
		case shopinfo_buy:																			// ���콺 ��ġ
			_shop.pointimage->render(dc, _shop.point.left, _shop.point.top);
			break;
		case shopinfo_sell:
			_shop.pointimage->render(dc, _shop.point.left, _shop.point.top + 30);
			break;
		case shopinfo_allSell:
			_shop.pointimage->render(dc, _shop.point.left, _shop.point.top + 60);
			break;
		case shopinfo_talk:
			_shop.pointimage->render(dc, _shop.point.left, _shop.point.top + 90);
			break;
		case shopinfo_exit:
			_shop.pointimage->render(dc, _shop.point.left, _shop.point.top + 120);
			break;
		case shopinfo_END:																			//============
			break;
		}

		break;
	case shop_buy :																			// ��� ����������
		_shopbuy.buyimage->render(dc, _shopbuy.x, _shopbuy.y);
		
		SetBkMode(dc, TRANSPARENT); //�۾��������ȭ									// ��� �̸�
		SetTextColor(dc, RGB(255, 255, 255));
		char temp[128];	
		sprintf(temp, "ȸ����");
		TextOut(dc, _shopbuy.x + 50, _shopbuy.y + 50, temp, strlen(temp));
		char four[128];
		sprintf(four, "PP����");
		TextOut(dc, _shopbuy.x + 50, _shopbuy.y + 100, four, strlen(four));
		char tall[128];
		sprintf(tall, "���Ŀ���");
		TextOut(dc, _shopbuy.x + 50, _shopbuy.y + 150, tall, strlen(tall));

		switch (_itembuy)																		//������ ���� ������!!
		{
		case item_potion :
			_shop.pointimage->render(dc, _shopbuy.x + 20, _shopbuy.y + 50);
			if (_itemSelcet.potionSelcet)
			{
				_shopbuy.buyimage2->render(dc, _shopbuy.rc2.left, _shopbuy.rc2.top);

				switch (_sele)
				{
				case buy:
					_shop.pointimage->render(dc, _shopbuy.x2 + 20, _shopbuy.y2 + 30);
					break;
				case no:
					_shop.pointimage->render(dc, _shopbuy.x2 + 20, _shopbuy.y2 + 60);
					break;
				}
			}

			
			break;
		case item_ppPotion:
			_shop.pointimage->render(dc, _shopbuy.x + 20, _shopbuy.y + 100);
			if (_itemSelcet.ppPotionSelect)
			{
				_shopbuy.buyimage2->render(dc, _shopbuy.rc2.left, _shopbuy.rc2.top);

				switch (_sele)
				{
				case buy:
					_shop.pointimage->render(dc, _shopbuy.x2 + 20, _shopbuy.y2 + 30);
					break;
				case no:
					_shop.pointimage->render(dc, _shopbuy.x2 + 20, _shopbuy.y2 + 60);
					break;
				}
			}
			break;
		case item_skill:
			_shop.pointimage->render(dc, _shopbuy.x + 20, _shopbuy.y + 150);
			if (_itemSelcet.skillSelcet)
			{
				_shopbuy.buyimage2->render(dc, _shopbuy.rc2.left, _shopbuy.rc2.top);

				switch (_sele)
				{
				case buy:
					_shop.pointimage->render(dc, _shopbuy.x2 + 20, _shopbuy.y2 + 30);
					break;
				case no:
					_shop.pointimage->render(dc, _shopbuy.x2 + 20, _shopbuy.y2 + 60);
					break;
				}
			}
			break;
		case item_end :
			break;
		}
		break;
		


	case shop_sell :
		break;
	case shop_allsell:
		break;
	case shop_talk:
		break;
	case shop_exit :
		break;
	}
	


	//Rectangle(dc, _shop.rc.left, _shop.rc.top, _shop.rc.right, _shop.rc.bottom);
	//Rectangle(dc, _shop.point.left, _shop.point.top, _shop.point.right, _shop.point.bottom);
}


void shopchildren::keyMove()				// �� ��ġ������ ����ġ ���� �ɼ�
{

	if (!_itemSelcet.potionSelcet && !_itemSelcet.ppPotionSelect && !_itemSelcet.skillSelcet)
	{
		if (!_shopbuy.buySelect)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				switch (_shopinfo)
				{
				case shopinfo_buy:
					_shopinfo = shopinfo_sell;
					break;
				case shopinfo_sell:
					_shopinfo = shopinfo_allSell;
					break;
				case shopinfo_allSell:
					_shopinfo = shopinfo_talk;
					break;
				case shopinfo_talk:
					_shopinfo = shopinfo_exit;
					break;
				case shopinfo_exit:
					_shopinfo = shopinfo_buy;
					break;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				switch (_shopinfo)
				{
				case shopinfo_buy:
					_shopinfo = shopinfo_exit;
					break;
				case shopinfo_sell:
					_shopinfo = shopinfo_buy;
					break;
				case shopinfo_allSell:
					_shopinfo = shopinfo_sell;
					break;
				case shopinfo_talk:
					_shopinfo = shopinfo_allSell;
					break;
				case shopinfo_exit:
					_shopinfo = shopinfo_talk;
					break;
				}
			}
		}
		if (_shopClick == shop_buy)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				switch (_itembuy)
				{
				case item_potion:
					_itembuy = item_ppPotion;
					break;
				case item_ppPotion:
					_itembuy = item_skill;
					break;
				case item_skill:
					_itembuy = item_potion;
					break;
				case item_end:
					break;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				switch (_itembuy)
				{
				case item_potion:
					_itembuy = item_skill;
					break;
				case item_ppPotion:
					_itembuy = item_potion;
					break;
				case item_skill:
					_itembuy = item_ppPotion;
					break;
				case item_end:
					break;
				}
			}
		}
	}

	if (_itemSelcet.potionSelcet || _itemSelcet.ppPotionSelect || _itemSelcet.skillSelcet)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			switch (_sele)
			{
				case buy:
					_sele = no;
					break;
				case no:
					_sele = buy;
					break;

			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			switch (_sele)
			{
				case buy:
					_sele = no;
					break;
				case no:
					_sele = buy;
					break;

			}
		}
	}
}