// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CKGameInstance.generated.h"

/**
 * CowardKnight의 영속 레이어.
 *
 * 맵 전환 사이에도 살아남는 유일한 객체이고, 향후 도입할 Subsystem들(Save/Audio/Settings)의 호스트 역할을 합니다.
 * 현재는 빈 골격. 첫 Subsystem 또는 첫 영속 데이터 등장 시 살이 붙습니다.
 *
 * 책임 분리: Game_Framework_Architecture.md 참조.
 */
UCLASS()
class COWARDKNIGHT_API UCKGameInstance : public UGameInstance
{
	GENERATED_BODY()
};
