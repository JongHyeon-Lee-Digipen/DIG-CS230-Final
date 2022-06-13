/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Ball.cpp
Purpose: This is the service provider for our games engine services
Project: CS230
Author: Jemin.Shin
Creation date: 3/27/2021
-----------------------------------------------------------------*/
#include "Mode1.h"	//Level1::gravity
#include "Ball.h"

Ball::Ball(math::vec2 startPos) : initPosition(startPos), velocity({ 0,0 }), currState(&state_land) {}

void Ball::Load() {
	sprite.Load("assets/Ball.spt");
	position = initPosition;
	velocity = { 0, 0 };
	currState = &state_land;
	currState->Enter(this);
}

void Ball::Update(double dt)
{
	currState->Update(this, dt);
	sprite.Update( dt);
	position += velocity * dt;
	currState->TestForExit(this);

	objectMatrix = math::TranslateMatrix(position);
}


void Ball::Draw(math::TransformMatrix cameraMatrix)
{
	sprite.Draw(cameraMatrix * objectMatrix);
}

void Ball::ChangeState(State* newState)
{
	Engine::GetLogger().LogDebug("Ball Leaving State : " + currState->GetName() + "Entering State: " + newState->GetName());
	currState = newState;
	currState->Enter(this);
}

void Ball::State_Bounce::Enter(Ball* ball)
{
	ball->sprite.PlayAnimation(static_cast<int>(Ball_Anim::None_Anim));
	ball->velocity.y = Ball::bounceVelocity;
}

void Ball::State_Bounce::Update(Ball* ball, double dt)
{
	ball->velocity.y -= Mode1::gravity * dt;
}

void Ball::State_Bounce::TestForExit(Ball* ball)
{

	if (ball->position.y < Mode1::floor )
	{
		ball->position.y = Mode1::floor ;
		ball->velocity.y = 0;
		ball->ChangeState(&ball->state_land);
	}
}

std::string Ball::State_Bounce::GetName()
{
	return "bounce";
}


void Ball::State_Land::Enter( Ball* ball) 
{
	ball->sprite.PlayAnimation(static_cast<int>(Ball_Anim::Squish_Anim));
}

void Ball::State_Land::Update([[maybe_unused]] Ball* ball, [[maybe_unused]] double dt) 
{
	ball->velocity.y -= Mode1::gravity * dt;
}

void Ball::State_Land::TestForExit([[maybe_unused]] Ball* ball)
{
	if (ball->sprite.IsAnimationDone() == true)
	{
		ball->ChangeState(&ball->stateBounce);
	}
}

std::string Ball::State_Land::GetName()
{
	return "land";
}