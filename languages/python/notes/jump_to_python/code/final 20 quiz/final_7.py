#사용자로부터 2~9를 입력받고 해당 숫자의 구단 출력

num = int(input("2 ~ 9 입력 : "))

for i in range(1,10):
    print(num * i, end = " ")