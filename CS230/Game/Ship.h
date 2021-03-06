/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Ship.h
Project: CS230
Author: Kevin Wright
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#pragma once
#include "..\Engine\Input.h"
#include "..\Engine\Sprite.h"
#include "..\Engine\Vec2.h"
#include "Flame_Anims.h"
class Ship {
public:
    Ship(math::vec2 startPos);
    void Load();
    void Update(double dt);
    void Draw();

private:
    void TestForWrap();

    CS230::Sprite sprite;
    CS230::Sprite flameLeft;
    CS230::Sprite flameRight;

    math::vec2 startPos;
    math::vec2 position;
    math::vec2 velocity;

    bool isAccel;
    static constexpr double accel = 400;
    static constexpr double drag = 1;
    double currentRotation = 0;
    static constexpr double speed = 5;

    CS230::InputKey rotateCounterKey;
    CS230::InputKey rotateClockKey;
    CS230::InputKey accelerateKey;

    math::TransformMatrix objectMatrix;
};