// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CKGameState.generated.h"

/**
 * CowardKnight의 게임 단위 현재 상태 스냅샷.
 *
 * 모든 액터가 읽을 수 있는 게임 공용 정보(현재 웨이브 번호, 경과 시간, 남은 적 수, 보스 등장 플래그)를 보관합니다.
 * GameMode가 룰을 실행하고, GameState는 그 결과를 보관합니다. HUD는 GameState를 구독해서 화면에 표시합니다.
 *
 * 책임 분리: Game_Framework_Architecture.md 참조.
 */
UCLASS()
class COWARDKNIGHT_API ACKGameState : public AGameStateBase
{
	GENERATED_BODY()
};
