// Copyright Epic Games, Inc. All Rights Reserved.

#include "CKGameMode.h"

#include "Characters/CKBoltCharacter.h"
#include "Player/CKPlayerController.h"

ACKGameMode::ACKGameMode()
{
	DefaultPawnClass = ACKBoltCharacter::StaticClass();
	PlayerControllerClass = ACKPlayerController::StaticClass();
}
