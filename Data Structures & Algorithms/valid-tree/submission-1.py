class Solution:
    """
    Two conditions to valid a tree:
    1. number of edges == n - 1
    2. no cycle
    """
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False

        # build the graph
        graph = {node: [] for node in range(n)}
        for v1, v2 in edges:
            graph[v1].append(v2)
            graph[v2].append(v1)

        visited = set()

        # dfs to check whether cycle exist
        # return False if cycle exist, else True
        def dfs(node, parent) -> bool:          
            visited.add(node)
            for neighbor in graph[node]:
                if neighbor == parent:
                    # ignore the edge from parent
                    continue
                if neighbor in visited:
                    # cycle detect
                    return False

                if not dfs(neighbor, node):
                    return False

            return True

        if not dfs(0, -1):
            return False

        if len(visited) < n:
            return False

        return True 