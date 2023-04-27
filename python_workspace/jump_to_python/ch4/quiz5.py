#quiz5
#"life is too short 출략 txt"

f1 = open("text.txt", 'w')
f1.write("life is too short")
f1.close()

f2 = open("text.txt", 'r')
print(f2.read())
f2.close()