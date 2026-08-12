class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyCount; // number, times

        for (int i = 0; i < nums.size(); i++) {
            frequencyCount[nums[i]]++;
        }

        vector<vector<int>> occurrences(nums.size() + 1);

        for (auto i = frequencyCount.begin(); i != frequencyCount.end(); i++) {
            occurrences[i->second].push_back(i->first);
        }

        vector<int> output;

        // [3: 2, 4, 5, 4 : 5, 6, 7]
        for (int i = occurrences.size() - 1; i > 0; i--) {
            for (int num : occurrences[i]) {
                output.push_back(num);
            }

            if (output.size() == k) {
                return output;
            }
        }

        return output;
    }
};