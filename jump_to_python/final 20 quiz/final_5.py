#첫항은 0이고 n번째 항까지의 피보나치 수열을 출력하는 함수를 작성하라

num1 = 0
num2 = 1
goal = int(input("n값 입력 : "))

for i in range(goal):

    if goal == 1:
        print(num1)
    elif goal == 2:
        print(num1, num2)
        break
    else:
        if i%2 == 0:
            print(num1, end = ' ')
            num1 += num2
        elif i%2 == 1:
            print(num2, end = ' ')
            num2 += num1
