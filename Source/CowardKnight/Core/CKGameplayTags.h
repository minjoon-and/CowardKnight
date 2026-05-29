// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "NativeGameplayTags.h"

/**
 * CowardKnight 네이티브 GameplayTag 선언 위치.
 *
 * Lyra 스타일로 모든 프로젝트 태그를 이 한 곳에서 선언·정의합니다.
 * 컴파일 타임 안전성과 IDE 자동완성·리네임을 얻기 위해 ini 방식 대신 네이티브 태그를 사용합니다.
 *
 * 첫 태그 추가 예 (State.Stunned, Event.LevelUp 등이 필요해지면):
 *   .h: UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_State_Stunned);
 *   .cpp: UE_DEFINE_GAMEPLAY_TAG(TAG_State_Stunned, "State.Stunned");
 *
 * 현재 정의된 태그 0개. 이 헤더의 존재 자체가 "태그는 여기에 선언한다"는 컨벤션을 박아둡니다.
 */
