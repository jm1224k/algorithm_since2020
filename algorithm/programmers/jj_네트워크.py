def bfs(graph, start_node):
    visit = []
    queue = []

    queue.append(start_node)

    while queue:
        node = queue.pop()
        if node not in visit:
            visit.append(node)
            queue.extend(graph[node])

    return visit


def solution(n,computers):
    #1. 연결되어 있는 네트워크 그래프 만들기
    graph = {node : [] for node in range(n)}

    for i ,computer in enumerate(computers):
        for j , conn in enumerate(computer):
            if i != j and conn == 1:
                graph[i].append(j)

    #2. graph를 순회하면서 모든 연결된 네트워크들의 path 리스트를 추가하기.
    tmp = []
    for node in graph:
        tmp.append(bfs(graph,node))

    # 3. 각각의 path에 대하여 경로 정리해서 추가하기
    paths = list(map(sorted,tmp))
    print(paths)

    result = []
    for path in paths :
        result.append(''.join(map(str,path)))

    #똑같은 경로 제거하기 (방향이 없는 graph이므로, 쳐내는 단계가 필요함)
    print(result)
    result = set(result)
    return len(result)