class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def is_valid_unit(values) -> bool:
            seen = set()
            for value in values:
                if value == '.':
                    continue
                if value in seen:
                    return False
                seen.add(value)
            return True

        # check row
        for row in range(9):
            values = []
            for col in range(9):
                values.append(board[row][col])
            if not is_valid_unit(values):
                return False

        # check column
        for col in range(9):
            values = []
            for row in range(9):
                values.append(board[row][col])
            if not is_valid_unit(values):
                return False

        # check square
        for square in range(9):
            values = []
            row_base = (square // 3) * 3
            col_base = (square % 3) * 3
            for grid_idx in range(9):
                row = row_base + (grid_idx // 3)
                col = col_base + (grid_idx % 3)
                values.append(board[row][col])
            if not is_valid_unit(values):
                return False
               
        return True
        