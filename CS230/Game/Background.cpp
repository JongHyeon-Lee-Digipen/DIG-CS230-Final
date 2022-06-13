/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Background.cpp
Project: CS230
Author: Jemin.Shin
Creation date: 5/04/2022
-----------------------------------------------------------------*/
#include "Background.h"

#include<iostream>
using namespace std;
void Background::Add(const std::filesystem::path& texturePath, int level)
{
    backgrounds.push_back(ParallaxInfo{ CS230::Texture{texturePath}, level });
}

void Background::Unload()
{
    backgrounds.clear();
}

math::ivec2 Background::Size()
{
    return backgrounds[2].texture.GetSize();
}

void Background::Draw(const CS230::Camera camera)
{
    for (int i = 0; i < backgrounds.size(); i++)
    {
        math::vec2 BackgroundVec(-camera.GetPosition() / backgrounds[i].level);
        backgrounds[i].texture.Draw(math::TranslateMatrix(BackgroundVec));
    }
}

