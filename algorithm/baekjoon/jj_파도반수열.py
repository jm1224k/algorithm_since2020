import sys

sys.stdin = open('input.txt','r')

n = int(input())
test_case = [int(input()) for _ in range(n)]
dp =[1,1,1,2,2,3,4,5,7,9]+[0]*90

def padovan(i):
    if dp[i]:
        return
    padovan(i-1)
    dp[i] = dp[i-1]+dp[i-5]

for i in test_case:
    i -= 1
    if i < 10 :
        print(dp[i])
    else:
        padovan(i)
        print(dp[i])


