# quiz2
#1부토 1000의 자연수중 3의배수 합
result = 0
i = 1
while i <= 1000:
    if i % 3 == 0:
        result += i
    i += 1
print(result)