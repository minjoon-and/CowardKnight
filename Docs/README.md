# CowardKnight 문서

이 폴더는 사람 개발자와 Claude(및 다른 LLM 에이전트)가 함께 참고하는 프로젝트 기억 저장소입니다.

코드나 에셋을 수정하기 전에 아래 문서를 읽습니다.

## 읽는 순서

작업 시작 시 프로젝트 루트의 `CLAUDE.md`가 먼저 로드됩니다. 그다음 아래 문서를 순서대로 읽습니다.

1. `00_Project/Project_Principles.md`
2. `01_Planning/Game_Design_Brief.md`
3. `02_Architecture/Development_Rules.md`
4. `02_Architecture/Folder_Conventions.md`
5. `02_Architecture/Coding_Convention.md`
6. `02_Architecture/Git_Convention.md`
7. `03_Unreal/Unreal_Standards.md`
8. `04_Logs/Development_Log.md`
9. `05_References/Reference_Index.md`

전체 문서를 한 번에 로드하려면 `/온보딩` 슬래시 커맨드를 사용합니다.

## 슬래시 커맨드

`.claude/commands/`에 프로젝트 전용 커맨드가 정의되어 있습니다.

- `/온보딩` — 모든 문서를 순서대로 읽어 컨텍스트 로드
- `/세션이어가기` — 직전 세션 인계 노트(`04_Logs/Session_Handoff.md`)를 읽고 다음 작업 추천
- `/깃메시지` — 변경사항 분석 후 `02_Architecture/Git_Convention.md` 형식으로 커밋 메시지 추천
- `/개발로그` — 이번 세션 작업을 `04_Logs/Development_Log.md`에 기록
- `/세션마감` — 이번 세션의 작업·결정·다음 시작점을 `04_Logs/Session_Handoff.md`에 인계 노트로 저장
- `/컨벤션점검` — 코드를 프로젝트 컨벤션 기준으로 점검

`/개발로그`와 `/세션마감`의 차이:
- `/개발로그` — 사용자가 정리한 **공식 결정·회고** 기록 (사람이 보고 검토).
- `/세션마감` — 다음 세션의 Claude가 컨텍스트를 회복할 수 있도록 남기는 **자동 인계 노트**.

커밋 메시지 추천 요청을 받으면 `/깃메시지` 커맨드 또는 `02_Architecture/Git_Convention.md`를 기준으로 답변합니다.

## 규칙

Markdown 문서는 이 `Docs/` 폴더에 모읍니다.

소스 코드, Unreal 에셋, 임시 구현 파일은 이 폴더에 두지 않습니다.

규칙이 바뀌면 해당 문서를 수정하고 `04_Logs/Development_Log.md`에 기록합니다.
