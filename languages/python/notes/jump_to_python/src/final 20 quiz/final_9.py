#평균값 구하기
f = open('sample.txt')
lines = f.readlines()
f.close()

total = 0

for line in lines:
    score = int(line)
    total += score

average = total /len(lines)
print(average)