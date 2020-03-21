def solution(money):
    answer = 0
    length = len(money)
    dp1 = [0]*length
    dp1[0] = money[0]
    dp1[1] = max(money[0],money[1])

    for i in range(2, length-1):
        dp1[i] = max(dp1[i-1],money[i]+dp1[i-2])

    dp2 = [0]*length
    dp2[0] = 0
    dp2[1] = money[1]

    for i in range(2,length):
        dp2[i] = max(dp2[i-1], money[i]+dp2[i-2])

    return max(max(dp1),max(dp2))

print(solution([8,3,2,7,1,2,3,1]))