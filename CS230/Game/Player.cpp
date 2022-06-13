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
startPos(startPos),  currState(currState),
Moving_Right(CS230::InputKey::Keyboard::D), Moving_Left(CS230::InputKey::Keyboard::A) {}
#include <doodle/doodle.hpp>
void Player::Load()
{
	sprite.Load("assets/Player.spt");
	Die.Load("assets/YouDie.png");
	Win.Load("assets/YouWin.png");
	position = startPos;
}

void Player::Update(double dt)
{
	Count += dt;

	if (Moving_Right.IsKeyDown() == true)
	{
		sprite.PlayAnimation(static_cast<int>(Player_Anim::Player_Idle_Anim));
		Cos_Value = Cos_Value + Speed * dt;
		Sin_Value = Sin_Value + Speed *dt;
	}
	if (Moving_Left.IsKeyDown() == true)
	{
		sprite.PlayAnimation(static_cast<int>(Player_Anim::Player_Dead_Anim));
		Cos_Value = Cos_Value - Speed * dt;
		Sin_Value = Sin_Value - Speed * dt;
	}
	velocity -= (velocity * Player::drag * dt);
	position += velocity * dt;
	position.x = (sin(Sin_Value) * 3000) * dt+ Engine::GetWindow().GetSize().x / 2.0 ;
	position.y = (cos(Cos_Value) * 3000) * dt + Engine::GetWindow().GetSize().y / 2.0;
	objectMatrix = math::TranslateMatrix(position) * math::ScaleMatrix(math::vec2(0.5));
	Player_State();
}

void Player::Draw()
{

	 if (Count > Timer && Player_Life == true)
	{
		 Count = 25;
		Win.Draw(objectMatrix);
	}
	else if (Player_Life == false)
	{
		Count = 0;
		Die.Draw(objectMatrix);
	}
	else
	 {
		 sprite.Draw(objectMatrix);
	 }

	 doodle::push_settings();
	 doodle::set_fill_color(doodle::HexColor{ 0xF0F8FF });
	 doodle::draw_text("Timer  :  " + std::to_string(25 - static_cast<int>(Count)), 0, Engine::GetWindow().GetSize().y - 100);
	 doodle::draw_text("Score  :  " + std::to_string(static_cast<int>(Count * 50)), Engine::GetWindow().GetSize().x /1.5, Engine::GetWindow().GetSize().y - 100);
	 doodle::pop_settings();

	
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
	player->sprite.PlayAnimation(static_cast<int>(Player_Anim::Player_Dead_Anim));
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