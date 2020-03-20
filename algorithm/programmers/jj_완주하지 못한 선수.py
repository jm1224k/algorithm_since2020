# # 1 . use deque 테스트 4 〉	통과 (104.14ms, 168MB)
from collections import deque
def solution(participant, completion):
    answer = ''
    participant = deque(sorted(participant))
    completion = deque(sorted(completion))

    while completion:
        a = participant.popleft()
        b = completion.popleft()
        if a != b:
            return a
    return participant[-1]

# 2. use hash key
# def solution(participant, completion):
#     answer = ''
#     temp = 0
#     dic = {}
#     for part in participant:
#         dic[hash(part)] = part
#         temp += int(hash(part))
#     for com in completion:
#         temp -= hash(com)
#     answer = dic[temp]
#
#     return answer

# 3. use collections - Counter
# import collections
# #
# def solution(participant, completion):
#     a = collections.Counter(participant)
#     b = collections.Counter(completion)
#     answer = a - b
#     answer = list(answer.keys())
#     return answer[0]
