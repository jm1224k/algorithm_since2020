def solution(N):
    temp_list=[1,1]
    for i in range(2, N+1):
        temp_list.append(temp_list[-1]+temp_list[-2])
    return temp_list[-2]*2 + temp_list[-1]*2