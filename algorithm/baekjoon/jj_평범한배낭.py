import sys

sys.stdin = open('input.txt','r')

n,w = map(int,input().split())
stuffs = [list(map(int,input().split())) for _ in range(n)]
stuffs = sorted(stuffs)

bag = [0 for _ in range(w+1)]

for i in range(n):
    for j in range(w,1,-1):
        if stuffs[i][0] <= j:
            bag[j] = max(bag[j], bag[j-stuffs[i][0]]+stuffs[i][1])

print(bag[-1])






# import sys
#
# sys.stdin = open('input.txt','r')
#
# n,k = map(int,input().split())
# stuffs = [[0,0]]+[list(map(int,input().split())) for _ in range(n)]
# stuffs = sorted(stuffs)
#
# dp = [0]*1000001
#
# for i in range(len(n)):
#     for j in range(i,len(n)):
#         curr_w = stuffs[j][0]
#         curr_v = stuffs[j][1]
#         for k in range(len(dp)):
#             now = 0
#             if dp[j-curr_w] != 0:
#                 dp[curr_w+stuffs[j][0]] = max(dp[curr_w+stuffs[j][0]],now)
#
