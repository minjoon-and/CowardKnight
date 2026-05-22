# 코딩 컨벤션

## 기준

Unreal Engine C++ 스타일을 최우선으로 따릅니다.

Unreal 타입과 reflection 매크로를 일관되게 사용합니다.

- Reflection 대상 타입에는 `UCLASS`, `USTRUCT`, `UENUM`, `UINTERFACE`를 사용합니다.
- Reflection, 에디터 노출, GC 추적이 필요한 멤버에는 `UPROPERTY`를 사용합니다.
- Blueprint에 노출하거나 Unreal delegate binding이 필요한 함수에는 `UFUNCTION`을 사용합니다.
- UObject 멤버 참조에는 상황에 맞게 `TObjectPtr<>`를 사용합니다.

## 클래스 접두사

Unreal 표준 접두사를 사용합니다.

- Actor 파생 클래스는 `A`.
- UObject 파생 클래스는 `U`.
- 구조체는 `F`.
- 열거형은 `E`.
- 인터페이스는 `I`.

프로젝트 고유 클래스명은 Unreal 접두사 뒤에 `CK`를 붙입니다.

예시:

- `ACKGameMode`
- `ACKBoltCharacter`
- `UCKHealthComponent`
- `FCKAbilityDefinition`
- `ECKAbilityCategory`

## 파일 이름

파일 이름은 주요 클래스명을 명확히 드러내야 합니다.

권장:

```text
CKBoltCharacter.h
CKBoltCharacter.cpp
CKGameMode.h
CKGameMode.cpp
```

## 헤더 구성

헤더는 아래 순서를 따릅니다.

1. Copyright.
2. `#pragma once`.
3. 최소 include.
4. generated header include.
5. Forward declaration.
6. Class declaration.

헤더에서는 forward declaration을 선호하고, 실제 include는 `.cpp`에 둡니다.

## 접근 제어

Blueprint에서 조정할 게임플레이 멤버는 기본적으로 `protected`를 사용합니다.

구현 세부사항은 `private`를 사용합니다.

Blueprint 노출은 디자이너나 에셋이 실제로 값을 만져야 할 때만 허용합니다.

Category 이름은 일관되게 사용합니다.

- `Input`
- `Camera`
- `Combat`
- `Ability`
- `Stage`
- `UI`
- `Debug`

## Tick 규칙

기본적으로 Tick을 켜지 않습니다.

Tick은 아래 조건을 만족할 때만 사용합니다.

- 실제로 매 프레임 갱신이 필요합니다.
- Timer, Event, Movement Component, Ability Task보다 Tick이 더 적합합니다.
- Tick을 쓰는 이유가 코드에서 명확하거나 짧은 주석으로 설명됩니다.

## Blueprint 규칙

C++는 오래 유지될 게임플레이 계약을 담당합니다.

Blueprint는 아래 영역을 담당합니다.

- 시각적 조립.
- 애니메이션 연결.
- VFX/SFX 타이밍.
- UI 레이아웃.
- Prototype 튜닝.

오래 유지될 핵심 규칙을 Blueprint Graph에만 숨겨두지 않습니다.

의도적인 이유가 있을 때만 예외를 허용합니다.

## 주석

주석은 의도, tradeoff, Unreal의 비직관적인 동작을 설명할 때 사용합니다.

명백한 대입이나 함수 호출을 설명하는 주석은 쓰지 않습니다.

## LLM 코딩 체크리스트

코드를 수정하기 전에 LLM은 아래 질문에 답해야 합니다.

- 이 변경은 어느 module/domain이 소유하는가?
- 대응되는 `Content/` 도메인 폴더가 존재하는가?
- 이 코드는 C++로 고정할 만큼 안정적인가, 아니면 Data/Blueprint prototype으로 시작해야 하는가?
- 가장 작은 buildable step은 무엇인가?
- 사용자가 코드 수정을 승인했는가?
