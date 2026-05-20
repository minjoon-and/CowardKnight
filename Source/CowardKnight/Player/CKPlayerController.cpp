// Copyright Epic Games, Inc. All Rights Reserved.

#include "CKPlayerController.h"

#include "EnhancedInputSubsystems.h"

void ACKPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!DefaultMappingContext)
	{
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (InputSubsystem)
	{
		InputSubsystem->AddMappingContext(DefaultMappingContext, MappingPriority);
	}
}
