
def input_wage():
    wage = int(input("임금을 입력해주세요.(단위 : 만원) : "))
    if(type(wage) == int and wage >= 0):
        annual = wage*12
        if(annual < 10000):
            print("세전 연봉 : %d만원" %(annual))
            return annual
        else:
            print("세후 연봉 : %d억 %d만원" %(annual//10000,annual%10000))
            return annual
    else:
        print("입력값이 잘못되었습니다.")
        return input_wage()

def print_wage(wage):
    if(wage < 10000):
        print("세후 연봉 : %d만원" %wage)
    else:
        print("세후 연봉 : %d억 %d만원" %(wage//10000,wage%10000))

def tax(annual):
    tax_rate = [0.58,0.6,0.62,0.65,0.76,0.85,0.94]
    cutline = [50,30,15,8.8,4.6,1.2,0]
    normal = annual/1000
    for count in range(0, len(cutline)):
        if(normal > cutline[count]):
            return annual * tax_rate[count]

wage = input_wage()
after_tax = tax(wage)
print_wage(after_tax)

