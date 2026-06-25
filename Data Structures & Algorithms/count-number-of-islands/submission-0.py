class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        islands = 0
        rows, cols = len(grid), len(grid[0])
        visited = [[False] * cols for _ in range(rows)]

        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        def dfs(r, c) -> None:
            if (r < 0 or r >= rows
                or c < 0 or c >= cols
                or grid[r][c] == '0'
                or visited[r][c]):
                return

            visited[r][c] = True

            for dr, dc in directions:
                dfs(r+dr, c+dc)
            
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1' and not visited[r][c]:
                    dfs(r, c)
                    islands += 1
        
        return islands
