from itertools import combinations

def solution(N,arrays):
    all_N = list(range(N))
    all_team = list(combinations(all_N,int(N/2)))
    diff = 99999

    for i in range(len(all_team)//2):
        #Start 팀
        team = all_team[i]
        start_A = 0 #능력치
        for j in range(N//2):
            member = team[j]
            for k in team:
                start_A += arrays[member][k]
        #Link 팀
        team = all_team[-i-1]
        start_L = 0 #능력치
        for j in range(N//2):
            member = team[j]
            for k in team:
                start_L += arrays[member][k]

        diff = min(diff,abs(start_A-start_L))

    return (diff)

N = int(input())
arrays = [list(map(int,input().split())) for _ in range(N)]

print(solution(N,arrays))