#사용자로 부터 입력된 숫자의 구분된 숫자의 총합을 구하라

#사용자는 65,45,2,3,45,8 을 입력했다고 가정

num = "65,45,2,3,45,8"

#my code

num_list = num.split(",")
sum = 0
for i in num_list:
    sum += int(i)

print(sum)