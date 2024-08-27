'''
입력: 전체 날짜 수 N, 연속적인 날짜 수 K / 온도 정보
출력: K일의 온도 합이 최대가 되는 값
-> 부분합!
0부터 시작해서 계속 더하고 index가 k-1인 곳부터 추적해나감
'''
n, k = map(int, input().split())

temp_list = list(map(int, input().split()))
temp_sum = 0

sum_list = []

for i in range(n):
    temp_sum += temp_list[i]
    if i == k -1:
        sum_list.append(temp_sum)
        continue
    if i > k-1:
        temp_sum -= temp_list[i-k]
        sum_list.append(temp_sum)


print(max(sum_list))