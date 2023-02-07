# 230124
- git_study_project 리포지토리 생성

- aoiiroa@gmail.com 리포지토리 초대

# 230126
- arduino 폴더 및 파일 생성
(for window)
- 4wd_car_part_1.ino, 4wd_car_part_2.ino 생성

# 230127

- 4wd_car_part_3.ino, 4wd_car_part_Fin.ino 생성

# 230130

- 연습용 파이썬 파일 생성
    - 230130_py.py

- git reset --soft HEAD^    (최근 커밋 하기전으로 돌림)
- git reset --hard HEAD^    (최근 커밋과 스테이징 파일변경 등을 수정하기전으로 돌림(변경이 불가하다))
- git reset HEAD~1          (커밋 실행 취소 (수량~1,2,3...))
- git log                   (log 보기)
- git log --oneline         (log 한줄로 간략히 보기)

# 230131

- 4wd_test\test\test.ino 수정
    - fineAdjustmentAngle_2() 추가
        - 미세조정2 추가 
            - 각도가 90 이상이면 각도값이 0.5씩 증가
    
    - booster() 추가
        - 순간적으로 가속을 하는 항목

## 230201

- test.ino 내의 back, left, setup, 값 수정
    - back, left 의 (ENB, carSpeed)를 (ENB, 160)으로 수정
    - setup의 myservo.attach(3)를 myservo.attach(3,4)로 수정
- 뷰티파이 질문하기

## 230202

- 뷰티파이 설치
    - 단 파이썬에서 잘못 쓰면 오류날수 있다

## 230207

- conflicts 해결과 cherry-pick 연습
    - main_light.ino 수정

        * git conflict 발생시

            - git checkout main
                - main 브렌치로 이동
            - git pull main
                - main의 최신화
            - git checkout '충돌브렌치이름'
                - 충돌 브렌치로 이동
            - git merge main
                - main 과 merge하기
                - 충돌한 부분을 알려준다
            - 충돌한 파일 수정
            - git add, commit, push, pull request 진행
            - main, master 가 변경되면 다시 충돌이 일어날수 있다.

        - conflict 는 먼저 알맞는 부모 브렌치를 풀 하고 작업을 시작하면 안생기나, 혹여 발생시 틀린 부분을 알맞게 수정하주고 다시 커밋한다

        * cherry-pick은 풀해온 브렌치에 여러개의 커밋이 있을떄 특정 부분의 커밋만 가져올 경우 사용한다
            - git cherry-pick [커밋해시]
                - 커밋 뒤에 해시부분을 복사해서 넣으면 된다.
                - ex) [git cherry-pick c886c1054eb2c32b02cc64a6bda26821af685f39]
- git 명령어

    - git fetch origin
        - git 패치하기 : 변동사항 있는지 확인
    - git pull origin 'branch name'
        - 브랜치명의 내용 가져오기 
    - git stash
        - 임시저장
    - git stash pop
        - 임시저장 가져오기
    - git stash save "name"
        - 이름 붙여서 임시저장
    - git stash list
        - 임시저장 목록확인
    - git stash apply stash@{0}
        - 이름붙인 임시저장 가져오기
