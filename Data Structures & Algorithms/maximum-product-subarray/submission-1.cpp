class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int previousMax = curMax;
            int previousMin = curMin;

            curMax = max({x, previousMax * x, previousMin * x});
            curMin = min({x, previousMax * x, previousMin * x});

            res = max(res, curMax);
        }

        return res;
    }
};