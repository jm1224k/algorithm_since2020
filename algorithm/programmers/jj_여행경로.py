def solution(tickets):
    routes = {}
    for t in tickets:
        #출발 공항이 key 갈수 있는 공항이 value
        routes[t[0]] = routes.get(t[0],[]) + [t[1]]

    for r in routes:
        routes[r].sort(reverse = True)

    stack = ['ICN'] # ICN이 무조건 먼저 이므로
    path = [] #가고자 하는 경로
    while len(stack)>0: #stack이 다 없어질떄까지
        top = stack[-1]
        #어떤 공항에서 출발하는 표가 한 장도 없다면, 또는 있었는데 다 써버렸다면
        if top not in routes or len(routes[top]) == 0:
            path.append(stack.pop())

        else:
            stack.append(routes[top][-1])
            routes[top] = routes[top][:-1]
    return path[::-1]