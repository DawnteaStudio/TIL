def make_txt_file(line):
    file = open("lines.txt",'w') #txt파일로 저장
    file.write(line)#매개변수로 복붙한 텍스트 저장
    file.close()

def count_word(line, keyword):
    make_txt_file(line)
    print(line.count(keyword))#찾고 싶은 keyword 매개변수로 받고 텍스트에서 키워드 갯수 찾는 메소드 실행

a = "안녕하세요.\n반갑습니다.\n파이썬 공부는 정말 재밌습니다."
count_word(a,"습니다")