def solution(phone_book):
    answer = True
    phone_book = list(map(str,sorted(phone_book)))
    for idx, number in enumerate(phone_book):
        length = len(number)
        for numbers in phone_book[idx+1:]:
            if numbers[:length] == number:
                answer = False
                return answer
    return answer