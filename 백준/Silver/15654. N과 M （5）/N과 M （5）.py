'''
입력: n, m / n개의 수
출력: 수열 하나씩 한 줄에 출력
'''
import sys
from itertools import permutations

n, m = map(int, sys.stdin.readline().split())

num = list(map(int, sys.stdin.readline().split()))
num.sort()
comb = list(permutations(num, m))

for i in comb:
    for j in i:
        print(j, end=' ')
    print()