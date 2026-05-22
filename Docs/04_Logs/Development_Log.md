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
