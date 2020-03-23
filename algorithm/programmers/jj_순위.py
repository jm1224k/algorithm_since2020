def solution(n, results):
    win = {i:set() for i in range(1,n+1)}
    lose={i:set() for i in range(1,n+1)}

    for result in results:
        win[result[0]].add(result[1])
        lose[result[1]].add(result[0])

    for idx in range(1,n+1):
        for winner in lose[idx]:
            win[winner].update(win[idx])
        for loser in win[idx]:
            lose[loser].update(lose[idx])

    cnt = 0
    for i in range(1,n+1):
        if len(win[i]) + len(lose[i]) == n-1:
            cnt += 1

    return cnt