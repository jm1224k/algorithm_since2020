import sys

sys.stdin = open('input.txt','r')

n = int(input())
array = list(map(int,input().split()))
dp = [0 for _ in range(n)]

for i in range(n): #i = current index
    min_value = 0
    for j in range(i): #j = compare index with i
        if array[i]>array[j]:
            min_value = max(min_value,dp[j])
    dp[i] = min_value +1
print(max(dp))
print(dp)

