# CowardKnight

`Bolt, the Coward Knight | 겁쟁이 기사 볼트` — 2.5D 횡스크롤 로그라이크 액션 (Unreal Engine, 모바일).

이 파일은 Claude Code가 매 세션 자동으로 읽는 진입점입니다. 작업 전 아래 규칙을 먼저 적용합니다.

## 가장 중요한 규칙

1. **코드 수정 전 승인** — C++, Blueprint/Unreal 에셋, Config, 빌드 파일(`.Build.cs`, `.Target.cs`)은 수정 전 사용자에게 명시적으로 승인받습니다. 무엇을·왜 바꾸는지, 가장 작고 안전한 구현, 검증 방법을 먼저 설명합니다.
2. **천천히, 작게** — 진도를 앞서가지 않습니다. 한 번에 하나의 작은 변경 단위를 제안하고, 승인받은 만큼만 진행합니다.
3. **승인 없이 가능한 작업** — `Docs/` 문서 읽기·수정, 폴더 표시용 placeholder(`.gitkeep`) 생성, 검색·조사·설명, `.claude/` 커맨드 파일 작성.

## 작업 시작 순서

1. 이 `CLAUDE.md`를 읽습니다 (자동).
2. `Docs/README.md`를 읽고, 거기 명시된 순서대로 문서를 확인합니다.
3. 최근 결정 사항은 `Docs/04_Logs/Development_Log.md`에서 확인합니다.
4. 코드·에셋을 건드리기 전, 어느 폴더·모듈을 바꿀지 설명하고 승인받습니다.

전체 문서를 한 번에 로드하려면 `/온보딩` 커맨드를 사용합니다.

## 문서 지도

| 문서 | 내용 |
| --- | --- |
| `Docs/00_Project/Project_Principles.md` | 프로젝트 정체성, 개발 철학, 승인 규칙 |
| `Docs/01_Planning/Game_Design_Brief.md` | 게임 기획 요약, 핵심 루프, MVP 범위 |
| `Docs/02_Architecture/Development_Rules.md` | 개발 규칙, 작업 순서 |
| `Docs/02_Architecture/Folder_Conventions.md` | 폴더 구조, 도메인, 미러 규칙 |
| `Docs/02_Architecture/Coding_Convention.md` | C++ 코딩 컨벤션 |
| `Docs/02_Architecture/Git_Convention.md` | 커밋 메시지 규칙 |
| `Docs/03_Unreal/Unreal_Standards.md` | Unreal 에셋 네이밍·아키텍처 규격 |
| `Docs/04_Logs/Development_Log.md` | 개발 로그 |
| `Docs/05_References/Reference_Index.md` | 참고 자료 인덱스 |

## 핵심 구조 규칙

- C++ 도메인은 `Source/CowardKnight/<도메인>`, 대응 에셋은 `Content/<도메인>` — **1차 도메인 폴더 이름을 미러링**합니다 (`Source/`의 `CowardKnight`는 C++ 모듈 폴더).
- 도메인 9종: `AI` `Characters` `Combat` `Core` `Data` `Input` `Player` `Stages` `UI`.
- 클래스는 Unreal 표준 접두사 + 프로젝트 접두사 `CK` (예: `ACKBoltCharacter`, `UCKHealthComponent`, `FCKAbilityDefinition`).
- Markdown 문서는 `Docs/`에만 둡니다. `Source/`나 `Content/`에 `.md`를 두지 않습니다.

## 슬래시 커맨드

| 커맨드 | 기능 |
| --- | --- |
| `/온보딩` | 모든 프로젝트 문서를 순서대로 읽어 컨텍스트 로드 |
| `/깃메시지` | 변경사항을 분석해 Git_Convention 형식 커밋 메시지 추천 |
| `/개발로그` | 이번 세션 작업을 Development_Log.md에 기록 |
| `/컨벤션점검` | 코드를 프로젝트 컨벤션 기준으로 점검하고 위반 보고 |

## 커밋

커밋은 개발자 단독 작성으로 기록합니다. 커밋 메시지에 `Co-Authored-By` 등 AI 공동 작성자·생성 표기를 넣지 않습니다. 자세한 규칙은 `Docs/02_Architecture/Git_Convention.md`를 따릅니다.
