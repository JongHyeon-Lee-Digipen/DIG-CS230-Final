/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: GameState.cpp
Purpose: Base class for different game states
Project: CS230
Author: Jemin.Shin
Creation date: 3/27/2022
-----------------------------------------------------------------*/

#include "GameStateManager.h"
#include "Engine.h"
#include <iostream>

#include "../Game/Splash.h"

using namespace std;

CS230::GameStateManager::GameStateManager()
{
	gameStates = {};
	nextGameState = { nullptr };
	currGameState = { nullptr };
	state = State::START;
}


void CS230::GameStateManager::AddGameState(GameState& gameState)
{
	gameStates.push_back(&gameState);
}


void CS230::GameStateManager::SetNextState(int initState)
{
	
	nextGameState = gameStates[initState];
}

void CS230::GameStateManager::Shutdown()
{
	nextGameState =  nullptr ;
}

void  CS230::GameStateManager::ReloadState()
{
	state = State::UNLOAD;
}


void CS230::GameStateManager::Update(double dt)
{

	switch (state)
	{
	case CS230::GameStateManager::State::START:
		if (gameStates.empty())
		{
			Engine::GetLogger().LogError("Error ! ");
			state = State::SHUTDOWN;
		}
		else
		{
			nextGameState = gameStates[0];
			state = State::LOAD;
			
		}
		break;

	case CS230::GameStateManager::State::LOAD:
		currGameState = nextGameState;

		Engine::GetLogger().LogEvent("Load" + currGameState->GetName());
		currGameState->Load();
		Engine::GetLogger().LogEvent("Load Complete ");
		state = State::UPDATE;
		break;
	case CS230::GameStateManager::State::UPDATE:
	{
		if (currGameState != nextGameState)
		{
			state = State::UNLOAD;
		}
		else
		{
			Engine::GetLogger().LogVerbose("Update " + currGameState->GetName());
			currGameState->Update(dt);
			currGameState->Draw();
		}
		
	}	
		break;
	case CS230::GameStateManager::State::UNLOAD:
		Engine::GetLogger().LogEvent("Unload " + currGameState->GetName());
		currGameState->Unload();
		if (nextGameState == nullptr) {
			state = State::SHUTDOWN;
			break;
		}
		state = State::LOAD;
		break;
	case CS230::GameStateManager::State::SHUTDOWN:

		state = State::EXIT;
		break;
	case CS230::GameStateManager::State::EXIT:

		break;
	}
}