/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Mode1.cpp
Purpose: This is the service provider for our games engine services
Project: CS230
Author: Jemin.Shin
Creation date: 3/14/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"	//GetGameStateManager
#include "Screens.h"
#include "Mode1.h"
#include "../Engine/Camera.h"


Mode1::Mode1() 
	: modeReload(CS230::InputKey::Keyboard::R), modeNext(CS230::InputKey::Keyboard::Enter),
	camera(math::rect2{ math::vec2{Engine::GetWindow().GetSize().x * (15.0 / 100.0),0},
	math::vec2{Engine::GetWindow().GetSize().x * (35.0 / 100.0), 0} }),
	hero(nullptr),
	ball1(nullptr),
	ball2(nullptr),
	ball3(nullptr)
{}

void Mode1::Load() 
{
	hero = new Hero({ 150, Mode1::floor }, CS230::Camera(camera));
	hero->Load();

	ball1 = new Ball(math::vec2(600, Mode1::floor));
	ball1->Load();

	ball2 = new Ball(math::vec2(2700, Mode1::floor));
	ball2->Load();

	ball3 = new Ball(math::vec2(4800, Mode1::floor));
	ball3->Load();

	background.Add("Assets/clouds.png", 4);
	background.Add("Assets/Mountains.png", 2);
	background.Add("Assets/foreground.png", 1);


	camera.SetPosition(math::vec2{ 0,0 });
	camera.SetExtent(math::irect2{ math::ivec2(0,0),background.Size() });
}
void Mode1::Update(double dt) 
{
	hero->Update(dt);
	ball1->Update(dt);
	ball2->Update(dt);
	ball3->Update(dt);
	camera.Update(hero->Getposition());

	if (modeNext.IsKeyReleased() == true) {
		Engine::GetGameStateManager().SetNextState(static_cast<int>(Screens::Mode2));
	}

	if (modeReload.IsKeyReleased() == true) 
	{
		Engine::GetGameStateManager().ReloadState();
	}

}
void Mode1::Unload() 
{
	delete hero;
	delete ball1;
	delete ball2;
	delete ball3;
}

void Mode1::Draw() 
{
	Engine::GetWindow().Clear(0x3399DAFF);
	math::TransformMatrix cameraMatrix = camera.GetMatrix();
	background.Draw(camera);
	hero->Draw(cameraMatrix);
	ball1->Draw(cameraMatrix);
	ball2->Draw(cameraMatrix);
	ball3->Draw(cameraMatrix);

}