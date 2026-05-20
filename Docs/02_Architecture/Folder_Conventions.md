# 폴더 규칙

## 최상위 폴더

프로젝트 루트:

- `Docs/`: 사람과 LLM 에이전트가 읽는 Markdown 문서.
- `Source/CowardKnight/`: C++ 소스 코드.
- `Content/CowardKnight/`: 이 게임을 위해 만든 Unreal 프로젝트 에셋.
- `Config/`: Unreal 프로젝트 설정.

프로젝트 에셋은 되도록 `Content/` 바로 아래에 두지 않습니다.

정리 전부터 존재하던 전환용 에셋은 예외로 둘 수 있습니다.

## 미러 규칙

`Content/CowardKnight/`는 `Source/CowardKnight/`의 주요 게임플레이 도메인을 따라갑니다.

C++ 도메인이 존재하면, 대응되는 에셋 도메인도 존재해야 합니다.

예시:

```text
Source/CowardKnight/Characters/
Content/CowardKnight/Characters/

Source/CowardKnight/Combat/
Content/CowardKnight/Combat/

Source/CowardKnight/UI/
Content/CowardKnight/UI/
```

모든 하위 폴더가 완벽하게 1:1일 필요는 없습니다.

하지만 1차 도메인 폴더 이름은 최대한 일치시킵니다.

## 제안 Source 도메인

```text
Source/CowardKnight/
  AI/
  AbilitySystem/
  Camera/
  Characters/
  Combat/
  Core/
  Data/
  Developer/
  Feedback/
  Input/
  Stages/
  UI/
```

## 제안 Content 도메인

```text
Content/CowardKnight/
  AI/
  AbilitySystem/
  Camera/
  Characters/
  Combat/
  Core/
  Data/
  Developer/
  Feedback/
  Input/
  Stages/
  UI/
```

## 도메인 의미

`Core`
: GameMode, GameState, PlayerState, GameInstance, 전역 프로젝트 클래스.

`Characters`
: 볼트, 적, NPC, Animation Blueprint, 캐릭터 전용 컴포넌트.

`Combat`
: 히트 판정, 대미지, 공격 trace, 전투 컴포넌트, 무기 로직.

`AbilitySystem`
: Gameplay Ability System 클래스, 능력 데이터, Gameplay Effect, Attribute, Gameplay Tags.

`Input`
: Enhanced Input Action, Mapping Context, 입력 설정 데이터.

`AI`
: Behavior Tree, Blackboard, AI Controller, Perception, 적 의사결정 로직.

`Stages`
: 맵, 스테이지 정의, 웨이브 정의, 스폰 규칙, 스테이지 스크립팅.

`Camera`
: 횡스크롤 카메라 동작, 카메라 볼륨, 카메라 모드 데이터.

`UI`
: Widget, HUD, 메뉴, 레벨업 카드 UI, CommonUI 스타일 레이아웃 클래스.

`Data`
: Data Asset, Data Table, Curve, 설정용 에셋.

`Feedback`
: VFX, SFX hook, Camera Shake, Hit Stop, 화면 효과.

`Developer`
: 디버그 전용 도구, Editor Utility, prototype helper.

## Placeholder 규칙

빈 폴더는 Git 추적을 위해 `.gitkeep`만 둘 수 있습니다.

Markdown 문서는 `Source/` 또는 `Content/`에 두지 않습니다.

프로젝트 문서는 `Docs/`에 둡니다.
