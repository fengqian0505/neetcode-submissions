class Solution {
    
private:
    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows = 0;
    int cols = 0;

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int max_area = 0;
        for(int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!visited[row][col] && grid[row][col] == 1) {
                    int area = dfs(grid, visited, row, col);
                    max_area = max(area, max_area);
                }
            }
        }

        return max_area;
    }

    int dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return 0;
        }

        if (grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;

        int area = 1;
        for(const auto& [del_row, del_col] : directions) {
            area += dfs(grid, visited, row+del_row, col+del_col);
        }

        return area;
    }

};