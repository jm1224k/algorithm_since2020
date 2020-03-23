def solution(people, limit):
    # 무거운 사람부터 꺼내되 가벼운 사람이 낄 수 있으면 같이 내보낸다.
    people = sorted(people,reverse=True)
    first, last = 0, len(people) - 1

    while first <= last:
        # 1. people[first] + people[last] <= limit 이라면 last 1 줄임.
        if people[first] + people[last] <= limit:
            last -= 1

        # first 1늘림.
        first += 1

    answer = first
    return answer