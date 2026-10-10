class Solution:
    def findOrder(self, numCourses: int, prereqisites: List[List[int]]) -> List[int]:
        result = []

        # build the graph
        in_degrees = [0] * numCourses
        graph = [[] for _ in range(numCourses)]
        for dest, source in prereqisites:
            graph[source].append(dest)
            in_degrees[dest] += 1

        q = deque([course for course in range(numCourses) if in_degrees[course] == 0])

        # bfs
        while q:
            course = q.popleft()
            result.append(course)
            for neighbor in graph[course]:
                in_degrees[neighbor] -= 1
                if in_degrees[neighbor] == 0:
                    q.append(neighbor)

        # if has cycle
        if len(result) != numCourses:
            return []

        return result
        