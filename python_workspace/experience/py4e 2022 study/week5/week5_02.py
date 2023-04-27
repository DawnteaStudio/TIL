
def grader(submit,answer):

    #이름과 점수를 매개변수로 받으므로 딕셔너리가 적합하다고 생각
    dic = {}

    #랭킹은 1등부터 시작함
    rank = 1

    #동점자 count용 변수 초기화
    equal_count = 0

    #제출한 학생을 새로 받을 때마다 점수와 count 초기화
    for stu in submit:
        score = 0
        count = 0

        #리스트의 요소를 보면 ,로 이름과 점수가 구분되어 있음
        name = stu.split(',')[0]
        check = stu.split(',')[1]

        #문자열을 돌면서 답안지와 동일하면 점수 10점추가 
        for right in check:
            if int(right) == answer[count]:
                score += 10
            count += 1

        #최종 점수를 딕셔너리에 key는 이름 value는 점수로 추가함.
        dic[name] = score

    #value값을 기준으로 내림차순 정렬, key값을 기준으로 sort가 작동하므로 람다함수를 통해 value값을 임시로 key값으로 변환하여 정렬함
    sort_dic = sorted(dic.items(), key=lambda x:x[1], reverse=True)
    
    #정렬된 리스트의 요소중(튜플로 저장됨) 0번째는 key, 1번째는 value임
    for sort_result in sort_dic:
        print("학생:",sort_result[0],"점수:",sort_result[1],"%d등" %rank)

        #if문은 마지막에 list의 인덱스를 넘어버리므로 예외처리안에서 작성함
        try:

            #현재 요소의 점수가 다음 요소 보다 클 경우에만 rank에 1추가 + (밀린 랭킹만큼 추가)
            if sort_result[1] > sort_dic[sort_dic.index(sort_result)+1][1]:
                rank += (1+equal_count)

                #랭킹이 변화하였으면 동점자로 밀린 랭킹 0으로 초기화
                equal_count = 0

            else:
                #동점이 발생하면 랭킹은 변화하지 않고 랭킹을 1만큼 뒤로 밀음
                equal_count += 1
        
        except:
            break




# 학생 답 : 동점자를 고의로 생성함 (이을의 동생 끊을은 이을과 동일한 답을 제출했다고 가정)
s = ["김갑,3242524215",
"이을,3242524223",
"끊을,3242524223",
"박병,2242554131",
"최정,4245242315",
"정무,3242524315"]

# 정답지
a = [3,2,4,2,5,2,4,3,1,2]

grader(s, a)
