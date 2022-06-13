/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Hero.h
Project: CS230
Author: Kevin Wright
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#pragma once
#include "..\Engine\Sprite.h"
#include "..\Engine\Input.h"
#include "..\Engine\Vec2.h"
#include "..\Engine\TransformMatrix.h"
#include "..\Game\Super_Rect.h"
#include "Player_Anims.h"
class Player
{
public:
	Player() = default;
	Player(math::vec2 startPos);
	void Load();
	void Update(double dt);
	void Draw();
	void Player_State();
	int Get_Num();
	void Set_Life(bool& Life);

private:
	class State
	{
	public:
		virtual void Enter(Player* player) = 0;
		virtual void Update(Player* player, double dt) = 0;
		virtual void TestForExit(Player* player) = 0;
		virtual std::string GetName() = 0;
	};
	class State_Idle : public State {
	public:
		virtual void Enter(Player* player) override;
		virtual void Update(Player* player, double dt) override;
		virtual void TestForExit(Player* player) override;
		std::string GetName() override { return "Idle"; }
	};
	class State_Dead : public State {
	public:
		virtual void Enter(Player* player) override;
		virtual void Update(Player* player, double dt) override;
		virtual void TestForExit(Player* player) override;
		std::string GetName() override { return "Idle"; }
	};

	State_Idle stateIdle;
	State_Dead stateDeath;

	void ChangeState(State* newState);

	State* currState;

	CS230::Sprite sprite;
	math::vec2 startPos;
	math::vec2 position;
	math::vec2 velocity;

	static constexpr double drag = 1;
	static constexpr double Speed = 200;
	double currentRotation = 0;
	double Cos_Value{};
	double Sin_Value{};


	CS230::InputKey Moving_Right;
	CS230::InputKey Moving_Left;
	math::TransformMatrix objectMatrix;
};

inline Player player({0,0});
inline int  Current_State{ 3 };
inline bool Player_Life = true;