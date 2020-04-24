import sys

sys.stdin = open('input.txt','r')
#
# def solve(arrays,n):
#     dp = [0]*n
#     dp[0] = arrays[0]
#     dp[1] = arrays[1]+dp[0]
#     dp[2] = max(arrays[2]+dp[0], arrays[2]+arrays[1])
#
#     for i in range(3,n):
#         curr = arrays[i]
#         dp[i] = max(curr+arrays[i-1]+dp[i-3], curr+dp[i-2])
#     print(dp[-1])
#
# if __name__ == "__main__":
#     n = int(input())
#     arrays = [int(input()) for _ in range(n)]
#     solve(arrays,n)

n = int(input())
s = [0 for i in range(301)]
dp = [0 for i in range(301)]
for i in range(n):
    s[i] = int(input())
dp[0] = s[0]
dp[1] = s[0] + s[1]
dp[2] = max(s[1] + s[2], s[0] + s[2])
for i in range(3, n):
    dp[i] = max(dp[i - 3] + s[i - 1] + s[i], dp[i - 2] + s[i])
print(dp[n - 1])