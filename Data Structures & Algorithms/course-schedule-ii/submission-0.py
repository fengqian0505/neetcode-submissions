class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        result = []

        # build graph
        graph = {course: [] for course in range(numCourses)}
        in_degree = {course: 0 for course in range(numCourses)}
        for dest, src in prerequisites:
            graph[src].append(dest)
            in_degree[dest] += 1

        # build the queue
        dq = deque([course for course in range(numCourses) if in_degree[course] == 0])

        while dq:
            course = dq.popleft()
            result.append(course)

            # remove in degree
            for neighbor in graph[course]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    dq.append(neighbor)

        if len(result) < numCourses:
            # cycle exist
            return []

        return result
        