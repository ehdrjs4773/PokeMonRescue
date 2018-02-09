#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

//³»ºÎ ½Ì±ÛÅæ DB ¸¸µé¾îµÐ´Ù
class database : public singletonBase <database>
{
private:

private:

public:
	database();
	~database();

	HRESULT init();
	void update();
	void release();
};

