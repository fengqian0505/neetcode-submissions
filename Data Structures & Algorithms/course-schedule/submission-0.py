class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # build graph
        graph = {course: [] for course in range(numCourses)}
        for dest, src in prerequisites:
            graph[src].append(dest)

        visited = set()
        rec_stack = set()

        def dfs_has_cycle(node):
            if node in rec_stack:
                # has cycle
                return True
            if node in visited:
                return False

            visited.add(node)
            
            rec_stack.add(node)
            for neighbour in graph[node]:
                if dfs_has_cycle(neighbour):
                    return True
            rec_stack.remove(node)

            return False

        for course in range(numCourses):
            if dfs_has_cycle(course):
                return False

        return True
        