import sys

a = sys.stdin.readline().strip().upper()
b = sys.stdin.readline().strip().upper()

len1 = len(a)
len2 = len(b)

matrix = [[0]*(len2+1) for _ in range(len1+1)]

for i in range(1,len1+1):
    for j in range(1,len2+1):
        A = a[i-1]
        B = b[j-1]
        if A == B:
            matrix[i][j] = matrix[i-1][j-1]+1
        else:
            matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1])

print(matrix[-1][-1])