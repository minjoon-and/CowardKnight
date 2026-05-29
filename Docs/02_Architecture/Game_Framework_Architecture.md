# 게임 프레임워크 아키텍처

이 문서는 CowardKnight의 게임 프레임워크 클래스(GameMode, GameState, PlayerController, PlayerState, Pawn, HUD, GameInstance)와 그 주변 시스템(AssetManager, Subsystem, GameplayTags, GAS)의 **책임 분리**와 **도입 시점**을 정의합니다.

코드를 어디에 둘지 헷갈리면 이 문서를 먼저 읽습니다.

## 원칙

1. **언리얼 표준 프레임워크 슬롯을 먼저 채운다.** 자체 시스템을 만들기 전에 GameMode/GameState/PlayerController/PlayerState/Pawn/HUD/GameInstance 자리에 우리 클래스를 둡니다. 엔진이 이미 이 슬롯들의 생명주기를 관리하고 있어서, 같은 일을 하는 별도 매니저를 만들면 중복·꼬임이 생깁니다.
2. **빈 골격이라도 먼저 만든다.** 책임 분리를 코드로 박아두면, 새 멤버를 어디에 둘지 0.5초 안에 결정됩니다. "지금 안 쓰니까 안 만든다"는 결국 GameMode·Character로 잡식성 비대화로 끝납니다.
3. **복잡한 시스템(Subsystem, GAS, 추가 AssetManager 책임)은 트리거가 올 때만 도입한다.** 어떤 트리거에 어떤 시스템이 들어오는지 이 문서 하단에 명시합니다.

## 클래스별 책임

### GameMode (`ACKGameMode`)

- **위치**: `Source/CowardKnight/Core/`
- **역할**: 게임의 룰 엔진. 권한 있는 1개 인스턴스.
- **담당**:
  - 어떤 Pawn/Controller/State/HUD 클래스를 쓸지 지정 (생성자).
  - 플레이어 입장·재시작·게임 종료 흐름.
  - 웨이브 진행·보스 스폰·스테이지 클리어 판정 (서버 권한).
- **담지 않음**:
  - 현재 웨이브 번호 같은 *상태값* → GameState로.
  - 플레이어 누적 값 → PlayerState로.
  - 입력 처리 → PlayerController로.

### GameState (`ACKGameState`)

- **위치**: `Source/CowardKnight/Core/`
- **역할**: 게임 단위 *현재 상태 스냅샷*. 모든 액터가 읽을 수 있는 게임 공용 정보.
- **담당**:
  - 현재 웨이브 번호, 경과 시간, 남은 적 수, 보스 등장 플래그.
  - HUD가 구독해서 화면에 표시하는 값들.
- **싱글에서도 쓰는 이유**: 책임 분리. GameMode는 룰을 *실행*하고, GameState는 결과를 *보관*합니다. 둘을 합치면 GameMode가 비대해지고, 다른 액터가 GameMode에 직접 접근하는 안티패턴이 생깁니다.

### PlayerController (`ACKPlayerController`)

- **위치**: `Source/CowardKnight/Player/`
- **역할**: 입력·UI 명령·Pawn 소유.
- **담당**:
  - Enhanced Input Mapping Context 등록.
  - 입력 → 본인이 소유한 Pawn으로 전달.
  - 일시정지·메뉴 열기 같은 UI 명령.
  - 카메라 후처리 (현재는 캐릭터에 카메라가 내장).
- **담지 않음**:
  - XP·레벨 같은 *누적 값* → PlayerState로.
  - 실제 이동·공격 *실행* → Pawn/Character로.

### PlayerState (`ACKPlayerState`)

- **위치**: `Source/CowardKnight/Player/`
- **역할**: 플레이어 단위 *누적 값*.
- **담당**:
  - XP, 레벨, 선택한 능력 카드 목록.
  - 처치 수, 점수, 최대 도달 웨이브.
- **Character와 구분 기준**: "캐릭터가 죽어도 유지되어야 하는 값"이면 PlayerState. "캐릭터에 종속된 값" (현재 HP, 현재 속도 버프)이면 Character.

### Pawn / Character (`ACKBoltCharacter`)

