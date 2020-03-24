import heapq

def solution(jobs):
    last = -1; now = 0; answer = 0
    wait = []
    length = len(jobs)
    count = 0

    while(count < length):
        for job in jobs:
            if last < job[0] <= now:
                answer += (now -job[0])
                heapq.heappush(wait, job[1])
        if len(wait) > 0:
            answer += len(wait) * wait[0]
            last = now
            now += heapq.heappop(wait)
            count += 1
        else:
            now += 1
    return answer//length


# 힙

# import heapq

# heap = []
# jobs = [[0, 3], [1, 9], [2, 6]]
# status = 0; answer = 0

# # jobs 리스트 swap하기. jobs = [[3, 0], [9, 1], [6, 2]]
# for i in jobs:
#   i[0],i[1] = i[1], i[0] 

# # 딕셔너리화
# dic_jobs = dict(jobs)

# # 힙구조 생성
# for i in jobs:
#   heapq.heappush(heap,i[0])

# # 힙 최소 정렬.
# sorted_jobs = []
# while heap:
#   sorted_jobs.append(heapq.heappop(heap))
  
# # 디스크 컨트롤러 최소시간
# for i in sorted_jobs:
#   status = status + i
#   answer = answer + (status - dic_jobs[i])
# print(answer/3)
