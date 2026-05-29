// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CKHUD.generated.h"

/**
 * CowardKnight의 UI 진입점.
 *
 * 게임 시작 시 메인 HUD 위젯을 생성·연결하고, 위젯 레이어(게임 HUD·카드 선택·일시정지)를 관리합니다.
 * GameState·PlayerState를 구독해서 위젯에 값을 전달하는 어댑터 역할도 합니다.
 *
 * 위젯 자체의 시각·레이아웃 로직은 UMG/WBP에서 담당합니다.
 *
 * 책임 분리: Game_Framework_Architecture.md 참조.
 */
UCLASS()
class COWARDKNIGHT_API ACKHUD : public AHUD
{
	GENERATED_BODY()
};
