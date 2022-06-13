/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Camera.cpp
Project: CS230
Author: Jemin.Shin
Creation date: 5/04/2022
-----------------------------------------------------------------*/
#include "Camera.h"
#include "Rect.h"
#include"Window.h"
#include<iostream>
using namespace std;

CS230::Camera::Camera(math::rect2 movableRange)
    :movableRange(movableRange) {}

void CS230::Camera::SetPosition(math::vec2 newPosition)
{
   position = newPosition;
}

void CS230::Camera::SetExtent(math::irect2 newExtent)
{
    extent = newExtent;
}


void CS230::Camera::Update(const math::vec2& followObjPos)
{

    if (followObjPos.x <= position.x + (movableRange.bottomLeft.x))
    {
        position.x = (followObjPos.x - (movableRange.bottomLeft.x));
    }

    if (followObjPos.x >= position.x + (movableRange.topRight.x))
    {
        position.x = (followObjPos.x - (movableRange.topRight.x));
    }

    if (position.x <= extent.bottomLeft.x)
    {
        position.x = extent.bottomLeft.x;
    }

    if (position.x + Engine::GetWindow().GetSize().x >= extent.topRight.x)
    {
        position.x = static_cast<double>(extent.topRight.x) - static_cast<double>(Engine::GetWindow().GetSize().x);
    }
   
}

const math::vec2& CS230::Camera::GetPosition() const
{
    return  position;
}

math::TransformMatrix CS230::Camera::GetMatrix()
{
    return math::TranslateMatrix(-position);
}