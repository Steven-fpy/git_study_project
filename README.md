### 230124
- git_study_project 리포지토리 생성

- aoiiroa@gmail.com 리포지토리 초대

### 230126
- arduino 폴더 및 파일 생성
(for window)
- 4wd_car_part_1.ino, 4wd_car_part_2.ino 생성

### 230127

- 4wd_car_part_3.ino, 4wd_car_part_Fin.ino 생성

### 230130

- 연습용 파이썬 파일 생성
    - 230130_py.py

- git reset --soft HEAD^    (최근 커밋 하기전으로 돌림)
- git reset --hard HEAD^    (최근 커밋과 스테이징 파일변경 등을 수정하기전으로 돌림(변경이 불가하다))
- git reset HEAD~1          (커밋 실행 취소 (수량~1,2,3...))
- git log                   (log 보기)
- git log --oneline         (log 한줄로 간략히 보기)

### 230131

- 4wd_test\test\test.ino 수정
    - fineAdjustmentAngle_2() 추가
        - 미세조정2 추가 
            - 각도가 90 이상이면 각도값이 0.5씩 증가
    
    - booster() 추가
        - 순간적으로 가속을 하는 항목

### 230201

- test.ino 내의 back, left, setup, 값 수정
    - back, left 의 (ENB, carSpeed)를 (ENB, 160)으로 수정
    - setup의 myservo.attach(3)를 myservo.attach(3,4)로 수정
- 뷰티파이 질문하기

### 230202

- 날짜 크기 변경
