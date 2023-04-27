def input_method():
    method = input("결재수단을 입력해주세요.(현금 or 카드) : ")
    if(method == "현금" or method == "카드"):
        return method
    else:
        print("정확한 결재수단을 입력해주세요.(현금 or 카드).")
        return input_method()

def input_age():
    try:
        age = int(input("나이를 입력해주세요.(숫자만) : "))
        return age
    except:
        print("나이를 정확히 입력해주세요.")
        return input_age()

def return_fare(age,method):
    age_table = [8,14,20,75]
    card = [0,450,720,1200]
    cash = [0,450,1000,1300]
    for count in range(0,len(age_table)):
        if(age < age_table[count]):
            if(method == "현금"):
                return cash[count]
            else:
                return card[count]
    return 0

def print_info(age,method,fare):
    print("\n출력결과")
    print("나이 :  %d세" %age)
    print("지불유형 :  %s" %method)
    print("버스요금 :  %d원" %fare)

age = input_age()
method = input_method()
fare = return_fare(age,method)

print_info(age,method,fare)