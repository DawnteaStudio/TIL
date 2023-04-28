def input_name():
    name = input("이름을 입력해주세요. : ")
    try:
        int(name)
        print("이름을 정확히 입력해주세요.")
        return input_name()
    except:
        return name

def input_score():
    try:
        score = int(input("점수를 입력해주세요. : "))
        return score
    except:
        print("점수를 정확히 입력해주세요.")
        return input_score()

def return_grade(score):
    grade_list = ['F','A+','A','B+','B','C+','C','D+','D']
    for count in range(1,len(grade_list)):
        if(score >= 100 - 5*count):
            return grade_list[count]
    return 'F'

def print_info(name,score,grade):
    print("학생이름 : " + name)
    print("점수 %d점" %score)
    print("학점 : " + grade)

name = input_name()
score = input_score()
grade = return_grade(score)
print_info(name,score,grade)