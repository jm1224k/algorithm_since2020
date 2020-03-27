def solution(clothes):
    answer = 1
    closet = {}
    for cloth,cat in clothes:
        if cat not in closet:
            closet[cat] = [cloth]
        else:
            closet[cat].append(cloth)

    for key in closet.keys():
        answer *= (len(closet[key])+1)

    return answer -1