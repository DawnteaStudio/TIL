def gugudan(number):
    print("%d단" %number)
    i = 1
    while True:
        result = i * number
        if result > 50:
            break
        print("%d X %d = %d" %(number,i,result))
        i += 2
number = int(input("몇 단? : "))
gugudan(number)