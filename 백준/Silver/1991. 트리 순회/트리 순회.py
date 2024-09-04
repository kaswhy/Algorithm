'''
입력: 노드 N / 노드, 왼쪽, 오른쪽
출력: 전위 순회 결과 / 중위 순회 결과 / 후위 순회 결과
    [조건]
    - 항상 A가 루트 노드
    - 노드 이름은 A부터 차례대로
    - 자식이 없으면 .으로 표현

    인접 리스트로 구현
    - 각 행은 해당 노드
    - 0) 왼쪽, 1) 오른쪽
        -> 해당 알파벳에 -ord('A) 한걸로 저장, 음수면 자식 없음
'''
import sys

n = int(sys.stdin.readline()) # 노드 개수 입력 받기

nums = [ [-1, -1] for i in range(n) ]
for i in range(n): # 노드 정보 입력 받기
    a, b, c = map(ord, sys.stdin.readline().split())
    a -= ord('A')
    b -= ord('A')
    c -= ord('A')
    nums[a][0] = b
    nums[a][1] = c

pre_visit = [ False for i in range(n) ]
in_visit = [ False for i in range(n) ]
post_visit = [ False for i in range(n) ]

def preorder(now):
    pre_visit[now] = True
    print(chr(now+ord('A')), end='')

    left = nums[now][0]
    right = nums[now][1]

    if left > 0:
        if pre_visit[left] == False:
            preorder(left)
    if right > 0:
        if pre_visit[right] == False:
            preorder(right)

def inorder(now):
    left = nums[now][0]
    right = nums[now][1]

    if left > 0:
        if in_visit[left] == False:
            in_visit[left] = True
            inorder(left)

    in_visit[now] = True
    print(chr(now + ord('A')), end='')

    if right > 0:
        if in_visit[right] == False:
            in_visit[right] = True
            inorder(right)


def postorder(now):
    left = nums[now][0]
    right = nums[now][1]

    if left > 0:
        if post_visit[left] == False:
            post_visit[left] = True
            postorder(left)

    if right > 0:
        if post_visit[right] == False:
            post_visit[right] = True
            postorder(right)


    post_visit[now] = True
    print(chr(now + ord('A')), end='')

preorder(0)
print()
inorder(0)
print()
postorder(0)