/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Mode2.cpp
Purpose: This is the service provider for our games engine services
Project: CS230
Author: Jemin.Shin
Creation date: 3/14/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"   //GetGameStateManager
#include "Screens.h"
#include "Mode2.h"

Mode2::Mode2()
	: ship(Engine::GetWindow().GetSize() / 2.0),
	modeReload(CS230::InputKey::Keyboard::R), modeNext(CS230::InputKey::Keyboard::Enter) {}

void Mode2::Load() {
	ship.Load();
}

void Mode2::Update(double dt) 
{
	ship.Update(dt);

	if (modeNext.IsKeyReleased() == true) 
	{
		Engine::GetGameStateManager().SetNextState(static_cast<int>(Screens::Mode3));
	}

	if (modeReload.IsKeyReleased() == true) 
	{
		Engine::GetGameStateManager().ReloadState();
	}
}

void Mode2::Unload() {}

void Mode2::Draw() 
{
	Engine::GetWindow().Clear(0x000000FF);

	ship.Draw();
}