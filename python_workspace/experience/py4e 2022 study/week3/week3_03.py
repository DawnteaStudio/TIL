def find_even_number(n,m):
    numbers = [ i for i in range(n,m+1)]
    for num in numbers:
        if num%2 == 0:
            if numbers.index(num) == int(len(numbers)/2) or numbers.index(num) == (len(numbers)/2)-1:
                print("%d 짝수 그리고 중앙값" %num)
                continue
            print("%d 짝수" %num)
        else:
            continue

n = int(input("첫 번째 수 입력 : "))
m = int(input("두 번째 수 입력 : "))
find_even_number(n, m)

