class Solution {
private:
    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows = 0;
    int cols = 0;

public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int island_num = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    island_num++;
                    dfs(grid, visited, row, col);
                }
            }
        }

        return island_num;
    }

    void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (col < 0 || col >= cols || row < 0 || row >= rows) {
            return;
        }

        if(visited[row][col]|| grid[row][col]== '0') {
            return;
        }

        visited[row][col] = true;

        for(const auto& [del_row, del_col] : directions) {
            dfs(grid, visited, row + del_row, col + del_col);
        }
    }
};
