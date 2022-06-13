/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Hero.cpp
Purpose: This is the service provider for our games engine services
Project: CS230
Author: Jemin.Shin
Creation date: 3/27/2021
-----------------------------------------------------------------*/
#include "../Engine/Engine.h"	//GetLogger
#include "Mode1.h"
#include "Hero.h"
#include"..\Engine\Camera.h"


Hero::Hero(math::vec2 startPos, const CS230::Camera& camera) : 
startPos(startPos), camera(camera), currState(&stateIdle), isFlipping(&isFlipping), isJumping(&isJumping), isRising(&isRising),
 jumpKey(CS230::InputKey::Keyboard::Up), 
moveLeftKey(CS230::InputKey::Keyboard::Left), moveRightKey(CS230::InputKey::Keyboard::Right) {}

void Hero::Load() 
{
	sprite.Load("assets/Hero.spt");
	position = startPos;
	isFlipping = false;
	currState = &stateIdle;
	velocity = { 0,0 };
	currState->Enter(this);
}

void Hero::Update(double dt) 
{
	currState->Update(this, dt);
	currState->TestForExit(this);
	position += velocity * dt;

	if (position.x < camera.GetPosition().x + sprite.GetFrameSize().x / static_cast<double>(2))
	{
		position.x = sprite.GetFrameSize().x / static_cast<double>(2) ;
		velocity.x = 0;
	}

	if (position.x > 5680)
	{
		position.x = 5680;
		velocity.x = 0;
	}
	objectMatrix = math::TranslateMatrix(position);
	if (isFlipping == true)
	{
		objectMatrix *= math::ScaleMatrix(math::vec2(-1.0, 1.0));
	}
}

void Hero::Draw(math::TransformMatrix cameraMatrix)
{
	sprite.Draw(cameraMatrix * objectMatrix);
}

math::vec2 Hero::Getposition()
{
	return position;
}

void Hero::ChangeState(State* newState) 
{
	Engine::GetLogger().LogDebug("Leaving State: " + currState->GetName() + " Entering State: " + newState->GetName());
	currState = newState;
	currState->Enter(this);
}

void Hero::State_Idle::Enter  ( Hero* hero)
{
	static_cast<int>(Hero_Anim::Hero_Idle_Anim);
}

void Hero::State_Idle::Update ([[maybe_unused]] Hero* hero, [[maybe_unused]] double dt)
{

}

void Hero::State_Idle::TestForExit(Hero* hero)
{
	 if (hero->moveLeftKey.IsKeyDown() )
	{
		hero->ChangeState(&hero->stateRunning);
		
	}
	if  (hero->moveRightKey.IsKeyDown())
	{
		hero->ChangeState(&hero->stateRunning);

	}
	if (hero->jumpKey.IsKeyDown())
	{
		hero->ChangeState(&hero->stateJumping);
	}
}

void Hero::State_Running::Enter(Hero* hero)
{
	hero->sprite.PlayAnimation(static_cast<int>(Hero_Anim::Hero_Run_Anim));
	if (hero->moveRightKey.IsKeyDown())
	{
		hero->isFlipping = false;
	}

	if (hero->moveLeftKey.IsKeyDown())
	{
		hero->isFlipping = true;
	}
}

void Hero::State_Running::Update(Hero* hero, double dt)
{
	hero->UpdateXVelocity(dt);
}

void Hero::State_Running::TestForExit(Hero* hero)
{
	if (hero->moveLeftKey.IsKeyDown() == true && hero->velocity.x > 0)
	{
		hero->ChangeState(&hero->stateSkidding);
	}
	if (hero->moveRightKey.IsKeyDown() == true && hero->velocity.x < 0)
	{
		hero->ChangeState(&hero->stateSkidding);
	}
	if (hero->velocity.x == 0)
	{
		hero->ChangeState(&hero->stateIdle);
	}
	if (hero->jumpKey.IsKeyDown() == true)
	{
		hero->ChangeState(&hero->stateJumping);
	}

}

