class Solution:
    def findOrder(self, numCourses: int, prereqisites: List[List[int]]) -> List[int]:
        result = []

        # build the graph
        in_degrees = [0 for course in range(numCourses)]
        graph = [[] for course in range(numCourses)]
        for dest, source in prereqisites:
            graph[source].append(dest)
            in_degrees[dest] += 1

        q = deque([course for course in range(numCourses) if in_degrees[course] == 0])

        # bfs
        while q:
            for node in graph[q[0]]:
                in_degrees[node] -= 1
                if in_degrees[node] == 0:
                    q.append(node)
            result.append(q[0])
            q.popleft()

        # if has cycle
        if len(result) < numCourses:
            return []

        return result
        