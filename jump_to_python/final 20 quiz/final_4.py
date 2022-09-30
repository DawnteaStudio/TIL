#리스트에서 50이상의 총합을 구하시오
A = [20,55,67,82,45,33,90,87,100,25]

#my code
sum = 0
for i in A:
    if i >= 50:
        sum += i

print(sum)