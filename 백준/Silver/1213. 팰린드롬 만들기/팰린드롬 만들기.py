import sys

name = sys.stdin.readline().strip()

cnt = [0 for i in range(26)]
odd_cnt = 0
odd_num = -1

for i in range(len(name)):
    now = ord(name[i]) - ord('A')
    cnt[now] += 1

for i in range(26):
    if cnt[i] % 2 == 1:
        odd_cnt += 1
        odd_num = i
    if odd_cnt > 1:
        break

if odd_cnt > 1:
    print("I'm Sorry Hansoo")
else:
    left = ''
    for i in range(26):
        if cnt[i] == 0:
            continue
        if i == odd_num:
            for j in range((cnt[i]-1)//2) :
                left += chr(i + ord('A'))
            continue
        for j in range(cnt[i] // 2):
            left += chr(i + ord('A'))
    reverse = left[::-1]
    result = left

    if odd_cnt == 1:
        result += chr(odd_num + ord('A'))
    result += reverse

    print(result)