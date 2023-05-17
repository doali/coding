graph = {
    "a": ["b", "c"],
    "b": ["a", "d", "e"],
    "c": ["a", "d"],
    "d": ["b", "c", "e"],
    "e": ["b", "d", "f", "g"],
    "f": ["e", "g"],
    "g": ["e", "f", "h"],
    "h": ["g"],
}


def dfs(graph, start):
    stack = [start]
    visited = []

    while len(stack) != 0:
        vertex = stack.pop()

        if not vertex in visited:
            visited.append(vertex)
            for node in graph[vertex]:
                if not node in visited:
                    stack.append(node)

    return f"{visited}"


res = dfs(graph, "g")
print(res)
