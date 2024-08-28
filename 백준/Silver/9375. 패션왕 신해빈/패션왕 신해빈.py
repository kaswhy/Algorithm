import sys


def calculate_combinations(clothes):
    type_count = {}
    for _, type in clothes:
        type_count[type] = type_count.get(type, 0) + 1

    result = 1
    for count in type_count.values():
        result *= (count + 1)

    return result - 1


t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    clothes = [sys.stdin.readline().split() for _ in range(n)]
    print(calculate_combinations(clothes))