import sys

a, b, c = map(int, sys.stdin.readline().split())

def mult(x, y, z):
    if y == 1:
        return x % z
    tmp = mult(x, y // 2, z)
    if y % 2 == 1:
        return ((tmp*tmp) % z) * x % z
    else: return (tmp*tmp) % z

print(mult(a, b, c))