void Hero::State_Skidding::Enter  ([[maybe_unused]]  Hero* hero)
{
	hero->sprite.PlayAnimation(static_cast<int>(Hero_Anim::Hero_Fall_Anim));
}

void Hero::State_Skidding::Update(Hero* hero, double dt)
{
	if (hero->velocity.x > 0)
	{
		hero->velocity.x -= (xDrag + xAccel) * dt;
	}
	else if (hero->velocity.x < 0)
	{
		hero->velocity.x += (xDrag + xAccel) * dt;
	}
}

void Hero::State_Skidding::TestForExit(Hero* hero)
{
	if (hero->moveLeftKey.IsKeyDown())
	{
		if (hero->velocity.x <= 0)
		{
			hero->ChangeState(&hero->stateRunning);
		}
	
	}
	else if (hero->moveRightKey.IsKeyDown())
	{
		if (hero->velocity.x >= 0)
		{
			hero->ChangeState(&hero->stateRunning);
		}
	}
	else
	{
		hero->ChangeState(&hero->stateRunning);
	}
	
	if (hero->jumpKey.IsKeyDown())
	{
		hero->ChangeState(&hero->stateJumping);
	}

}

void Hero::State_Jumping::Enter(Hero* hero) 
{
	hero->sprite.PlayAnimation(static_cast<int>(Hero_Anim::Hero_Jump_Anim));
	hero->velocity.y = jumpVelocity; 
}
void Hero::State_Jumping::Update(Hero* hero, double dt) 
{
	hero->velocity.y -= Mode1::gravity * dt; 
	hero->UpdateXVelocity(dt); 
}
void Hero::State_Jumping::TestForExit(Hero* hero) 
{
	if (hero->jumpKey.IsKeyDown() == false) {  
		hero->ChangeState(&hero->stateFalling);
		hero->velocity.y = 0;
	}
	else if (hero->velocity.y <= 0) 
	{
		hero->ChangeState(&hero->stateFalling);
	}

}
void Hero::State_Falling::Enter  ([[maybe_unused]] Hero* hero)
{
	hero->sprite.PlayAnimation(static_cast<int>(Hero_Anim::Hero_Fall_Anim));
}

void Hero::State_Falling::Update(Hero* hero, double dt)
{
	hero->velocity.y -= Mode1::gravity * dt;
	hero->UpdateXVelocity(dt);
}

void Hero::State_Falling::TestForExit(Hero* hero)
{
	if (hero->Getposition().y <= Mode1::floor)
	{
		hero->velocity.y = 0;
		hero->position.y = Mode1::floor;
		if (hero->velocity.x > 0)
		{
			if (hero->moveLeftKey.IsKeyDown() == true)
			{
				hero->ChangeState(&hero->stateSkidding);
			}
			else
			{
				hero->ChangeState(&hero->stateRunning);
			}
		}
		else if (hero->velocity.x < 0)
		{
			if (hero->moveRightKey.IsKeyDown() == true)
			{
				hero->ChangeState(&hero->stateSkidding);
			}
			else
			{
				hero->ChangeState(&hero->stateRunning);
			}
		}
		else
		{
			hero->ChangeState(&hero->stateIdle);
		}
	}
}

void Hero::UpdateXVelocity(double dt)
{
	if (moveLeftKey.IsKeyDown())
	{
		velocity.x -= xAccel * dt;
		if (velocity.x < -maxXVelocity)
		{
			velocity.x = -maxXVelocity;
		}
	}

	else if (moveRightKey.IsKeyDown())
	{
		velocity.x += xAccel * dt;
		if (velocity.x > maxXVelocity)
		{
			velocity.x = maxXVelocity;
		}
	}
	else
	{
		double xDragdt  = xDrag* dt;
		if (velocity.x > xDragdt)
		{
			velocity.x -= xDragdt;
		}
		else if (velocity.x < -xDragdt)
		{
			velocity.x += xDragdt;
		}
		else
		{
			velocity.x = 0;
		}
	}
}