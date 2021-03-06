/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Texture.h
Purpose: Wrapper class for doodle::Image
Project: CS230
Author: Kevin Wright
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#pragma once
#include <doodle/image.hpp>    //doodle::Image
#include "Vec2.h"
#include "TransformMatrix.h"

namespace CS230 {
    class Texture {
    public:
        Texture();
        Texture(const std::filesystem::path& filePath);
        void Load(const std::filesystem::path& filePath);
        void Draw(math::TransformMatrix displayMatrix);
        void Draw(math::TransformMatrix displayMatrix, math::vec2 texelPos, math::vec2  frameSize);
        math::ivec2 GetSize();
    private:
        doodle::Image image;
    };
}