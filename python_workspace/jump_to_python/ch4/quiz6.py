#quiz6
#사용자 입력을 저장하는 프로그램 작성

user_input = input("저장할 내용을 입력하세요:")
f = open('test2.txt', 'a')
f.write(user_input)
f.write('\n')
f.close()