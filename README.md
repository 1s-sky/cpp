# c++
C++강의 과제

-------------------------------------
## HW9 
로봇 일시키기 프로그램

<기능>
>1. 구입할 로봇의 대수를 입력 받아 로봇 대수만큼 객체 생성
>2. 구입한 로봇의 대수만큼 숱파적으로 로봇의 이름과 초기 에너지량을 입력 받아 초기화 한 후 일을 시킨다.

<할 수 있는 일>
```
go() : 전진 메세지 출력 후 에너지 10 감소
back() : 후진 메세지 출력 후 에너지 20 감소
turn() : 턴 메세지 출력 후 에너지 30 감소
jump() : 점프 메세지 출력 후 에너지 40 감소
charge(int e) : 에너지 e만큼 충전
```

## HW11
Fitness 회원관리 프로그램
>회원의 등록 가능한 회원수는 최대 100명으로 제한

<메뉴>
```
1.회원 등록
2.회원 전체보기 : 한 줄에 한 명씩 회원정보 출력
3.회원 정보검색 : 회원명으로 검색하여 해당 이름인 사람 모두 출력
4.회원 탈퇴 : 회원 정보에 해당하는 회원 객체 삭제
5.특별관리 회원 : bmi를 검사하여 고도비만, 비만, 과체중에 해당하는 회원정보 출력
6.종료
```
