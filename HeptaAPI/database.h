#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

//���� �̱��� DB �����д�
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

