class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], boxes[9];
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char cell = board[r][c];
                if (cell == '.') continue;
                int box = (r / 3) * 3 + (c / 3);
                if (rows[r].count(cell) || cols[c].count(cell) || boxes[box].count(cell))
                    return false;
                rows[r].insert(cell);
                cols[c].insert(cell);
                boxes[box].insert(cell);
            }
        }
        return true;
    }
};
