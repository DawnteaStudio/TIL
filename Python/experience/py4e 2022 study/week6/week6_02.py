def sales_management(name,records):
    dic = {}
    rec_avr = []
    buffer = ""
    buffer_rec = 0
    for i in range(len(name)):
        dic[name[i]] = records[i]

    for i in dic.keys():
        sum = 0
        for j in dic[i]:
            sum += j
        rec_avr.append(sum/len(dic[i]))


    for i in range(1,len(rec_avr)):
        for j in range(i-1,-1,-1):
            if rec_avr[j+1] > rec_avr[j]:
                buffer = name[j]
                buffer_rec = rec_avr[j]
                name[j] = name[j+1]
                name[j+1] = buffer
                rec_avr[j] = rec_avr[j+1]
                rec_avr[j+1] = buffer_rec
                    
            else:
                break

    if rec_avr[0] > 5:
        print("보너스 대상자 %s" %name[0])
        if rec_avr[1] > 5:
            print("보너스 대상자 %s" %name[1])

    print()

    if rec_avr[5] < 3 :
        print("면담 대상자 %s" %name[5])
        if rec_avr[4] < 3:
            print("면담 대상자 %s" %name[4])



# 이름, 실적
member_names = ["갑돌이", "갑순이", "을돌이", "을순이", "병돌이", "병순이"]
member_records = [[4,5,3,5,6,5,3,4,1,3,4,5],[2,3,4,3,1,2,0,3,2,5,7,2], 
        [1,3,0,3,3,4,5,6,7,2,2,1],[3,2,9,2,3,5,6,6,4,6,9,9],
        [8,7,7,5,6,7,5,8,8,6,10,9],[7,8,4,9,5,10,3,3,2,2,1,3]]

sales_management(member_names, member_records)