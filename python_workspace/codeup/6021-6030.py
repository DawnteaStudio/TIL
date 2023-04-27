# 6021
a = input()
for i in range(0,5):
    print(a[i])
# 6022
# for range에서 range의 루프가 몇씩 증가할지 정할 수 있음을 기억하자.!!! 제발 좀...
a = input()
for i in range(0,6,2):
    print(a[i:i+2], end=" ")
# 6023
a = input().split(":")
print(a[1])
# 6024
# 문자열 a,b 로 출력하면 공백이 생기지만 a+b로 출력하면 공백이 없다!!!
a,b = input().split(" ")
print(a,end = "")
print(b)
print(a+b)
# 6025
# .split은 문자열 함수 인것을 기억하자!!
a,b = input().split()
a = int(a)
b = int(b)
print(a+b)
# 6026
a = input()
b = input()
c = float(a)+float(b)
print(c)
# 6027
# 포매팅은 ""나 ''안에 있어야 한다...
a = int(input())
print('%x' % a)
# 6028
a = int(input())
b = ('%x' % a).upper()
# b = ('%X' % a).upper() x를 대문자인 X로 하면 자동으로 대문자로 출력한다..
print(b)
# 6029
# int에서 , 를 통해 몇 진수로 저장할지 정할 수 있다.
a = input()
n = int(a, 16)
print('%o' % n)
# 6030
# ord 함수는 문자의 유니코드 값을 돌려주는 함수이다..
a = ord(input())
print(a)

# 모르는 내장함수들이 너무 많아서 책을 다 끝낸 뒤 다시 풀을 예정