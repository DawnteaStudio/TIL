def find_primes(n,m):
    numbers = [ i for i in range(n,m+1)]
    count = 0
    for num in numbers:
        is_prime = True
        if num == 1:
            continue
        elif num == 2:
            count += 1
            continue
        for j in range(2, num):
            if num%j == 0:
                is_prime = False
                break
        if is_prime == True:
            count += 1
    print("소수개수 %d" %count)

n = int(input("첫 번째 수 입력 : "))
m = int(input("두 번째 수 입력 : "))
find_primes(n, m)