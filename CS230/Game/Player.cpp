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
#include "Player.h"
#include <algorithm>

Player::Player(math::vec2 startPos) :
startPos(startPos), 
Moving_Right(CS230::InputKey::Keyboard::D), Moving_Left(CS230::InputKey::Keyboard::A) {}

void Player::Load()
{
	sprite.Load("assets/Player.spt");
	position = startPos;
}

void Player::Update(double dt)
{
	if (Moving_Right.IsKeyDown() == true)
	{
		Cos_Value = Cos_Value + Speed * dt;
		Sin_Value = Sin_Value + Speed *dt;
	}
	if (Moving_Left.IsKeyDown() == true)
	{
		Cos_Value = Cos_Value - Speed * dt;
		Sin_Value = Sin_Value - Speed * dt;
	}
	velocity -= (velocity * Player::drag * dt);
	position += velocity * dt;
	position.x = (sin(Sin_Value) * 3000) * dt+ Engine::GetWindow().GetSize().x / 2.0 ;
	position.y = (cos(Cos_Value) * 3000) * dt + Engine::GetWindow().GetSize().y / 2.0;
	objectMatrix = math::TranslateMatrix(position) * math::ScaleMatrix(math::vec2(0.01));
	Player_State();
}

void Player::Draw()
{
	if (Player_Life == true)
	{
		sprite.Draw(objectMatrix);
	}
}

void Player::ChangeState(State* newState)
{
	Engine::GetLogger().LogDebug("Leaving State: " + currState->GetName() + " Entering State: " + newState->GetName());
	currState = newState;
	currState->Enter(this);
}

void Player::State_Idle::Enter(Player* player)
{
	static_cast<int>(Player_Anim::Player_Idle_Anim);
}

void Player::State_Idle::Update([[maybe_unused]] Player* player, [[maybe_unused]] double dt)
{
	//
}

void Player::State_Idle::TestForExit([[maybe_unused]] Player* player)
{
	if (Player_Life == false)
	{
		player->ChangeState(&player->stateDeath);
	}
}

void Player::State_Dead::Enter(Player* player)
{
	player->sprite.PlayAnimation(static_cast<int>(Player_Anim::Player_Death_Anim));
}

void Player::State_Dead::Update([[maybe_unused]] Player* player, [[maybe_unused]] double dt)
{
	//
}

void Player::State_Dead::TestForExit([[maybe_unused]] Player* player)
{
	if (Player_Life == true)
	{
		player->ChangeState(&player->stateIdle);
	}
}

void Player::Player_State()
{
	if (sin(Sin_Value) <= 1 && sin(Sin_Value) >= 0)
	{
		if (cos(Cos_Value) >= 0 && cos(Cos_Value) <= 1)
		{
			Current_State = 1;
		}
	}

	if (sin(Sin_Value) <= 1 && sin(Sin_Value) >= 0)
	{
		if (cos(Cos_Value) <= 0 && cos(Cos_Value) >= -1)
		{
			Current_State = 2;
		}
	}

	if (sin(Sin_Value) >= -1 && sin(Sin_Value) <= 0)
	{
		if (cos(Cos_Value) <= 0 && cos(Cos_Value) >= -1)
		{
			Current_State = 3;
		}
	}

	if (sin(Sin_Value) >= -1 && sin(Sin_Value) <= 0)
	{
		if (cos(Cos_Value) >= 0 && cos(Cos_Value) <= 1)
		{
			Current_State = 4;
		}
	}

}

int Player::Get_Num()
{
	return Current_State;
}

void Player::Set_Life(bool &Life)
{
	Player_Life = Life;
}