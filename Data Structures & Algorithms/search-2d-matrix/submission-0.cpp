class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        int bot = 0;
        int top = rows - 1;
        int selectedRow = -1;

        while (bot <= top) {
            int m = bot + (top - bot) / 2;

            if (target < matrix[m][0]) {
                top = m - 1;
            } else if (target > matrix[m][cols - 1]) {
                bot = m + 1;
            } else {
                selectedRow = m;
                break;
            }
        }

        if (selectedRow == -1) {
            return false;
        }

        int l = 0;
        int r = cols - 1;

        while (l <= r) {
            int middle = l + (r - l) / 2;

            if (matrix[selectedRow][middle] == target) {
                return true;
            } else if (target < matrix[selectedRow][middle]) {
                r = middle - 1;
            } else {
                l = middle + 1;
            }
        }

        return false;
    }
};