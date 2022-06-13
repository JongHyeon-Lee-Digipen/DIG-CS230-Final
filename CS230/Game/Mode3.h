/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Mode2.h
Project: CS230
Author: Kevin Wright
Creation date: 2/10/2021
-----------------------------------------------------------------*/
#pragma once
#include "..\Engine\GameState.h"
#include "..\Engine\Input.h"
#include "Player.h"
#include "Super_Rect.h"
#include "Super_Rect2.h"
#include "../Engine/GameObjectManager.h"

class Mode3 : public CS230::GameState 
{
public:
	Mode3();
	void Load() override;
	void Update(double dt) override;
	void Unload() override;
	void Draw() override;

	std::string GetName() override { return "Mode 3"; }
private:

	Player player;
	CS230::GameObjectManager gameObjectManager;
	Super_Rect* super_rect1_1;
	Super_Rect* super_rect1_2;
	Super_Rect2* super_rect2_1;
	Super_Rect2* super_rect2_2;
	CS230::InputKey modeReload;
	CS230::InputKey modeNext;
	static constexpr double RectStart = 300;
};

