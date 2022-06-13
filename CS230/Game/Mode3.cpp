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
#include "Mode3.h"
#include "Player.h"


Mode3::Mode3()
	:player(Engine::GetWindow().GetSize() / 2.0),
	modeReload(CS230::InputKey::Keyboard::R),
	modeNext(CS230::InputKey::Keyboard::Enter)
{}

void Mode3::Load() 
{
	super_rect = new Super_Rect({ 450, 406 });
	super_rect->Load();
	player.Load();
}

void Mode3::Update(double dt)
{
	player.Update(dt);
	super_rect->Update(dt);
	if (modeNext.IsKeyReleased() == true)
	{
		Engine::GetGameStateManager().Shutdown();
	}

	if (modeReload.IsKeyReleased() == true)
	{
		Engine::GetGameStateManager().ReloadState();
	}
}

void Mode3::Unload() {}

void Mode3::Draw()
{
	Engine::GetWindow().Clear(0x0F0000FF);
	player.Draw();
	super_rect->Draw();
}