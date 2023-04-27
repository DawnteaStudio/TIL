def after_100(month,day,name):

    #기본 리스트 작성
    month_list = [1,2,3,4,5,6,7,8,9,10,11,12]
    day_list = [31,28,31,30,31,30,31,31,30,31,30,31]
    name_list = ["월","화","수","목","금","토","일"]
    
    #각 매개변수의 시작 인덱스값 할당
    start = month_list.index(month)
    start_day = name_list.index(name)

    #매개변수를 시작으로 하는 리스트로 수정
    month_list = month_list[start:] + month_list[:start]
    day_list = day_list[start:] + day_list[:start]
    name_list = name_list[start_day:] + name_list[:start_day]

    #입력받은 만큼 날 제거
    day_list[0] -= day
    count = 0

    #입력 받은 날 부터 시작
    day_count = day
    change_name = 0

    #오늘부터 1일이므로 99번 반복
    for i in range(1,100):
        
        #day는 1씩 증가하면서 list의 day값은 1씩 제거
        day_list[count] -= 1
        day_count += 1
        change_name += 1

        #날짜 다 제거하면 다음달로 이동 day_count 0으로 초기화
        if day_list[count] == 0:
            count += 1
            day_count = 0
        
        #요일이 한바퀴 끝나면 다시 처음으로 이동
        if name_list[-1] == name_list[change_name]:
            change_name = -1
    

    after_month = month_list[count]
    after_day = day_count
    after_name = name_list[change_name]

    print(f"{month}월 {day}일 {name}요일부터 100일 뒤는 {after_month}월 {after_day}일 {after_name}요일")            




after_100(6,21,"월")
