'''
입력: 정점 개수 N, 간선 M, 시작 정점 V / 간선 정보
출력: DFS 수행 결과 / BFS 수행 결과
    인접리스트 방식 사용 하여 그래프 입력받기
    1. 1001개짜리 배열에 하나씩 추가하는 식으로 (40mb)
    2. visit -> 4kb
    3. visit -> 4kb
    4. queue ->


    DFS
    1. 현재 인덱스를 인자로 받음
    2. visit -> True, 출력
    3. 지금 인덱스랑 연결된 애들 방문 안 했으면 하나씩 재귀로

    BFS
    1. 큐에 현재 인덱스를 집어넣음
'''
import sys
from collections import deque

n, m, v = map(int, sys.stdin.readline().split())

graph = [ [] for i in range (n+1) ]
for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[x].sort()
    graph[y].append(x)
    graph[y].sort()

visit_dfs = [ False for i in range (n+1) ]
visit_bfs = [ False for i in range (n+1) ]

def dfs(now):
    visit_dfs[now] = True
    print(now, end=' ')

    for i in graph[now]:
        if visit_dfs[i] == False:
            dfs(i)

dfs(v)
print()

que = deque([v])

while que:
    x = que.popleft()
    if visit_bfs[x] == False:
        print(x, end =' ')
        visit_bfs[x] = True

    for i in graph[x]:
        if visit_bfs[i] == False:
            que.append(i)

print()