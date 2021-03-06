/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Texture.cpp
Purpose: Wrapper class for doodle::Image
Project: CS230
Author: Kevin Wright
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#include <doodle/drawing.hpp>	//draw_image
#include "Texture.h"

CS230::Texture::Texture() {}

CS230::Texture::Texture(const std::filesystem::path& filePath)
{
	image = doodle::Image{ filePath };
}

void CS230::Texture::Load(const std::filesystem::path& filePath) {
	image = doodle::Image{ filePath };
}

void CS230::Texture::Draw(math::TransformMatrix displayMatrix) 
{
    doodle::push_settings();
    doodle::apply_matrix(displayMatrix[0][0], displayMatrix[1][0], displayMatrix[0][1], displayMatrix[1][1], displayMatrix[0][2], displayMatrix[1][2]);
    doodle::draw_image(image, 0, 0);
    doodle::pop_settings();
}

//Need to create a new Texture::Draw function to draw only part of an image (do not remove the old one)

void CS230::Texture::Draw(math::TransformMatrix displayMatrix, math::vec2 texelPos, math::vec2 frameSize)
{
    doodle::push_settings();
    doodle::apply_matrix(displayMatrix[0][0], displayMatrix[1][0], displayMatrix[0][1], displayMatrix[1][1], displayMatrix[0][2], displayMatrix[1][2]);
    doodle::draw_image(image, 0, 0, static_cast<double>(frameSize.x), static_cast<double>(frameSize.y), texelPos.x, texelPos.y);
    doodle::pop_settings();
}

math::ivec2 CS230::Texture::GetSize() { return { image.GetWidth(), image.GetHeight() }; }