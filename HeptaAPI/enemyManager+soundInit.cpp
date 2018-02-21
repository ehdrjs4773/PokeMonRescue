#include "enemyManager.h"
void enemyManager::soundInit()
{
	SOUNDMANAGER->addSound("Çª¸°ÀÇ³ë·¡", ".//music//purin.mp3", true, true);
	SOUNDMANAGER->addSound("·¹ÄíÀð", ".//music//lekujya.mp3", false, false);

	SOUNDMANAGER->addSound("º¸½ºÅ×¸¶", ".//music//bossMusic.mp3", false, false);
	SOUNDMANAGER->addSound("¿ÀÇÁ´×", ".//music//opening.mp3", false, false);

	SOUNDMANAGER->addSound("Æø¹ßÀ½", ".//music//explosion.wav", false, false);
	SOUNDMANAGER->addSound("°ø°Ý", ".//music//hit.wav", false, false);

}