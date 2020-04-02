import heapq

def solution(operations):
    cnt = 0
    minhq = []
    maxhq = []

    for operation in operations:
        if operation[0] == 'I':
            number = int(operation[2:])
            heapq.heappush(minhq,number)
            heapq.heappush(maxhq,-number)
            cnt += 1

        else:
            if cnt != 0:
                if operation == 'D 1':
                    heapq.heappop(maxhq)
                elif operation == 'D -1':
                    heapq.heappop(minhq)
                cnt -= 1
            if cnt == 0:
                maxhq = []
                minhq = []

    if cnt != 0:
        answer = [-heapq.heappop(maxhq),heapq.heappop(minhq)]
    else:
        answer = [0,0]
        
    return answer