#quiz7
#text 파일의
#Life is too short
#you need java
#에서 java를 python으로 바꾸어 저장하라
f = open('text3.txt', 'r')
body = f.read()
f.close()

body = body.replace("java", "python")

f = open('text3.txt', 'w')
f.write(body)
f.close