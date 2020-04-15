N,M = map(int,input().split())
num_list = [i+1 for i in range(N)]
check_num = [False]*N
arr = []

def dfs(cnt,idx):
    if cnt == M:
        print(*arr)
        return

    for i in range(idx,N):
        arr.append(num_list[i])
        dfs(cnt+1,idx+1)
        arr.pop()

dfs(0,0)

