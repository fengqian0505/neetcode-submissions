class Solution {
public:
    const int directions[4][2]  = {{1, 0}, {-1 ,0}, {0, 1}, {0, -1}};

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(dfs(board, visited, word, 0, i, j)) {
                    return true;
                }
            } 
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int word_target, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();

        // out of range
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col]) {
            return false;
        }

        if(board[row][col] != word[word_target]) {
            return false;
        }

        // find the end of the word
        if (word_target == word.size()-1) {
            return true;
        }

        visited[row][col] = true;

        for (const auto& [diff_row, diff_col] : directions) {
            if(dfs(board, visited, word, word_target+1, row+diff_row, col+diff_col)) {
                visited[row][col] = true;
                return true;
            }
        }

        visited[row][col] = false;
        return false;
    }
};
