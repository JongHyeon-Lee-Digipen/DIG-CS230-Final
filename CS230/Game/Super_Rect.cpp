/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Hero.cpp
Purpose: This is the service provider for our games engine services
Project: CS230
Author: Jemin.Shin
Creation date: 3/27/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"	//GetLogger
#include "Super_Rect.h"
#include <algorithm>

Super_Rect::Super_Rect(math::vec2 startPos):
	startPos(startPos) , Hexagon_Num(Hexagon_Num) {}

void Super_Rect::Load()
{
	sprite.Load("assets/Ptg.spt");
	position = startPos;
}

void Super_Rect::Update(double dt)
{
	position.x = (sin(Sin_Value) * 100) * dt + Engine::GetWindow().GetSize().x / 2.0 - 50;
	position.y = (cos(Cos_Value) * 100) * dt + Engine::GetWindow().GetSize().y / 2.0;
	//objectMatrix = math::TranslateMatrix(position) * math::RotateMatrix(currentRotation) * math::ScaleMatrix(math::vec2(0.01));
}

void Super_Rect::Draw()
{
	sprite.Draw(objectMatrix);
}