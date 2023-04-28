def make_guest_file(book):#txt파일로 저장하는 함수, 설명 생략
    book_txt = open("guest_book.txt", 'w')
    book_txt.write(book)
    book_txt.close()

def wrong_guest_book(book):
    make_guest_file(book)#txt파일로 저장하는 함수 호출

    file = open("guest_book.txt", 'r')#txt파일의 내용을 한줄씩 읽고
    while True:
        line = (file.readline()).strip()#개행문자 및 공백 제거
        if not line:#더이상 읽을 줄이 없으면 반복문 종료
            break
        
        line = line.split(',')#라인을 ,로 분리 0번째 인덱스는 이름, 1번째 인덱스는 번호
        name = line[0]
        number = line[1]

        if number[:3] != "010" or len(number) != 13 or (number[3] and number[8]) != '-':
        #문제에서 제시한 조건 3가지 if와 or로 구현

            print("잘못 쓴 사람: ",name)
            print("잘못 쓴 번호:",number)
            print()

        else:
            is_number = number.split('-')
        #문제에서 제시한 조건3가지가 만족하더라도 번호가 숫자여야하는 조건을 추가하기 위한 else문

            for i in is_number: 
                try:
                    int(i) #'-'로 문자열을 쪼갠 후 각각의 요소가 int로 형변환 가능한지 확인

                except: #int로 형변환이 안되면 자연수가 아니므로 except으로 잘못 작성된 방명록임을 확인
                    print("잘못 쓴 사람: ",name)
                    print("잘못 쓴 번호:",number)
                    print()
                    break #단 한번이라도 int형변환이 안되는 순간 잘못 된것을 알 수 있기 때문에 for문 break


guest_book = """김갑,123456789
이을,010-1234-5678
박병,010-5678-111
최정,111-1111-1111
정무,010-3333-3333
로봇,010-abcd-efgh"""
wrong_guest_book(guest_book)