class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        return not self.hasCycle(numCourses, prerequisites)

    def hasCycle(self, numCourses, prerequistites):
        graph = [[] for _ in range(numCourses)]
        for dest, source in prerequistites:
            graph[source].append(dest)

        UNVISITED = 0
        VISITING = 1
        VISITED = 2
        state = [UNVISITED] * numCourses

        def dfs_has_cycle(node):
            if state[node] == VISITING:
                return True

            if state[node] == VISITED:
                return False
            
            state[node] = VISITING

            for neighbor in graph[node]:
                if dfs_has_cycle(neighbor):
                    return True

            state[node] = VISITED
            return False
        
        for course in range(numCourses):
            if dfs_has_cycle(course):
                return True
            
        return False