#주어진 문자열을 split과 join함수를 사용하여 a#b#c#d로 변경하라

line = "a:b:c:d"

line = line.split(":")
line = "#".join(line)
print(line)