def solution(participant, completion):
    p = sorted(participant)
    c = sorted(completion)
    
    for i in range(len(c)):
        if p[i] != c[i]:
            return par[i]
    
    return p[i+1]
    