- **위치**: `Source/CowardKnight/Characters/`
- **역할**: 움직이는 본체. 볼트.
- **담당**:
  - 이동·점프·공격 *실행*.
  - 현재 HP·현재 버프 등 *캐릭터 종속 상태*.
  - 카메라 (Phase 1 한정. 별도 카메라 시스템 도입 시 분리).

### HUD (`ACKHUD`)

- **위치**: `Source/CowardKnight/UI/`
- **역할**: UI 진입점.
- **담당**:
  - 게임 시작 시 메인 HUD 위젯 생성·연결.
  - 위젯 레이어 관리 (게임 HUD, 카드 선택, 일시정지).
  - GameState·PlayerState를 구독해서 위젯에 전달하는 어댑터.
- **위젯 자체의 로직은 담지 않음**. 위젯은 UMG/WBP에서.

### GameInstance (`UCKGameInstance`)

- **위치**: `Source/CowardKnight/Core/`
- **역할**: 영속 레이어. 맵 전환 사이에도 살아남는 유일한 객체.
- **담당**:
  - 향후 도입할 Subsystem들의 호스트 (저장·설정·오디오).
  - 세션 단위 데이터 (직전 스테이지 결과, 현재 진행 중인 런 정보).
- **현재 상태**: 빈 골격. 첫 Subsystem 또는 첫 영속 데이터(저장 시스템) 등장 시 살이 붙음.

## 책임 경계 4문장 규칙

새 멤버를 어디에 둘지 헷갈리면 아래 4문장을 순서대로 적용합니다.

1. **캐릭터가 죽으면 사라지는 값**은 Character.
2. **캐릭터가 죽어도 유지되는 값**은 PlayerState.
3. **여러 액터가 봐야 하는 게임 단위 값**은 GameState.
4. **입력 또는 UI 동작**은 PlayerController.

이 4문장에 다 안 맞으면 Subsystem 도입을 검토합니다 (아래 Defer 항목 참조).

## 데이터 흐름 예시

### 예시 1 — 웨이브 시작

```text
GameMode (룰)
  └── "다음 웨이브 시작" 결정
      └── GameState.CurrentWave += 1 (상태 기록)
          └── HUD가 GameState 구독 중 → 화면 "Wave 3" 갱신
```

### 예시 2 — 적 처치 → 레벨업

```text
Enemy (Character) 사망
  └── GameMode가 처치 통지 수신
      └── PlayerState.XP += XPReward (누적 값 가산)
          └── PlayerState가 LevelUp 판정
              └── PlayerController → HUD에 카드 선택 UI 띄우라고 명령
                  └── HUD가 WBP_LevelUpChoice 생성
                      └── 플레이어 카드 선택 → PlayerState.SelectedAbilities에 추가
```

이 흐름에서 각 클래스가 한 가지 책임만 갖는 게 핵심입니다.

## 도메인 매핑

| 클래스 | 도메인 폴더 |
| --- | --- |
| `ACKGameMode` | `Core/` |
| `ACKGameState` | `Core/` |
| `UCKGameInstance` | `Core/` |
| `UCKAssetManager` | `Core/` |
| `CKGameplayTags` | `Core/` |
| `ACKPlayerController` | `Player/` |
| `ACKPlayerState` | `Player/` |
| `ACKBoltCharacter` (Pawn) | `Characters/` |
| `ACKHUD` | `UI/` |

`Core/`에 프레임워크·전역 인프라가 모이고, 도메인 폴더는 도메인 책임을 가집니다.

## AssetManager (`UCKAssetManager`)

- **현재 역할**: `UAssetManager` 빈 서브클래스.
- **존재 이유**: `DefaultEngine.ini`의 `AssetManagerClassName`을 우리 클래스로 박아두면, 나중에 Primary Asset Labels·비동기 로딩·번들을 도입할 때 Engine 기본 클래스를 갈아끼우는 마이그레이션이 없습니다.
- **확장 트리거**:
  - 첫 Data Asset 카탈로그가 등장 (예: 능력 카드 데이터 자산 N개).
  - 또는 비동기 로딩이 필요 (스테이지 진입 시 능력 에셋 프리로드).

