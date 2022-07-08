# quiz1
kor = 80
eng = 75
math = 55

sum = kor + eng + math
q1 = sum/3
print(f"1번 답은 : {q1}")

# quiz2
q2 = 13
if q2//2 == 1:
    print("13은 짝수입니다.")
else:
    print("13은 홀수입니다.")

# quiz3
pin = "881120-1068234"

yyyymmdd = print("yyyymmdd = " + pin.split("-")[0])
num = print("num = " + pin.split("-")[1])

# quiz4
print(pin.split("-")[1][0])

# quiz5
a = "a:b:c:d"
b = a.replace(":","#")
print(b)

# quiz6
a = [1,3,5,4,2]
a.sort()
a.reverse()
print(a)

# quiz7
a = ['life',"is","too","short"]
a = " ".join(a)
print(a)

# quiz8
a = (1,2,3)
a = a + (4,)
print(a)

# quiz9
# 딕셔너리 key값에는 바뀌지 않는 값이 와야하므로 숫자,문자열,튜플은 올 수 있지만 리스트는 올 수 없다.

# quiz10
a = {"A":90, "B":80, "C":70}
result = a.pop("B")
print(result)

# quiz11
a = [1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5]
aSet = set(a)
b = list(aSet)
print(b)

# quiz12
a = b = [1,2,3]
a[1] = 4
print(b)
# b값이 바뀌는 이유는 a와 b가 62번쨰 줄에서 동일한 id로 설정되었기 때문에 a값이 변하면 a가 지정하고 있는 id의 정보가 바뀌기 때문에
# b또한 값이 바뀐다.