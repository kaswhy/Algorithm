'''
입력: n
출력: 각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수
1부터 하나씩 늘려가면서 확인
'''
import sys

while True:
    now = sys.stdin.readline().strip()
    if now == '':
        break
    n = int(now)
    cnt = 1
    num = "1" * cnt
    ntoi = int(num.lstrip('0'))

    while ntoi % n != 0:
        cnt += 1
        num = "1" * cnt
        ntoi = int(num, 10)

    print(cnt)