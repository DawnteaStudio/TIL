#quiz5
#A학급의 평균 점수를 구해 보자.

A = [70, 60, 55, 75, 95, 90, 80, 80, 85, 100]
total = 0
for score in A:
    total += score
average = total/len(A)
print(average)
