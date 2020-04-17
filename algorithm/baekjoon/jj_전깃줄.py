import sys

sys.stdin = open('input.txt','r')
n = int(input())
wires = [tuple(map(int,input().split())) for _ in range(n)]

wires = sorted(wires,key=lambda x: x[0])

dp = [0]*n
dp[0] = 1

for i in range(1,n):
    min_value = 0
    for j in range(i):
        curr = wires[i][1]
        compare = wires[j][1]
        if (curr >compare):
            min_value = max(dp[j],min_value)
    dp[i] = min_value+1
print(n-max(dp))