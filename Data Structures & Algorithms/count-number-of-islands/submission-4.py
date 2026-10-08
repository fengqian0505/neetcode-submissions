class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        count = 0

        visited = [[False for col in row] for row in grid]
        directions = [
            [1, 0],[-1, 0],[0, 1],[0, -1]
        ]

        def dfs(row, col):
            if row < 0 or row >= rows or col < 0 or col >= cols:
                return

            if visited[row][col]:
                return

            if grid[row][col] == '0':
                return

            visited[row][col] = True

            for row_diff, col_diff in directions:
                dfs(row+row_diff, col+col_diff)
            
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == '1' and visited[row][col] == False:
                    count += 1
                dfs(row, col)
        
        return count




        