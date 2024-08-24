'''
입력: 세로 n, 가로 m / 0 - 갈 수 없음, 1 - 갈 수 있음, 2 - 목표지점
출력: 각 지점에서 목표지점까지의 거리
    - 입력 모양 그대로 받는 인접행렬 하나, 거리 행렬 하나
    - 0 빼고 나머지는 -1로 초기화해놓고 추가해나감
'''
from collections import deque

reach = list() # 갈 수 있는지 없는지
distance = list() # 목표 지점으로부터 거리
visit = list() # 방문 여부

n, m = map(int, input().split())

start_y = 0
start_x = 0

for i in range(n):
    reach.append(list(map(int, input().split())))
    if 2 in reach[i]:
        start_y = i
        start_x = reach[i].index(2) # 여기서 출발
    distance.append([0 for tmp in range(m)])
    visit.append([0 for tmp in range(m)])

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

queue = deque([(start_y, start_x)])

while queue:
    now_y, now_x= queue.popleft()

    for now in range(4):
        new_y = now_y + dy[now]
        new_x = now_x + dx[now]
        if 0<= new_y < n and 0<= new_x < m and reach[new_y][new_x] == 1 and not visit[new_y][new_x]:
            queue.append((new_y, new_x))
            visit[new_y][new_x] = 1
            distance[new_y][new_x] = distance[now_y][now_x] + 1


for i in range(n):
    for j in range(m):
        if visit[i][j] == 0 and reach[i][j] == 1:
            print(-1, end = ' ')
            continue
        print(distance[i][j], end=' ')
    print()