class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numsSet(nums.begin(), nums.end());

        int longest = 0;

        for (int num : nums) {
            int length = 0;
            if (numsSet.contains(num - 1)) continue;

            while (numsSet.contains(num + length)) {
                length += 1;
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
