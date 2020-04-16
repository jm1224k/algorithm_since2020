import sys

sys.stdin = open("input.txt","r")

n = int(input())
triangle = [list(map(int, input().split())) for _ in range(n)]
dp = [[0]*n for _ in range(n)]

def check_t(i,j):
    n = len(triangle[i])-1
    if i == 0:
        return triangle[0][0]

    if j == 0:
        return dp[i-1][0] + triangle[i][0]
    elif j == n:
        return dp[i-1][n-1] + triangle[i][n]
    else:
        return max(dp[i - 1][j-1] + triangle[i][j], dp[i - 1][j] + triangle[i][j])


for i,row in enumerate(triangle):
    for j, ele in enumerate(row):
        dp[i][j] = check_t(i,j)

print(max(dp[-1]))
