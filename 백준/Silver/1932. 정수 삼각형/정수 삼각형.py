'''
입력: 삼각형 크기 n / 정수 삼각형
출력: 합이 최대가 되는 경로에 있는 수의 합
    1
    2 3
    4 5 6

    => dp 이용하기
         1) top-down 방식
         2) 행 수만큼 리스트 만들어놓음
         3) 마지막 행은 처음에 입력 받은 거랑 똑같이 복사
         4) 행 하나씩 줄여가면서(올라가면서) 바로 아래 두 개 중에 하나 중 큰 걸로 선택
            - 내가 0 이면 0이랑 1 중에 선택
         5) return [0][0]
'''
import sys

n = int(sys.stdin.readline())
nums = []

for i in range(n):
    nums.append(list(map(int, sys.stdin.readline().split())))

dp = [ [0 for j in range(len(nums[i])) ] for i in range(n) ]
dp[n-1] = nums[n-1]

row = n-2
while row >= 0:
    for j in range(len(nums[row])):
        dp[row][j] = nums[row][j] + max(dp[row+1][j], dp[row+1][j+1])
    row -= 1

print(dp[0][0])