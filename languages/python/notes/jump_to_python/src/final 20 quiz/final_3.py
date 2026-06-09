#리스트를 더할 때 '+'와 extend 함수의 차이는?

a = [1,2,3]
print("a의 주소값 : ",id(a))
a = a + [4,5]
print(a)
print("+ 사용 : ",id(a))

a = [1,2,3]
print("a의 주소값 : ",id(a))
a.extend([4,5])
print(a)
print("extend 사용 : ",id(a))

# + 는 id가 변하고, extend는 id가 유지