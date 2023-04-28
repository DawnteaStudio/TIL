import random 

def bs31():
    print("베스킨라빈스 써리원 게임")
    print("------------------")

    #게임이 끝나는 번호와 시작하는 번호 설정
    bs_number = 31
    number = 0

    #게임 종료 여부 확인하는 변수 초기화
    victory = False 

    #게임 승자가 나올때까지 반복
    while not victory : 
        my = input("My turn - 숫자를 입력하세요: ")

        #입력을 공백단위로 잘라 리스트로 저장
        my = my.split() 

        #입력된 요소들은 정수여야함
        try:
            my = [int(i) for i in my]
        except:
            print("잘못된 입력입니다. 다시 입력하세요.")
            continue

        #컴퓨터의 입력값 초기화
        computer_turn_num = random.randint(1,3)

        # 1~3개 사이의 숫자를 입력해야함
        if len(my) > 3 or len(my) < 1: 
            print("잘못된 입력입니다. 다시 입력하세요.")
            continue

        #마지막 숫자보다 1이 더 큰 숫자로 시작해야함
        elif my[0] != number+1: 
            print("잘못된 입력입니다. 다시 입력하세요.")
            continue

        #숫자는 1씩 커져야만 함, 리스트 내포를 사용하여 한줄로 확인
        elif [j for j in my if j != my[0]+my.index(j)]:
            print("잘못된 입력입니다. 다시 입력하세요.")
            continue

        
        else:
            #나의 패배인지 확인하는 반복문
            for num in my:
                if num == bs_number:
                    print("현재 숫자:31")
                    print("컴퓨터의 승리입니다!")

                    #게임의 승자가 나오면 victory는 참이 됨
                    victory = True
                    break
            
            #게임의 승자가 나왔으면 반복문을 빠져나옴
            if victory:
                continue

            #현재 숫자는 내가 부른 마지막 숫자임
            number = my[-1]
            print("현재 숫자:%d" %number)

            #숫자는 1씩 커져야 함
            for i in range(1, computer_turn_num+1):
                number += 1

                #컴퓨터의 숫자가 커지는 도중 31이 생기면 게임을 종료해야 함
                if number == bs_number:
                    print("컴퓨터:31")
                    victory = True
                    print("Player의 승리입니다!")
                    continue
                
                #게임이 종료되지 않는 한 컴퓨터가 호출한 숫자 반복 출력
                print("컴퓨터:%d" %number)
            
            #현재 숫자 출력
            print("현재 숫자:%d" %number)
bs31()