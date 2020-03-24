import heapq
def solution(jobs):
    answer = 0
    start,now = -1,0
    wait = []
    cnt = 0
    n = len(jobs)
    while cnt<n:
        for job in jobs:
            if start < job[0] <= now: #작업 중
                answer +=(now-job[0]) # 대기시간 더하기
                heapq.heappush(wait,job[1])
        if len(wait)>0:
            answer += len(wait)*wait[0] # 대기시간 더하기
            start =now
            now+=heapq.heappop(wait) # 작업이 끝난 시간 갱신
            cnt+=1
        else:
            now+=1
    return answer//n
