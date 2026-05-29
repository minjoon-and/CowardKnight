// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CKPlayerState.generated.h"

/**
 * CowardKnight의 플레이어 단위 누적 값.
 *
 * 캐릭터가 죽어도 유지되어야 하는 값을 담습니다. XP, 레벨, 선택한 능력 카드 목록, 처치 수, 점수 등.
 * 캐릭터에 종속된 값(현재 HP, 일시 버프)은 Character에 둡니다.
 *
 * 책임 분리: Game_Framework_Architecture.md 참조.
 */
UCLASS()
class COWARDKNIGHT_API ACKPlayerState : public APlayerState
{
	GENERATED_BODY()
};
