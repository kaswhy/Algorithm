import sys

n = int(sys.stdin.readline())

rgb = []
for i in range(n):
    rgb.append(list(map(int, sys.stdin.readline().split())))

dp = [ [0, 0, 0] for i in range(n) ]
dp[0] = rgb[0]
for i in range(1, n):
    dp[i][0] = rgb[i][0] + min(dp[i-1][1], dp[i-1][2])
    dp[i][1] = rgb[i][1] + min(dp[i-1][0], dp[i-1][2])
    dp[i][2] = rgb[i][2] + min(dp[i-1][1], dp[i-1][0])

print(min(dp[n-1]))