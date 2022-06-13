#pragma once
/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Rect.h
Author: Jemin.Shin
Creation date: 2022/04/05
-----------------------------------------------------------------*/
#pragma once
#include <cmath>
#include <limits>
#include <vector>

#include "Vec2.h"
namespace math
{
    struct rect2
    {
        math::vec2 bottomLeft;
        math::vec2 topRight;
    };

    struct irect2
    {
        math::ivec2 bottomLeft;
        math::ivec2 topRight;
    };
}