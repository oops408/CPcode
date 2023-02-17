from collections import deque

def bfs(graph, start, goal):
    queue = deque([start])
    visited = set([start])
    parent = {start: None}

    while queue:
        node = queue.popleft()

        if node == goal:
            path = []
            while node:
                path.append(node)
                node = parent[node]
            return list(reversed(path))

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                parent[neighbor] = node
                queue.append(neighbor)

    return None
