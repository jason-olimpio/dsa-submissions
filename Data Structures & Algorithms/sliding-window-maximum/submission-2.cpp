class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        deque<int> q;

        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }

            q.push_back(r);

            if (q.front() < l) {
                q.pop_front();
            }

            if (r - l + 1 == k) {
                output.push_back(nums[q.front()]);
                l++;
            }
        }

        return output;
    }
};