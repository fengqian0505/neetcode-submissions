class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        visited = [[False for col in row] for row in grid]
        directions = [
            [1, 0],[-1, 0],[0, 1],[0, -1]
        ]

        def dfs(row, col):
            if row < 0 or row >= rows or col < 0 or col >= cols:
                return 0

            if visited[row][col]:
                return 0

            if grid[row][col] == 0:
                return 0

            visited[row][col] = True
            area = 1

            for row_diff, col_diff in directions:
                area += dfs(row+row_diff, col+col_diff)

            return area
            
        max_area = 0
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1 and visited[row][col] == False:
                    max_area = max(max_area, dfs(row, col))
        
        return max_area
        