# Unreal 규격

## 공식 방향

이 프로젝트는 자체 시스템을 먼저 만들기보다 Unreal Engine의 공식 패턴을 우선합니다.

중요한 참고 기준:

- Epic의 Recommended Asset Naming Conventions.
- Lyra Sample Game 아키텍처.
- Gameplay Ability System 문서.
- Enhanced Input 워크플로우.
- 에셋 로딩/쿠킹 구조가 필요해질 때 Asset Manager와 Primary Asset Labels.

## 에셋 네이밍

Epic이 권장하는 에셋 네이밍 형태를 사용합니다.

```text
[AssetTypePrefix]_[AssetName]_[Descriptor]_[OptionalVariant]
```

예시:

```text
BP_BoltCharacter
ABP_Bolt
SK_Bolt
M_BoltArmor
MI_BoltArmor_Blue
WBP_LevelUpChoice
IA_Move
IMC_Player
DA_Ability_PanicSprint
```

## 자주 쓰는 Prefix

더 강한 Unreal 관례가 없다면 아래 prefix를 사용합니다.

- `BP_`: Blueprint
- `WBP_`: Widget Blueprint
- `ABP_`: Animation Blueprint
- `SK_`: Skeletal Mesh
- `SM_`: Static Mesh
- `SKEL_`: Skeleton
- `PHYS_`: Physics Asset
- `M_`: Material
- `MI_`: Material Instance
- `T_`: Texture
- `FXS_`: Niagara System
- `FXE_`: Niagara Emitter
- `IA_`: Input Action
- `IMC_`: Input Mapping Context
- `DA_`: Data Asset
- `DT_`: Data Table
- `CT_`: Curve Table
- `GA_`: Gameplay Ability
- `GE_`: Gameplay Effect
- `GC_`: Gameplay Cue

## Lyra에서 참고할 아키텍처

프로젝트에 필요해질 때 Lyra에서 아래 아이디어를 빌려옵니다.

- 오래 유지될 게임플레이 로직과 시각 에셋을 분리합니다.
- 기능 중심 도메인 구조를 선호합니다.
- Legacy Input 대신 Enhanced Input을 사용합니다.
- 상태와 이벤트 이름에는 Gameplay Tags를 사용합니다.
- 레벨업 능력이 충분히 복잡해지면 Gameplay Ability System을 사용합니다.
- UI는 하나의 HUD Widget에 모두 연결하지 않고, 레이어와 재사용 구조를 갖춥니다.

프로젝트가 아직 필요로 하지 않는 Lyra의 복잡도는 가져오지 않습니다.

## Cropout에서 참고할 범위 감각

Cropout에서는 아래 방향을 참고합니다.

- 1인 개발자가 관리 가능한 콘텐츠 범위를 유지합니다.
- 환경과 NPC 구성을 명확하게 정리합니다.
- 과한 설계보다 읽기 쉬운 작은 시스템을 선호합니다.

## Parrot에서 참고할 게임플레이

Parrot에서는 아래 방향을 참고합니다.

- 횡스크롤 카메라 제한.
- CharacterMovement 기반 이동.
- 단순하고 읽기 쉬운 전투 접촉.
- 좌→우 진행 기반 스테이지 흐름.

## Content Browser 정리

게임 전용 에셋은 `Content/CowardKnight/` 아래에 둡니다.

Marketplace 또는 Sample 에셋은 검토 전까지 원래 import 폴더에 둡니다.

실제 게임에서 사용할 때는 `Content/CowardKnight/` 아래에 프로젝트 소유 wrapper asset 또는 child Blueprint를 만듭니다.

## 데이터 기반 규칙

레벨업 선택지, 적 웨이브 정의, 스테이지 정의, 능력 튜닝은 첫 prototype으로 형태가 증명된 뒤 Data Asset 또는 Data Table로 옮기는 것을 목표로 합니다.

초기 prototype에서는 직접 Blueprint 또는 C++ 값을 사용할 수 있습니다.

다만 임시 값이면 개발 로그에 남겨야 합니다.

## 출처

- Epic Games, Recommended Asset Naming Conventions: https://dev.epicgames.com/documentation/pl-pl/unreal-engine/recommended-asset-naming-conventions-in-unreal-engine-projects
- Epic Games, Lyra Sample Game: https://dev.epicgames.com/documentation/unreal-engine/lyra-sample-game-in-unreal-engine
- Epic Games, Gameplay Ability System: https://dev.epicgames.com/documentation/unreal-engine/gameplay-ability-system
- Epic Games, Primary Asset Labels API: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/Engine/UAssetManager/ApplyPrimaryAssetLabels
