#include "enemyManager.h"
void enemyManager::soundInit()
{
	SOUNDMANAGER->addSound("Ǫ���ǳ뷡", ".//music//purin.mp3", true, true);
	SOUNDMANAGER->addSound("������", ".//music//lekujya.mp3", false, false);

	SOUNDMANAGER->addSound("�����׸�", ".//music//bossMusic.mp3", false, false);
	SOUNDMANAGER->addSound("������", ".//music//opening.mp3", false, false);

	SOUNDMANAGER->addSound("������", ".//music//explosion.wav", false, false);
	SOUNDMANAGER->addSound("����", ".//music//hit.wav", false, false);

}