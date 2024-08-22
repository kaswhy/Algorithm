'''
입력: 수빈 위치  N, 동생 위치 K
출력: 동생을 찾는 가장 빠른 시간
동생 위치부터 시작해서 위치+1, -1, /2
세 가지 중 가장 작은 걸 지속적으로 선택
(1) 5부터 시작
0. 5 -> 0
1. 4-> 1, 6-> 1, 10->1
2. 3, 5, 8 / 5, 7, 12 / 9, 11, 20
3. 2, 4, 6/ 4, 6, 26 / 7, 9, 16 /

=> BFS 사용
'''
from collections import deque

a, b = map(int, input().split())
time_list = [0 for i in range(100001)]


def cnt_time():
    queue = deque([a])

    while queue:
        n = queue.popleft()
        if n == b:
            print(time_list[n])
            break
        for now in (n-1, n+1, n*2):
            if 0<= now <=100000:
                if not time_list[now]:
                    time_list[now] = time_list[n] + 1
                    queue.append(now)

cnt_time()