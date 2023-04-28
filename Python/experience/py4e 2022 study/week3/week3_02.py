import random

def rsp_start():
    rsp = input("가위(0),바위(1),보(2)를 선택하세요.")
    if(rsp == "가위" or rsp == "0") :
        return 0
    elif(rsp == "바위" or rsp == "1") :
        return 1
    elif(rsp == "보" or rsp == "2") :
        return 2
    else:
        print("잘못된 입력입니다.")
        return rsp_start()

def rsp_game(com,i,count):
    rsp_list = ["가위","바위","보"]
    com_rsp = rsp_list[com]
    my_rsp = rsp_list[i]
    print("나:",my_rsp)
    print("컴퓨터:",com_rsp)
    if(i == com):
        print("%d번째 판 비겼습니다." %count)
        return 1
    elif(i > com):
        if(i - com == 1):
            print("%d번째 판 나의 승리!" %count)
            return 0
        else:
            print("%d번째 판 컴퓨터 승리!" %count)
            return 2
    else:
        if(com - i == 2):
            print("%d번째 판 나의 승리!" %count)
            return 0
        else:
            print("%d번째 판 컴퓨터 승리!" %count)
            return 2

def rsp_advanced(games):
    count = 0
    board = [0,0,0]
    while count < games:
        rsp = rsp_start()
        computer = random.randint(0, 2)
        print("%d번째 게임입니다." %(count+1))
        board[rsp_game(computer,rsp,count+1)] += 1
        print("")
        count += 1
    print("나의 전적 : %d승 %d무 %d패" %(board[0],board[1],board[2]))
    print("컴퓨터의 전적 : %d승 %d무 %d패" %(board[2],board[1],board[0]))


games = int(input("몇 판을 진행하시겠습니까? : "))
rsp_advanced(games)