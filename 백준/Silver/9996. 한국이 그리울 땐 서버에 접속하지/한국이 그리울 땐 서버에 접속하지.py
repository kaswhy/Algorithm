'''
입력: 파일 개수 N / 패턴 / 파일이름
출력: 패턴 일치 시 DA , 불일치시 NE
-> 문자열 슬라이싱 이용
'''

n = int(input())
pattern = input()

star_index = pattern.find('*')

first = pattern[:star_index]
first_len = len(first)
last = pattern[star_index+1:]
last_len = len(last)

for i in range(n):
    now = input()
    if len(now) < first_len+last_len:
        print("NE")
        continue
    if now[:first_len] == first and now[-last_len:] == last:
        print("DA")
        continue
    print("NE")