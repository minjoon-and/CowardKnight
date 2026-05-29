// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "CKAssetManager.generated.h"

/**
 * CowardKnight 전용 AssetManager.
 *
 * DefaultEngine.ini의 AssetManagerClassName으로 등록되어 엔진 기본 AssetManager 자리를 차지합니다.
 * 현재는 빈 서브클래스. 첫 Data Asset 카탈로그가 등장하거나 비동기 로딩이 필요해질 때
 * Primary Asset Labels·번들 로딩 책임이 여기에 추가됩니다.
 *
 * 지금 빈 골격으로 박아두는 이유: 나중에 Engine 기본 클래스에서 우리 클래스로 갈아끼우는 마이그레이션 비용 회피.
 */
UCLASS()
class COWARDKNIGHT_API UCKAssetManager : public UAssetManager
{
	GENERATED_BODY()
};
