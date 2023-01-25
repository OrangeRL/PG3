#include<stdio.h>
#include"SceneManager.h"
int main()
{

	SceneManager* sceneManager_ = SceneManager::GetInstance();

	sceneManager_->GetInstance()->SceneDisplay();
	sceneManager_->GetInstance()->SceneChange();


	return 0;
}