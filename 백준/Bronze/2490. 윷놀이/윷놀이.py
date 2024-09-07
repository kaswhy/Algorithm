import sys

for i in range(3):
    a, b, c, d = map(int, sys.stdin.readline().split())

    cnt = a+b+c+d
    if cnt == 4:
        print("E")
        continue
    if cnt == 0:
        print("D")
        continue
    if cnt == 3:
        print("A")
        continue
    if cnt == 2:
        print("B")
        continue
    if cnt == 1:
        print("C")
    