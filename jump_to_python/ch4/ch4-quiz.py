# # quiz1
# result = 0
# i = 1
# while i <= 1000:
#     if i % 3 == 0:
#         result += i
#     i += 1
# print(result)

# # quiz2

# star = 1
# while star < 6:
#     print("*"*star)
#     star += 1

# # quiz3
# for i in range(1,101):
#     print(i)

# quiz4
score = [70,60,55,75,95,90,80,80,85,100]
sum = 0
for i in score:
    sum += i
print("Mean Value is" , sum/len(score))
pp = sum/len(score)
print("Mean Value is %f" % pp)

# quiz5 basic
numbers = [1,2,3,4,5]
result = []
for i in numbers:
    if i % 2 != 0:
        result.append(i*2)
print(result)

# quiz5 list comprehension
numbers = [1,2,3,4,5]
result = [i*2 for i in numbers if i%2 != 0]
print(result)