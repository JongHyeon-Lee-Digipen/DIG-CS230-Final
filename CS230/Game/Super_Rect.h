/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Super_Rect.h
Project: CS230
Author: Kevin Wright
Creation date: 2/14/2021
-----------------------------------------------------------------*/
#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Vec2.h"
#include "..\Engine\Camera.h"
#include "..\Engine\TransformMatrix.h"
#include "..\Game\Player.h"

class Super_Rect
{
public:
	Super_Rect(math::vec2 startPos, double currentRotation, double Timer);
	void Load();
	void Update(double dt);
	void Draw();
private:
	CS230::Sprite sprite;
	math::vec2 startPos;
	math::vec2 position;
	math::vec2 velocity;

	static constexpr double pi = 3.14159265358979;
	static constexpr double accel = 400;
	static constexpr double drag = 1;
	static constexpr double Speed = 200;
	static constexpr double rotate = pi / 2.0;
	double currentRotation = 0;

	bool AAA = false;
	double Cos_Value{};
	double Sin_Value{};
	double RectWidth = 1;
	double RectHeight = 0.5;
	double Timer{};
	double Rect_Num = 1;

	math::TransformMatrix objectMatrix;
};