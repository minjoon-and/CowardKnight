# 개발 로그

## 2026-05-20

### 프로젝트 구조 정리

본격적인 구현 전에 프로젝트 구조 정의를 시작했습니다.

결정 사항:

- 문서는 `Docs/`에 모읍니다.
- 코드와 에셋 변경은 수정 전에 명시적 승인을 받습니다.
- `Source/CowardKnight/`와 `Content/CowardKnight/`는 1차 도메인 폴더 이름을 맞춥니다.
- Unreal 공식 컨벤션과 샘플 프로젝트 패턴을 아키텍처 기준으로 삼습니다.

메모:

- 승인 규칙이 명확해지기 전에 초기 prototype C++ 파일이 만들어졌습니다.
- 앞으로 코드 변경은 먼저 승인받고 진행합니다.

## 2026-05-22

### Claude Code 작업 환경 정비

Codex에서 Claude Code로 작업 도구를 옮기면서 프로젝트 골격을 정비했습니다.

결정 사항:

- `Source/CowardKnight/Player/`를 정식 도메인으로 채택했습니다. Lyra가 PlayerController/PlayerState를 별도 `Player` 도메인에 두는 방식을 따릅니다.
- 진입점 문서 `CLAUDE.md`를 추가해 매 세션 승인 규칙과 문서 읽기 순서가 자동 적용되도록 했습니다.
- 반복 작업을 `.claude/commands/`의 한글 슬래시 커맨드로 분리했습니다.

변경:

- 루트에 `CLAUDE.md` 추가.
- `Folder_Conventions.md`에 `Player` 도메인 추가, `Core` 도메인 의미 조정.
- `Docs/README.md`에 진입점·커맨드 안내 추가, 읽기 순서에 `05_References` 보강.
- `Content/CowardKnight/Player/.gitkeep` 추가로 미러 규칙 충족.
- 커맨드 4종 추가: `/온보딩`, `/깃메시지`, `/개발로그`, `/컨벤션점검`.

메모:

- `CKPlayerController`는 이미 `Source/CowardKnight/Player/`에 있어 코드 이동 없음.
- Codex가 만든 C++(`CKBoltCharacter`, `CKGameMode`, `CKPlayerController`)는 컨벤션을 따르고 있어 유지하기로 함.
- 미결: Git 브랜치 전략과 Git LFS(`.uasset` 바이너리) 규칙은 아직 문서화되지 않음.

### Content 폴더 구조 재편과 도메인 정리

폴더 구조를 다시 검토해 프로토타입에 맞게 단순화했습니다.

결정 사항:

- `Content/CowardKnight/` 래퍼 폴더를 제거하고 도메인 폴더를 `Content/` 바로 아래로 옮겼습니다.
- 미러 규칙을 `Source/CowardKnight/<도메인>` ↔ `Content/<도메인>`으로 다시 정의했습니다. `CowardKnight`는 C++ 모듈 폴더라 `Content`에는 두지 않습니다.
- Phase 1 기준 9개 도메인만 유지: AI, Characters, Combat, Core, Data, Input, Player, Stages, UI.
- `AbilitySystem`, `Camera`, `Developer`, `Feedback` 도메인은 삭제하고, 필요해질 때 다시 추가하기로 했습니다.

변경:

- `Source/CowardKnight/`와 `Content/`에서 도메인 폴더 4개 삭제, Content 도메인 9개를 래퍼 밖으로 이동.
- `Folder_Conventions.md`를 새 구조로 재작성.
- `CLAUDE.md`, `Unreal_Standards.md`, `Project_Principles.md`, `Coding_Convention.md`의 폴더 경로 표현 갱신.

메모:

- 삭제·이동한 폴더는 모두 비어 있어(`.gitkeep`만) C++ 코드와 빌드에 영향 없음.
- `Content/dRealWarriorPack`, `Content/Fantastic_Village_Pack`은 임포트 에셋 검토용으로 그대로 둠.
- 폴더 변경 후 Unreal Editor의 Content Browser 새로고침 또는 재시작 필요.

### 커밋 작성자 표기 규칙

커밋은 개발자 단독 작성으로 기록하기로 했습니다.

- 커밋 메시지에 `Co-Authored-By` 등 AI 공동 작성자·생성 표기를 넣지 않습니다.
- `Git_Convention.md`, `CLAUDE.md`, `/깃메시지` 커맨드에 규칙을 명시했습니다.
