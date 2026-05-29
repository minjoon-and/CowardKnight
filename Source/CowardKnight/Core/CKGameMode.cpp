// Copyright Epic Games, Inc. All Rights Reserved.

#include "CKGameMode.h"

#include "CKGameState.h"
#include "Characters/CKBoltCharacter.h"
#include "Player/CKPlayerController.h"
#include "Player/CKPlayerState.h"
#include "UI/CKHUD.h"

ACKGameMode::ACKGameMode()
{
	DefaultPawnClass = ACKBoltCharacter::StaticClass();
	PlayerControllerClass = ACKPlayerController::StaticClass();
	GameStateClass = ACKGameState::StaticClass();
	PlayerStateClass = ACKPlayerState::StaticClass();
	HUDClass = ACKHUD::StaticClass();
}
