#include "SceneManager.h"


SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;


	return &instance;
}

void SceneManager::SceneChange()
{
	while (true)
	{
		Sleep(3 * 1000);

		sceneCount += 1;
		if (sceneCount > 3) {
			sceneCount = 0;
			Count += 1;
		}

		if (Count == 3) {
			break;
		}
		SceneDisplay();

	}
}

void SceneManager::SceneDisplay()
{
	if (sceneCount == 0) {
		printf("Titleシーン\n");
	}

	if (sceneCount == 1) {
		printf("NewGameシーン\n");
	}

	if (sceneCount == 2) {
		printf("GamePlayシーン\n");
	}

	if (sceneCount == 3) {
		printf("GameClearシーン\n");
	}
}