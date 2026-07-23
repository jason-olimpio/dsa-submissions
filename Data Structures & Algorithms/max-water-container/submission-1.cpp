class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int result = 0;

        while (l < r) {
            int area = (r - l) * min(heights[r], heights[l]);
            result = max(result, area);

            if (heights[l] < heights[r]) {
                l++;
            }

            else {
                r--;
            }
        }

        return result;
    }
};
