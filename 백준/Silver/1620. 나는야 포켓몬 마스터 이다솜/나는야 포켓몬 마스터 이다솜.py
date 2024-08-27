'''
입력: 포켓몬 개수 N, 맞춰야 하는 문제 M / 포켓몬 이름
출력: 숫자 -> 문자 / 문자 -> 숫자
딕셔너리
'''

n, m = map(int, input().split())
name_dict = {}
num_dict = {}

for i in range(n):
    name = input()
    num_dict[i+1] = name
    name_dict[name] = i+1

for i in range(m):
    quiz = input()
    if 65 <= ord(quiz[0])  <= 90:
        print(name_dict[quiz])
        continue
    new_quiz = int(quiz)
    print(num_dict[new_quiz])
