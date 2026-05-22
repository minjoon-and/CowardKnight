# 폴더 규칙

## 최상위 폴더

프로젝트 루트:

- `Docs/`: 사람과 LLM 에이전트가 읽는 Markdown 문서.
- `Source/CowardKnight/`: C++ 소스 코드. `CowardKnight`는 C++ 모듈 이름이라 이 폴더 이름은 고정입니다.
- `Content/`: Unreal 에셋. 게임 도메인 폴더를 이 폴더 바로 아래에 둡니다.
- `Config/`: Unreal 프로젝트 설정.

## 미러 규칙

게임플레이 도메인은 C++와 에셋 양쪽에서 같은 이름을 씁니다.

- C++ 도메인: `Source/CowardKnight/<도메인>/`
- 대응 에셋: `Content/<도메인>/`

`Source/`의 `CowardKnight`는 C++ 모듈 폴더라 Unreal이 강제합니다. `Content/`에는 이 모듈 폴더를 두지 않고 도메인 폴더를 바로 아래에 둡니다. 양쪽에서 일치시키는 것은 **1차 도메인 폴더 이름**입니다.

예시:

```text
Source/CowardKnight/Characters/   ↔   Content/Characters/
Source/CowardKnight/Combat/       ↔   Content/Combat/
Source/CowardKnight/UI/           ↔   Content/UI/
```

C++ 도메인이 존재하면 대응되는 에셋 도메인도 존재해야 합니다. 모든 하위 폴더가 완벽하게 1:1일 필요는 없지만, 1차 도메인 폴더 이름은 일치시킵니다.

임포트한 Marketplace/Sample 에셋은 도메인 폴더가 아닙니다. 아래 '외부 에셋' 규칙을 따릅니다.

## 도메인 목록

Phase 1 프로토타입 기준으로 아래 9개 도메인을 사용합니다.

```text
Source/CowardKnight/          Content/
  AI/                           AI/
  Characters/                   Characters/
  Combat/                       Combat/
  Core/                         Core/
  Data/                         Data/
  Input/                        Input/
  Player/                       Player/
  Stages/                       Stages/
  UI/                           UI/
```

## 도메인 의미

`Core`
: GameMode, GameState, GameInstance, 전역 프로젝트 클래스, 부트스트랩.

`Player`
: PlayerController, PlayerState, LocalPlayer, 플레이어 세션 단위 클래스. Lyra가 PlayerController/PlayerState를 별도 `Player` 도메인으로 두는 방식을 따릅니다.

`Characters`
: 볼트, 적, NPC, Animation Blueprint, 캐릭터 전용 컴포넌트.

`Combat`
: 히트 판정, 대미지, 공격 trace, 전투 컴포넌트, 무기 로직.

`Input`
: Enhanced Input Action, Mapping Context, 입력 설정 데이터.

`AI`
: Behavior Tree, Blackboard, AI Controller, Perception, 적 의사결정 로직.

`Stages`
: 스테이지 정의, 웨이브 정의, 스폰 규칙, 스테이지 스크립팅. 스테이지 맵 파일은 `Content/Maps/Stages/`에 둡니다.

`UI`
: Widget, HUD, 메뉴, 레벨업 카드 UI, CommonUI 스타일 레이아웃 클래스.

`Data`
: Data Asset, Data Table, Curve, 설정용 에셋.

## 도메인 추가 규칙

프로토타입 단계에서는 도메인을 최소한으로 유지합니다.

아래 도메인은 지금은 만들지 않고, 실제로 필요해질 때 `Source`와 `Content` 양쪽에 함께 추가합니다.

- `AbilitySystem`: 레벨업 능력이 Gameplay Ability System을 쓸 만큼 복잡해질 때.
- `Camera`: 카메라 볼륨·카메라 모드 등 별도 카메라 로직이 필요해질 때. 현재 횡스크롤 카메라는 캐릭터에 내장되어 있습니다.
- `Feedback`: VFX, SFX, Camera Shake, Hit Stop을 별도로 관리해야 할 때.
- `Developer`: 디버그 전용 도구나 Editor Utility가 필요해질 때.

도메인을 추가하거나 제거하면 이 문서와 `CLAUDE.md`의 도메인 목록을 함께 갱신하고, 개발 로그에 남깁니다.

## 맵 폴더 (Maps)

모든 맵(`.umap`)은 `Content/Maps/` 아래에 모읍니다.

- 맵은 경로로 로드되는 특별한 에셋이라, 도메인 폴더에 흩어두지 않고 한곳에 모읍니다.
- `Maps`는 도메인 폴더가 아니지만 우리 게임 콘텐츠이므로 접두사 없이 둡니다.
- 용도별 하위 폴더로 정리합니다.
  - `Maps/Stages/`: 스테이지 플레이 맵 (Stage01, Stage02 등)
  - `Maps/Menu/`: 메인 메뉴, 게임오버 등 프론트엔드 맵
  - `Maps/Dev/`: 화이트박스, 테스트용 맵
- `Stages` 도메인은 맵 파일이 아니라 스테이지 로직·데이터(웨이브·스폰 정의, 스테이지 Blueprint)를 담당합니다.
- 맵을 옮기거나 이름을 바꿀 때는 반드시 Unreal Editor의 Content Browser에서 합니다. 파일 탐색기로 옮기면 참조가 깨집니다.
- 기본 맵(`EditorStartupMap`, `GameDefaultMap`)으로 지정된 맵을 옮기면 Project Settings의 Maps & Modes에서 경로를 갱신합니다.

## 외부 에셋 (_Vendor)

Fab 등에서 받은 Marketplace/Sample 에셋은 `Content/_Vendor/` 아래에 모읍니다.

- `_Vendor`는 도메인 폴더가 아니라 외부 에셋 원본 보관소입니다. `_` 접두사로 Content Browser에서 도메인 폴더와 구분됩니다.
- 받은 팩은 import한 이름 그대로 `Content/_Vendor/<팩이름>/`에 둡니다.
- 실제 게임에 사용할 때는 원본을 직접 쓰지 않고, 해당 도메인 폴더에 child Blueprint나 wrapper 에셋을 만들어 씁니다.
- 에셋 팩을 옮기거나 정리할 때는 반드시 Unreal Editor의 Content Browser에서 합니다. 파일 탐색기로 옮기면 에셋 참조가 깨집니다.

## Placeholder 규칙

빈 폴더는 Git 추적을 위해 `.gitkeep`만 둘 수 있습니다.

Markdown 문서는 `Source/` 또는 `Content/`에 두지 않습니다.

프로젝트 문서는 `Docs/`에 둡니다.
