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
#include "Super_Rect3.h"
#include "Super_Rect4.h"
#include "Background.h"
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
	Super_Rect2* super_rect2_1;
	Super_Rect3* super_rect3_1;
	Super_Rect4* super_rect4_1;

	Super_Rect* super_rect1_2;
	Super_Rect2* super_rect2_2;
	Super_Rect3* super_rect3_2;
	Super_Rect4* super_rect4_2;

	Super_Rect* super_rect1_3;
	Super_Rect2* super_rect2_3;
	Super_Rect3* super_rect3_3;
	Super_Rect4* super_rect4_3;

	Super_Rect* super_rect1_4;
	Super_Rect2* super_rect2_4;
	Super_Rect3* super_rect3_4;
	Super_Rect4* super_rect4_4;

	Background background;
	CS230::InputKey modeReload;
	CS230::InputKey modeNext;
	double Timer{};
	static constexpr double RectStart = 300;
};

