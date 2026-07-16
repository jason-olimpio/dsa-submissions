class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string str : strs) {
            string signature = str;

            std::sort(signature.begin(), signature.end());

            groups[signature].push_back(str);
        }

        vector<vector<string>> result;

        for (auto& pair : groups) {
            result.push_back(std::move(pair.second));
        }

        return result;
    }
};
