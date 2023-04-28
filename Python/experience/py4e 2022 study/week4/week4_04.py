def print_id(year,month,gender): #문자열 3개를 매개변수로 받아 각 요소를 출력하는 함수작성
    if gender == '1' or gender == '3':
        print("%s년%s월 남자" %(year,month))
    else:
        print("%s년%s월 여자" %(year,month))

def check_id(id):
    if id[6] == '-' and len(id) == 14:#기본 조건인 -로 구분이 되었는지와 길이가 14자리인지 확인
        date_of_birth = id.split('-')[0]#기본조건이 성립하면 앞부분은 생년월일, 뒷부분은 비밀번호로 구분
        secret_number = id.split('-')[1]

        try:#3번에서 한것과 동일하게 주민번호가 숫자로 이루어져있는지 확인
            int(date_of_birth)
            int(secret_number)
        except:
            print("잘못된 번호입니다.")
            print("올바른 번호를 넣어주세요.")
            exit()

        year = date_of_birth[:2]#생년월일과 성별에 해당하는 부분 문자열슬라이싱
        month = date_of_birth[2:4]
        gender = secret_number[0]


        if int(month) > 12 or int(month) < 1:#태어난 달은 1월 ~12월 사이
            print("잘못된 번호입니다.")
            print("올바른 번호를 넣어주세요.")

        elif int(year) >= 0 and int(year) <= 21: #2000년생~2021년생의 경우 3,4로 성별구분하는 것 조건문으로  적용
            new_gen = input("2000년 이후 출생자 입니까? 맞으면o 아니면 x:")
            if new_gen == 'o' and (gender == '3' or gender == '4'):
                print_id(year,month,gender) #print함수 호출
            elif new_gen == 'x' and (gender == '1' or gender == '2'):
                print_id(year,month,gender) #print함수 호출            
            else:
                print("잘못된 번호입니다.")
                print("올바른 번호를 넣어주세요.")

        elif int(gender) > 0 and int(gender) <5: #성별을 확인하는 숫자는 1,2,3,4 여야한다.
            print_id(year,month,gender) #print함수 호출
        else:
            print("잘못된 번호입니다.")
            print("올바른 번호를 넣어주세요.")            
            
    else:#기본조건 성립 안될 경우
        print("잘못된 번호입니다.")
        print("올바른 번호를 넣어주세요.")

id = input("주민번호 입력 :(구분은 -) ")
check_id(id)