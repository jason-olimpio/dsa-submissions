class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> columns(9);
        vector<set<char>> squares(9);

        for (int row = 0; row < 9; row++) {
            for (int column = 0; column < 9; column++) {
                char current_val = board[row][column];
                
                if (current_val == '.') continue;
                
                int square_index = (row / 3) * 3 + (column / 3);
                
                if (rows[row].contains(current_val) ||
                    columns[column].contains(current_val) ||
                    squares[square_index].contains(current_val)) {
                    return false;
                }
                
                rows[row].insert(current_val);
                columns[column].insert(current_val);
                squares[square_index].insert(current_val);
            }
        }

        return true;
    }
};