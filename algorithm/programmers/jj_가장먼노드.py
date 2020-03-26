from collections import deque as queue,defaultdict

def bfs(start,tables,visited):
    graph = queue()
    graph.append((start,0))
    visited.add(start)

    numbers = defaultdict(lambda:0)
    while graph:
        node,cnt = graph.popleft()
        visited.add(node)
        for neighbor in tables[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                numbers[cnt+1] += 1
                graph.append((neighbor,cnt+1))

    return numbers[cnt]

def solution(n, edge):
    tables = defaultdict(set)
    for a,b in edge:
        tables[a].add(b)
        tables[b].add(a)
    visited = set()
    return bfs(1, tables, visited)