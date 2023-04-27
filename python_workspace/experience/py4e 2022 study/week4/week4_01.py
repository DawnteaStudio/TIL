def make_comma(num):
    num = str(num) #num을 문자형으로 변경
    i = -3 #첫번째 comma가 찍힐 위치

    while abs(i) < len(num): #i는 뒤에서 부터 문자열을 새는 값이므로 절대값이 문자열의 길이보다 작아야함

        num = num[:i] + ',' + num[i:]#첫번째 위치에 comma + 문자열 둘로 가르고 , 삽입후 다시 문자열에 할당

        comma_count = 1 #comma가 찍혔기 때문에 문자열의 길이가 1만큼 늘어남
        
        i -= (3 + comma_count) #1000단위 마다 찍히므로 -3에 comma가 찍혀서 1 늘어난 만큼을 i에서 빼줌

    print(num)

make_comma(int(input("숫자입력 : ")))
