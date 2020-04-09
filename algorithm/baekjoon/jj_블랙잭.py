from itertools import combinations

#1. 조합 만들어서 풀기
def solution(M,num_list):
    com_3 = list(combinations(num_list,3))
    maximum = 0
    for com in com_3:
        sum_com = sum(com)
        if sum_com > M:
            continue
        else:
            maximum = max(maximum,sum_com)
    return maximum

#2. 시간 줄이기..
def time_sol(M,num_list):
    num_list = sorted(num_list,reverse=True)
    length = len(num_list)
    min_cost = M
    for idx in range(length):
        curr_cost = M - num_list[idx]
        com_2 = sorted(list(combinations(num_list[idx+1:], 2)), reverse=True)
        for cards in com_2:
            sums = sum(cards)
            if curr_cost - sums >= 0:
                min_cost = min(min_cost, curr_cost - sums)
                continue
    return M - min_cost

N,M = map(int,input().split())
num_list = list(map(int,input().split()))
print(solution(M,num_list))