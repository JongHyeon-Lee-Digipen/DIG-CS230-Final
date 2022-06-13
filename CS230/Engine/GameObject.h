/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: GameObject.h
Purpose: Base class for different game states
Project: CS230
Author: JongHyeon Lee
Creation date: 5/13/2022
-----------------------------------------------------------------*/

#pragma once

namespace math { class TransformMatrix; }

namespace CS230 {
	class GameObject {
	public:
		virtual ~GameObject() {} 
		virtual void Update(double dt) = 0;
		virtual void Draw(math::TransformMatrix cameraMatrix) = 0;
	};
}