/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Super_Rect.cpp
Purpose: This is the service provider for our games engine services
Project: CS230
Author: Jemin.Shin
Creation date: 3/27/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"	//GetLogger
#include "Super_Rect2.h"
#include <algorithm>

Super_Rect2::Super_Rect2(math::vec2 startPos , double currentRotation , double Timers):
	startPos(startPos) , currentRotation(currentRotation) , Timers(Timers)
{}

void Super_Rect2::Load()
{
	sprite.Load("assets/Ptg.spt");
	position = startPos;
	currentRotation -= rotate;
}

void Super_Rect2::Update(double dt)
{
	Timer += dt;
	if (Timers < Timer)
	{
		math::TransformMatrix roation = math::RotateMatrix(currentRotation);
		velocity += roation * math::vec2(0, accel * dt);

		velocity.x -= (velocity.x * Super_Rect2::drag * dt);
		position.x -= velocity.x * dt;
		RectWidth -= 0.90 * dt;
		RectHeight -= 0.66 * dt;

		if (RectHeight < 0)
		{
			RectHeight = 0;
		}
		if (Current_State == 4 && (RectHeight > 0 && RectHeight <= 0.1))
		{
			Player_Life = false;
		}

		objectMatrix = math::TranslateMatrix(position) * math::RotateMatrix(currentRotation) * math::ScaleMatrix(math::vec2({ RectWidth, RectHeight }));
	}
	}

void Super_Rect2::Draw()
{
	if (Timers < Timer && Player_Life == true)
	{
		sprite.Draw(objectMatrix);
	}
}