/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Splash.cpp
Purpose: This is the service provider for our games engine services
Project: CS230
Author: Jemin.Shin
Creation date: 3/14/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"	//GetGameStateManager
#include "Screens.h"
#include "Splash.h"

Splash::Splash() {}

void Splash::Load() {
	texture.Load("assets/DigiPen_BLACK_1024px.png");
}

void Splash::Update(double dt) {
	timer += dt;
	if (timer >= DISPLAY_TIME) 
	{
		Engine::Instance().GetGameStateManager().SetNextState(static_cast<int>(Screens::Mode1));
	}
}

void Splash::Unload() 
{

}

void Splash::Draw()
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
	math::vec2 Splash_Vec(Engine::GetWindow().GetSize() / 2 - texture.GetSize() / 2);
	texture.Draw(math::TranslateMatrix( Splash_Vec));
}