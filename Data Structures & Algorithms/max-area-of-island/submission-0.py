class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        
        if not grid:
            return max_area

        rows, cols = len(grid), len(grid[0])
        visited = [[False] * cols for _ in range(rows)]

        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        def dfs(r, c) -> int:
            if (r < 0 or r >= rows
                    or c < 0 or c >= cols
                    or visited[r][c]
                    or grid[r][c] == 0):
                return 0

            visited[r][c] = True
            area = 1

            for dr, dc in directions:
                area += dfs(r + dr, c + dc)
            return area

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1 and not visited[r][c]:
                    max_area = max(max_area, dfs(r, c))

        return max_area