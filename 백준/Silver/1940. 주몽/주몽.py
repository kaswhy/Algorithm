import sys

n = int(sys.stdin.readline().strip())
m = int(sys.stdin.readline().strip())
nums = list(map(int, sys.stdin.readline().split()))
nums.sort()

cnt = 0
start = 0
end = len(nums) - 1

while len(nums) > end > start >= 0:
    if nums[start] + nums[end] == m:
        cnt += 1
        start += 1
        end -= 1
        continue
    if nums[start] + nums[end] > m: # 부분합이 목표값보다 큼 => 줄여야
        end -= 1
        continue
    # 부분합 < 목표값 -> 키워야 함
    start += 1

print(cnt)