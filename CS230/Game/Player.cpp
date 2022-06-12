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
#include "Player.h"
#include <algorithm>

Player::Player(math::vec2 startPos) :
startPos(startPos), Speed(Speed),
Moving_Right(CS230::InputKey::Keyboard::D), Moving_Left(CS230::InputKey::Keyboard::A) 
, Moving_Up(CS230::InputKey::Keyboard::W) {}

void Player::Load()
{
	sprite.Load("assets/Player.spt");
	position = startPos;
}

void Player::Update(double dt)
{
	if (Moving_Right.IsKeyDown() == true)
	{
		Cos_Value = Cos_Value - 0.2;
		Sin_Value = Sin_Value - 0.2;
	}
	if (Moving_Left.IsKeyDown() == true)
	{
		Cos_Value = Cos_Value + 0.2;
		Sin_Value = Sin_Value + 0.2;
	}
	math::TransformMatrix roation = math::RotateMatrix(currentRotation);

	cout << "Player_X  :  " << position.x << "\t" << "Player_Y  :  " << position.y << endl;
	velocity -= (velocity * Player::drag * dt);
	position += velocity * dt;
	position.x = sin(Sin_Value) * 100 + Engine::GetWindow().GetSize().x / 2.0;
	position.y = cos(Cos_Value) * 100 + Engine::GetWindow().GetSize().y / 2.0;
	objectMatrix = math::TranslateMatrix(position) * math::RotateMatrix(currentRotation) * math::ScaleMatrix(math::vec2(0.75));
}

void Player::Draw()
{
	sprite.Draw(objectMatrix);
}