/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: GameObjectManager.h
Purpose: Base class for different game states
Project: CS230
Author: JongHyeon Lee
Creation date: 5/13/2022
-----------------------------------------------------------------*/

#pragma once

#include <vector>
#include "..\Engine\GameObject.h"
#include "..\Engine\TransformMatrix.h"
#include "..\Game\Hero.h"
#include "..\Game\Ball.h"

namespace math { class TransformMatrix; }

namespace CS230 {
	class GameObject;

	class GameObjectManager {
	public:
		void Add(GameObject* obj);
		void Unload();

		void UpdateAll(double dt);
		void DrawAll(math::TransformMatrix& cameraMatrix);
	private:
		std::vector<GameObject*> gameObjects;
	};
}