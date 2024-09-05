"""
입력: 정점 개수 V, 간선 개수 E / 시작 정점 K / u에서 v로 가는 가중치 w인 간선
출력: i번째 줄에 i번 정점으로의 최단 경로값
    [조건]
    - 모든 정점에는 1 ~ V 까지 번호가 매겨져 있음
    - 1 <= V <= 20,000
    - 1 <= E <= 300,000
    => 인접 리스트로 dfs 구현하자
"""
import sys
import heapq

v, e = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

graph = [[] for _ in range(v + 1)]

for _ in range(e):
    u, x, w = map(int, sys.stdin.readline().split())
    graph[u].append((x, w))

dp = [sys.maxsize] * (v + 1)
dp[k] = 0  # 시작 정점의 최단 경로는 0
pq = [(0, k)]  # (거리, 정점)

while pq:
    current_dist, now = heapq.heappop(pq)

    if dp[now] < current_dist:
        continue

    for adj, weight in graph[now]:
        distance = current_dist + weight

        if distance < dp[adj]:
            dp[adj] = distance
            heapq.heappush(pq, (distance, adj))

for i in range(1, v + 1):
    if dp[i] == sys.maxsize:
        print("INF")
    else:
        print(dp[i])