## GameplayTags (`CKGameplayTags`)

- **현재 역할**: 빈 네이티브 태그 헤더. 정의된 태그 0개.
- **방식**: Lyra 스타일 네이티브 태그 — `UE_DECLARE_GAMEPLAY_TAG_EXTERN` / `UE_DEFINE_GAMEPLAY_TAG`.
- **선택 이유**: 컴파일 타임 안전성, IDE 자동완성, 리네임 가능. ini 방식은 런타임에 조용히 깨짐.
- **첫 추가 시점**: 첫 상태·이벤트 라벨이 필요할 때 (예: `State.Stunned`, `Event.LevelUp`). 추가 위치는 `CKGameplayTags.h/.cpp` 한 곳에 집중.

## Defer — 지금 안 만드는 것

아래 시스템은 트리거가 올 때만 도입합니다. 트리거가 분명한데 도입을 미루면 잡식성 비대화로 끝나고, 트리거가 없는데 도입하면 학습 비용만 떠안습니다.

### Subsystem

- **현재 상태**: 클래스 없음. 문서에만 기록.
- **도입 트리거**: 첫 cross-cutting 요구사항 등장.
- **첫 후보 (예상 순서)**:
  1. `UCKSaveGameSubsystem` — 저장·로드가 필요해질 때 (영구 진행도, 설정).
  2. `UCKAudioSubsystem` — BGM 페이드·SFX 풀링이 필요해질 때.
  3. `UCKSettingsSubsystem` — 그래픽·오디오·조작 설정 메뉴가 들어올 때.
- **만들 때 원칙**:
  - 목적별로 만든다. 만능 `UCKSubsystem` 같은 추상 placeholder는 금지.
  - 호스트 결정: `UGameInstanceSubsystem` 우선. 월드 단위면 `UWorldSubsystem`. 플레이어 단위면 `ULocalPlayerSubsystem`.

### GAS (Gameplay Ability System)

- **현재 상태**: 플러그인 비활성, 코드 없음. 능력은 일반 C++로 구현.
- **도입 트리거** (아래 중 **2개 이상** 만족):
  1. 능력이 8~10개를 넘어선다.
  2. 능력끼리 상호작용한다 (시너지·조건부 발동).
  3. 데이터 주도 밸런싱이 필요해진다 (수치 자주 튜닝).
  4. 상태 효과(스턴·슬로우·버프 스택)가 본격 등장한다.
- **도입 시 최소 셋업**:
  - `.uproject`에 `GameplayAbilities` 플러그인 활성화.
  - `Build.cs`에 `GameplayAbilities`, `GameplayTasks` 모듈 추가 (`GameplayTags`는 이미 있음).
  - `UCKAbilitySystemComponent` (ASC 서브클래스).
  - `UCKAttributeSet` (속성 컨테이너).
  - `UCKGameplayAbility` (능력 베이스).
  - `ACKBoltCharacter`에 ASC 부착 + `IAbilitySystemInterface` 구현.

### 추가 AssetManager 책임

- **현재 상태**: 빈 서브클래스.
- **확장 트리거**: 위 AssetManager 섹션 참조.

### 영속 데이터 (Save/Load)

- **현재 상태**: 없음.
- **도입 트리거**: Phase 2 진입, 또는 첫 영구 진행도(언락된 능력·최고 점수) 등장.
- **도입 시**: `UCKSaveGameSubsystem` + `USaveGame` 서브클래스.

## 검증 방법

이 문서를 기반으로 골격이 구축된 뒤:

1. PIE 실행 시 GameMode 로그에서 `CKGameInstance`, `CKGameState`, `CKPlayerState`, `CKHUD`가 모두 우리 클래스로 인스턴스화됐는지 확인.
2. World Settings → Game Mode에서 6개 슬롯이 모두 `CK` 접두사 클래스로 채워져 있는지 확인.
3. `Project Settings → Project → Maps & Modes`에서 `Game Instance Class`와 `Asset Manager Class Name`이 우리 클래스로 지정되어 있는지 확인.

## 변경 기록

이 문서를 수정하거나 위 아키텍처가 바뀌면 `Docs/04_Logs/Development_Log.md`에 기록합니다.
