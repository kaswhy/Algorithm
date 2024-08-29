'''
입력: 수열 크기 N (<=1000) / 수열 정보
출력: 수열 A의 가장 긴 증가하는 부분 수열의 길이

    -> 파이썬 1초 = 약 2000만 -> 반복문 2만까지 가능
    쭉 돌면서 max 값이 갱신되는 횟수를 배열에 하나씩 넣고
'''
import sys

n = int(sys.stdin.readline())
num = list(map(int, sys.stdin.readline().split()))

cnt = [1 for i in range(n)]
for i in range(1, n): # 시작 위치
    for j in range(i):
        if num[i] > num[j]:
            cnt[i] = max(cnt[i], cnt[j] + 1)

print(max(cnt))