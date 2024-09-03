'''
입력: n, m
출력: 1부터 n까지 자연 수 중 m 개를 고른 수열
'''
import sys
from itertools import combinations_with_replacement

n, m = map(int, sys.stdin.readline().split())

nums = [ i for i in range(1, n+1)]

combs = list(combinations_with_replacement(nums, m))
for i in combs:
    for j in i:
        print(j, end= ' ')
    print()