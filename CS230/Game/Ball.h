/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Ball.h
Project: CS230
Author: Kevin Wright
Creation date: 2/14/2021
-----------------------------------------------------------------*/
#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Vec2.h"
#include "..\Engine\Camera.h"
#include "..\Engine\TransformMatrix.h"
#include "Ball_Anims.h"

class Ball {
public:
	Ball(math::vec2 startPos);
	void Load();
	void Update(double dt);
	void Draw(math::TransformMatrix cameraMatrix);

private:

	class State
	{
		public:
			virtual void Enter(Ball* ball) = 0;
			virtual void Update(Ball* ball, double dt) = 0;
			virtual void TestForExit(Ball* ball) = 0;
			virtual std::string GetName() = 0;
	};
	class State_Bounce : public State
	{
		void Enter(Ball* ball) override;
		void Update(Ball* ball, double dt) override;
		void TestForExit(Ball* ball) override;
		std::string GetName() override;
	};
	class State_Land : public State
	{
		void Enter(Ball* ball) override;
		void Update(Ball* ball, double dt) override;
		void TestForExit(Ball* ball) override;
		std::string GetName() override;
	};

	State_Bounce stateBounce;
	State_Land state_land;
	State* currState;

	void ChangeState(State* newState);

	CS230::Sprite sprite;
	math::TransformMatrix objectMatrix;
	math::vec2 initPosition;
	math::vec2 position;
	math::vec2 velocity;

	static constexpr double bounceVelocity = 1000;
};