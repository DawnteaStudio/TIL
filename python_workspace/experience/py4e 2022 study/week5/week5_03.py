import random

def guess_number():

    #정답의 리스트와 입력값 리스트 선언
    num_list = []
    input_list = []

    #시도 횟수 0으로 초기화, 값을 맞추면 해당 값의 value가 1로 변경될 예정
    ans_dict = {"최솟값":0,"중간값":0,"최댓값":0}
    keys = list(ans_dict.keys())
    count = 0
    
    while True:

        #0~100 랜덤 숫자 리스트에 추가
        num_list.append(random.randint(0, 100))

        #만약 리스트에 값을 넣었는데 중복이 생길경우 마지막에 넣은 값 삭제
        if len(num_list) != len(set(num_list)):
            num_list.pop()

        #중복이 없고 리스트에 숫자가 3개 들어가면 반복문 종료
        elif len(num_list) == 3:
            break
        
    #완성된 리스트 오름 차순    
    num_list.sort()

    while True:

        #반복문이 반복 될 때 마다 시도 횟수 1증가
        count += 1

        #숫자를 맞췄을 때 반복문 처음으로 돌리기 위한 변수
        correct = False


        while True:
            print("%d차 시도" %count)
            number = input("숫자를 예측해보세요(정답이 알고 싶으면 \"답\"을 입력) : ")

            #input값을 정수로 변환
            try:
                number = int(number)


            except:
                #정답 알고 싶을 때 경우의 수
                if number == "답":
                    print(num_list)
                    continue

                #그 외는 정수 입력 요구
                else:
                    print("정수를 입력해주세요.")
                    continue
            
            #숫자 범위 조건
            if number > 100 or number < 0:
                print("범위를 벗어났습니다.")
                continue
            
            #이미 사용한 숫자 조건
            elif number in input_list:
                print("이미 예측에 사용한 숫자입니다.")
                continue
            
            #조건을 만족하면 사용 여부 확인 리스트에 추가하고 입력 종료
            else:
                input_list.append(number)
                break

        for elem in num_list:

            #elem의 index값을 저장하는 변수 선언
            index_num = num_list.index(elem)

            #숫자를 맞추면 조건에 맞게 출력하고 해당 딕셔너리의 value값 1로 변경
            if number == elem:
                print("숫자를 맞추셨습니다! %d(은)는 %s입니다." %(number,keys[index_num]))
                ans_dict[keys[index_num]] = 1

                #맞췄다고 선언하고 for문 종료
                correct = True
                break
        
        #만약 딕셔너리 value가 전부 1이면 메인 반복문 종료
        if not 0 in ans_dict.values():
            break
        
        #만약에 숫자를 맞췄다면 밑의 조건문 실행하지 않도록 continue
        elif correct:
            continue
        
        #숫자의 크기를 통해 사용자에게 더 도움되는 힌트 제공
        if count%5 == 0:
            print("%d는 없습니다." %number)
            if number < num_list[0]:
                print("%d(은)는 최솟값보다 작습니다." %number)
            elif number < num_list[1]:
                print("%d(은)는 최솟값보다 크고 중간값보다 작습니다." %number)
            elif number < num_list[2]:
                print("%d(은)는 중간값보다 크고 최댓값보다 작습니다." %number)
            else:
                print("%d(은)는 최댓값보다 큽니다." %number)

        else:
            print("%d(은)는 없습니다." %number)
    
    #메인 반복문 
    print("게임 종료")
    print("%d번 시도만에 예측 성공" %count)


guess_number()


















