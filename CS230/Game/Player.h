/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Hero.h
Project: CS230
Author: Kevin Wright
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"
#include "..\Engine\TransformMatrix.h"

class Player
{
public:
	Player(math::vec2 startPos);
	void Load();
	void Update(double dt);
	void Draw();

private:

	CS230::Sprite sprite;
	math::vec2 startPos;
	math::vec2 position;
	math::vec2 velocity;

	bool isAccel;
	static constexpr double accel = 400;
	static constexpr double drag = 1;
	double currentRotation = 0;
	//static constexpr double speed = 5;

	double Speed = 0;
	double Cos_Value{};
	double Sin_Value{};
	CS230::InputKey Moving_Right;
	CS230::InputKey Moving_Left;
	CS230::InputKey Moving_Up;
	math::TransformMatrix objectMatrix;
};

