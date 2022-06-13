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
#include "Super_Rect.h"
#include <algorithm>

Super_Rect::Super_Rect(math::vec2 startPos , double currentRotation , double Timer):
	startPos(startPos) , currentRotation(currentRotation) , Timer(Timer)
{}

void Super_Rect::Load()
{
	sprite.Load("assets/Ptg.spt");
	position = startPos;
	currentRotation -= rotate;
}

void Super_Rect::Update(double dt)
{
	Timer += dt;
	math::TransformMatrix roation = math::RotateMatrix(currentRotation);
	velocity += roation * math::vec2(0, accel * dt);


	velocity -= (velocity * Super_Rect::drag * dt);
	position.y -= velocity.y * dt;
	if (RectHeight > 0)
	{
		RectWidth -= 0.90 * dt;
		RectHeight -= 0.66 * dt;
	}

	cout << RectHeight << endl;
	cout << Current_State << endl;
	cout << Player_Life << endl;
	if (RectHeight < 0)
	{
		RectHeight = 0;
	}
	if (Current_State == 3 && (RectHeight > 0 && RectHeight <= 0.1))
	{
		Player_Life = false;
	}

	objectMatrix = math::TranslateMatrix(position) * math::RotateMatrix(currentRotation) * math::ScaleMatrix(math::vec2({ RectWidth, RectHeight }));
}

void Super_Rect::Draw()
{
	sprite.Draw(objectMatrix);
}