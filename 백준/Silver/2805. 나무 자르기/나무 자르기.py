'''
입력: 나무의 수 N, 집으로 가져가려고 하는 나무 길이 M
출력: 적어도 M미터의 나무를 집에 가져가기 위해 설정할 수 있는 높이 최댓값
binary search!
    1. mid len 구함
    2. ans = 0으로 해서 배열의 모든 값에서 min 뺀 거 더한 게 m인지 확인
    3. m이면 mid 리턴
    4. m보다 ans가 크면 mid 키우기
    5. m 보다 작으면 mid를 줄이기
'''
n, m = map(int, input().split())
tree_list = list(map(int, input().split()))

max_len = max(tree_list)
min_len = 1

ans = 0

while min_len <= max_len:
    mid_len = (min_len + max_len) // 2
    ans = 0
    for i in tree_list: # 현재 나무가 mid보다 클 때만 더함
        if i > mid_len:
            ans += i - mid_len
    if ans >= m:
        min_len = mid_len + 1
    else:
        max_len = mid_len - 1

print(max_len)