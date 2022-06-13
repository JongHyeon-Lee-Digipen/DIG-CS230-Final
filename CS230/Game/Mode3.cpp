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
	modeNext(CS230::InputKey::Keyboard::Enter){}

void Mode3::Load() 
{
	player.Load();
	super_rect1_1 = new Super_Rect({ (Engine::GetWindow().GetSize().x / 3.4) + RectStart, 200 }, 4.05, 3);
	super_rect2_1 = new Super_Rect2({ (Engine::GetWindow().GetSize().x / 7.0) + RectStart, 400 }, 2.41, 2);
	super_rect3_1 = new Super_Rect3({ (Engine::GetWindow().GetSize().x / 3.4) + RectStart, 600 }, 0.94, 1);
	super_rect4_1 = new Super_Rect4({ (Engine::GetWindow().GetSize().x / 2.25) + RectStart, 400 }, 5.57, 1);
	super_rect1_2 = new Super_Rect({ (Engine::GetWindow().GetSize().x / 3.4) + RectStart, 200 }, 4.05, 5);
	super_rect2_2 = new Super_Rect2({ (Engine::GetWindow().GetSize().x / 7.0) + RectStart, 400 }, 2.41, 7);
	super_rect3_2 = new Super_Rect3({ (Engine::GetWindow().GetSize().x / 3.4) + RectStart, 600 }, 0.94, 10);
	super_rect4_2 = new Super_Rect4({ (Engine::GetWindow().GetSize().x / 2.25) + RectStart, 400 }, 5.57, 12);
	super_rect1_3 = new Super_Rect({ (Engine::GetWindow().GetSize().x / 3.4) + RectStart, 200 }, 4.05, 13);
	super_rect2_3 = new Super_Rect2({ (Engine::GetWindow().GetSize().x / 7.0) + RectStart, 400 }, 2.41, 9);
	super_rect3_3 = new Super_Rect3({ (Engine::GetWindow().GetSize().x / 3.4) + RectStart, 600 }, 0.94, 15);
	super_rect4_3 = new Super_Rect4({ (Engine::GetWindow().GetSize().x / 2.25) + RectStart, 400 }, 5.57, 16);
	super_rect1_4 = new Super_Rect({ (Engine::GetWindow().GetSize().x / 3.4) + RectStart, 200 }, 4.05, 18);
	super_rect2_4 = new Super_Rect2({ (Engine::GetWindow().GetSize().x / 7.0) + RectStart, 400 }, 2.41, 20);
	super_rect3_4 = new Super_Rect3({ (Engine::GetWindow().GetSize().x / 3.4) + RectStart, 600 }, 0.94, 24);
	super_rect4_4 = new Super_Rect4({ (Engine::GetWindow().GetSize().x / 2.25) + RectStart, 400 }, 5.57, 22);

	super_rect1_1->Load();
	super_rect2_1->Load();
	super_rect3_1->Load();
	super_rect4_1->Load();
	super_rect1_2->Load();
	super_rect2_2->Load();
	super_rect3_2->Load();
	super_rect4_2->Load();
	super_rect1_3->Load();
	super_rect2_3->Load();
	super_rect3_3->Load();
	super_rect4_3->Load();
	super_rect1_4->Load();
	super_rect2_4->Load();
	super_rect3_4->Load();
	super_rect4_4->Load();
}

void Mode3::Update(double dt)
{
	player.Update(dt);
	Timer += dt;

	super_rect1_1->Update(dt);
	super_rect2_1->Update(dt);
	super_rect3_1->Update(dt);
	super_rect4_1->Update(dt);

	super_rect1_2->Update(dt);
	super_rect2_2->Update(dt);
	super_rect3_2->Update(dt);
	super_rect4_2->Update(dt);

	super_rect1_3->Update(dt);
	super_rect2_3->Update(dt);
	super_rect3_3->Update(dt);
	super_rect4_3->Update(dt);

	super_rect1_4->Update(dt);
	super_rect2_4->Update(dt);
	super_rect3_4->Update(dt);
	super_rect4_4->Update(dt);


	if (modeNext.IsKeyReleased() == true)
	{
		Engine::GetGameStateManager().Shutdown();
	}

	if (modeReload.IsKeyReleased() == true)
	{
		Engine::GetGameStateManager().ReloadState();
		Player_Life = true;
	}
}

void Mode3::Unload() {}

void Mode3::Draw()
{
	Engine::GetWindow().Clear(0x0F0000FF);
	player.Draw();

	super_rect1_1->Draw();
	super_rect2_1->Draw();
	super_rect3_1->Draw();
	super_rect4_1->Draw();

	super_rect1_2->Draw();
	super_rect2_2->Draw();
	super_rect3_2->Draw();
	super_rect4_2->Draw();

	super_rect1_3->Draw();
	super_rect2_3->Draw();
	super_rect3_3->Draw();
	super_rect4_3->Draw();

	super_rect1_4->Draw();
	super_rect2_4->Draw();
	super_rect3_4->Draw();
	super_rect4_4->Draw();
}