# 세션 인계 노트

각 세션 종료 시 `/세션마감`이 새 항목을 최상단에 추가합니다.
`/세션이어가기`가 최상단부터 읽어 이전 컨텍스트를 복원합니다.

공식 개발 로그는 `Development_Log.md`를 사용합니다.

---

## 2026-05-29 - 게임 프레임워크 골격 구축과 세션 인계 워크플로우 도입

**한 일**
- 게임 프레임워크 아키텍처 문서 작성 (책임 분리·경계 4문장 규칙·Defer 트리거)
- C++ 빈 골격 6쌍 추가: CKGameInstance, CKGameState, CKAssetManager, CKGameplayTags, CKPlayerState, CKHUD
- CKGameMode에 GameState/PlayerState/HUD 클래스 지정 + Build.cs에 GameplayTags 모듈 추가
- DefaultEngine.ini에 GameInstance·AssetManager 등록, GlobalDefaultGameMode를 BP_DefaultGameMode로 전환
- 사용자가 BP 자식 5개 생성: BP_BoltCharacter, BP_BoltPlayerController, BP_GameHUD, BP_DefaultGameMode, IMC_Player
- 변경분을 docs/feat/build/config/content 5개 커밋으로 분할 후 push
- 세션 인계 워크플로우 도입: `/세션마감`, `/세션이어가기` 슬래시 커맨드 추가 + CLAUDE.md·Docs/README.md 갱신

**핵심 결정**
- 결정: World Settings 6슬롯 + GameInstance를 즉시 빈 골격으로 구축 — 이유: 책임 분리를 코드로 박아두면 새 멤버 위치 결정이 0.5초
- 결정: AssetManager 빈 골격 사전 등록 — 이유: 데이터 자산 본격화 시 엔진 기본 클래스에서 마이그레이션 비용 회피
- 결정: GameplayTags는 Lyra 스타일 네이티브 헤더 — 이유: 컴파일 타임 안전성 + IDE 자동완성
- 결정: GAS는 문서로만 트리거 명시 (능력 8~10개 + 상호작용 등 2조건) — 이유: 능력 0개 상태에서 학습 비용 회피
- 결정: Subsystem은 placeholder 없이 문서만 — 이유: 만능 추상 클래스는 안티패턴, 목적별 등장 시 생성
- 결정: GameMode→BP 자식 연결은 Pattern A (BP_DefaultGameMode 중간 다리) — 이유: ConstructorHelpers 하드코딩 경로는 자산 이동에 취약

**다음 세션 시작점**
- 캐릭터 작업: 볼트가 맵에서 "제자리 걷기" 애님 재생까지
  1. BP_BoltCharacter Mesh에 SKM_Manny 연결 (`Content/_Vendor/dRealWarriorPack/Demo/Characters/Mannequins/Meshes/`)
  2. Mesh Transform: Location Z=-90, Rotation Z=-90 (캡슐 바닥 정렬 + 횡스크롤 방향)
  3. Anim Class 임시 지정: ABP_Warrior 사용하거나 Warrior_Walk_InPlace 재생용 ABP 신규
  4. NewMap에서 PIE 실행 → 캐릭터 메시 + 제자리 걷기 애님 확인
- 캐릭터 검증 통과 후 IA 4개(IA_Move/Jump/Attack/Skill) + IMC_Player 매핑 → BP 슬롯 채우기

**주의 / 미결**
- 시각 확인 미완료 (사용자만 가능):
  - World Settings → Selected GameMode 6슬롯이 CK* 접두사로 채워졌나
  - Project Settings → Engine → General Settings → Asset Manager Class Name = CKAssetManager
  - Project Settings → Maps & Modes → Default GameMode = BP_DefaultGameMode
- NewMap.umap 변경은 에디터 자동 저장으로 판단해 content 커밋에 포함 — 의도와 다르면 사용자 확인
- 이번 세션의 슬래시 커맨드 추가·문서 변경·이 인계 노트는 별도 `chore` 커밋으로 묶어 push 진행

**관련 커밋**
- `916e87d` content: 게임 프레임워크 BP 자식과 기본 입력 컨텍스트 추가
- `b519383` config: GameInstance·AssetManager·Default GameMode 등록
- `abd72dc` build: GameplayTags 모듈 의존성 추가
- `7b19b7c` feat: 게임 프레임워크 C++ 빈 골격 클래스 추가
- `de2aa65` docs: 게임 프레임워크 아키텍처 문서 추가

---
