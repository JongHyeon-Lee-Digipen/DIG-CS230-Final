/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: GameObjectManager.cpp
Purpose: Base class for different game states
Project: CS230
Author: JongHyeon Lee
Creation date: 5/13/2022
-----------------------------------------------------------------*/

#include "..\Engine\GameObjectManager.h"

void CS230::GameObjectManager::Add(GameObject* obj)
{
	gameObjects.push_back(obj);
}
void CS230::GameObjectManager::Unload()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}

	gameObjects.clear();
}
void CS230::GameObjectManager::UpdateAll(double dt)
{
	for (CS230::GameObject* object : gameObjects)
	{
		object->Update(dt);
	}
}
void CS230::GameObjectManager::DrawAll(math::TransformMatrix& cameraMatrix)
{
	for (CS230::GameObject* object : gameObjects)
	{
		object->Draw(cameraMatrix);
	}
}