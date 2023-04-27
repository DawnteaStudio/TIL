import random

def start():
    rsp = input("가위바위보를 선택하세요.")
    if(rsp == "가위") :
        return 0
    elif(rsp == "바위") :
        return 1
    elif(rsp == "보") :
        return 2
    else:
        print("잘못된 입력입니다.")
        return start()

def game(com,i):
    rsp_list = ["가위","바위","보"]
    com_rsp = rsp_list[com]
    my_rsp = rsp_list[i]
    print("나:",my_rsp)
    print("컴퓨터:",com_rsp)
    if(i == com):
        print("비겼습니다.")
    elif(i > com):
        if(i - com == 1):
            print("나의 승리!")
        else:
            print("컴퓨터 승리!")
    else:
        if(com - i == 2):
            print("나의 승리!")
        else:
            print("컴퓨터 승리!")

rsp = start()
computer = random.randint(0, 2)
game(computer,rsp)


