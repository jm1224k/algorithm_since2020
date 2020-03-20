# # list idx 테스트 1 〉	통과 (4.00ms, 15.3MB)
# def solution(phone_book):
#     answer = True
#     phone_book = list(sorted(map(str,phone_book)))
#     for idx, number in enumerate(phone_book):
#         length = len(number)
#         for numbers in phone_book[idx+1:]:
#             if numbers[:length] == number:
#                 answer = False
#                 return answer
#     return answer

# deque 테스트 1 〉	통과 (3.98ms, 15.3MB)
from collections import deque

def solution(phone_book):
    answer = True
    phone_book = deque(sorted(map(str,phone_book)))

    while phone_book:
        number = phone_book.popleft()
        lenght = len(number)
        for phone_num in phone_book:
            if number == phone_num[:lenght]:
                return False
    return answer