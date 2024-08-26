'''
입력: 회의 수 N / 시작 시간, 끝나는 시간
출력: 최대 사용할 수 있는 회의의 개수
    현재 회의 시작 시간이 앞 회의 끝나는 시간보다 크면 count 1
'''

n = int(input())
que = []
max_time = 0

for i in range(n):
    start, end = map(int, input().split())
    que.append([end, start])

que.sort() # 오름차순으로 정렬

cnt = end = 0
for i in range(n):
    now = que[i][1]
    if now >= end:
        cnt += 1
        end = que[i][0]

print(cnt)