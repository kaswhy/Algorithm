'''
입력: 가로 M, 세로 N / 1(익음), 0(안 익음), -1(없음)
출력: 토마토가 모두 익을 때까지의 최소 날짜 / 이미 익어있으면 0, 모두 익지 못하면 -1
bfs 사용 -> max 값
'''
from collections import deque

m, n = map(int, input().split())
reach = [[0 for i in range(m)] for j in range(n)] # 갈 수 있는지 없는지
queue = deque()

for i in range(n):
    tmp = list(map(int, input().split()))
    for j in range(m):
        reach[i][j] = tmp[j]
        if reach[i][j] == 1: queue.append((i, j))

direction = [(-1, 0), (0, 1), (1, 0), (0, -1)]

while queue:
    now_y, now_x = queue.popleft()

    for new_y, new_x in direction:
        ny = now_y + new_y
        nx = now_x + new_x
        if 0 <= ny < n and 0 <= nx < m and reach[ny][nx] == 0:
            queue.append((ny, nx))
            reach[ny][nx] = reach[now_y][now_x] + 1
ans = 0
for i in reach:
    for j in i:
        if j == 0:
            print(-1)
            exit(0)
    ans = max(ans, max(i))

print(ans - 1)