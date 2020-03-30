# 1.
def solution(K, travel):
    answer = 0
    dp = [[0 for _ in range(100001)]for _ in range(101)]
    dp[0][travel[0][0]]=travel[0][1]
    dp[0][travel[0][2]]=travel[0][3]
    for i in range(1,len(travel)):
        for j in range(K):
            if dp[i-1][j] == 0 : # 이전에 들르지 않았을 경우 지나감
                continue
            if (j+travel[i][0]<=K): # 도보이동
                dp[i][j+travel[i][0]] = max(dp[i][j+travel[i][0]],dp[i-1][j]+travel[i][1])
                answer = max(answer,dp[i][j+travel[i][0]])
            if (j+travel[i][2]<=K): # 자전거 이동
                dp[i][j+travel[i][2]] = max(dp[i][j+travel[i][2]],dp[i-1][j]+travel[i][3])
                answer = max(answer,dp[i][j+travel[i][2]])
    return answer

# 2.
# def solution(K, travel):
#     n=len(travel)
#
#     memo=[[0 for j in range(K+1)] for x in range(n+1)]
#
#     for i in range(1,n+1):
#         t_walk,v_walk,t_bike,v_bike=travel[i-1]
#
#         for j in range(K+1):
#             #walk
#             walk=memo[i-1][j-t_walk]+v_walk if j>=t_walk and memo[i-1][j-t_walk]!=-1 else -1
#             bike=memo[i-1][j-t_bike]+v_bike if j>=t_bike and memo[i-1][j-t_bike]!=-1 else -1
#
#             memo[i][j]=max(walk,bike)
#
#     return  memo[n][K]