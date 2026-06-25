class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int len_row = 0;
    int len_col = 0;

public:
    int numIslands(vector<vector<char>>& grid) {
        len_row = grid.size();
        len_col = grid[0].size();

        int island_num = 0;
        vector<vector<bool>> visited(len_row, vector<bool>(len_col, false));

        for (int row = 0; row < len_row; row++) {
            for (int col = 0; col < len_col; col++) {
                if (!visited[row][col] && grid[row][col] =='1') {
                    island_num++;
                    dfs(grid, visited, row, col);
                }
            }
        }

        return island_num;
    }

    void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (col < 0 || col >= len_col ||
            row < 0 || row >= len_row) {
                return;
            }

        if(visited[row][col] == true || grid[row][col]== '0') {
            return;
        }

        visited[row][col] = true;

        for(const auto& [del_row, del_col] : directions) {
            int new_row = row + del_row;
            int new_col = col + del_col;
            if (new_col >= 0 && new_col < len_col && new_row >= 0 && new_row < len_row &&
                !visited[new_row][new_col] && grid[new_row][new_col] == '1') {
                dfs(grid, visited, new_row, new_col);
            }
        }
    }
};
