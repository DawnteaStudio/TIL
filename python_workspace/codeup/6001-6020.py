# codeup >> https://codeup.kr/problemsetsol.php?psid=33
# 6001
print("Hello")
# 6002
print("Hello World")
# 6003
print("Hello\nWorld")
# 6004
print("'Hello'")
# 6005
print('"Hello World"')
# 6006
print("\"!@#$%^&*()\'")
# 6007
print('"C:\\Download\\\'hello\'.py"')
# 6008
print("print(\"Hello\\nWorld\")")
# 6009
a = input("")
print(a)
# 6010
a = input()
print(int(a))
# 6011
a = input()
print(float(a))
# 6012
# input(int())라고 실수함 input 범위설정은 input 밖에서 지정해주기.
a = int(input())
b = int(input())
print(a)
print(b)
# 6013
a = (input())
b = (input())
print(b)
print(a)
# 6014
a = float(input())
print(a)
print(a)
print(a)
# 6015 
# a, b = input().split() 이 코드를 아예 몰랐음... input이 2개 이상의 값이 저장되는 지 몰랐고 split으로 쪼갤 수 있는 지도 몰랐음
a, b = input().split()
print(a)
print(b)
# 6016
a, b = input().split()
print(b,a)
# 6017
a = str(input())
print((a + " ")*3)
# 6018
# sep 함수는 구분자로써 공백대신에 원하는 것을 넣어 줄 수 있다...첫문단이 내풀이 둘째문단이 내가 몰랐던 풀이..그리고 sep나 end를 사용할 때 , 로 변수와 구분 지어줘야함을 기억하자. sep= 로 =도 붙여줘야한다.
a = input().split(":")
print(a[0] + ":" + a[1])

a, b = input().split(':')
print(a, b, sep=':')
# 6019
a, b, c = input().split('.')
print(c, b, a, sep='-')
# 6020
a, b = input().split('-')
print(a,b, sep=(''))
