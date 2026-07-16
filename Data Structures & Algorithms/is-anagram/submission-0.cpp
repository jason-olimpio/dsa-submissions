class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> sCount;
        unordered_map<char, int> tCount;

        for (int i = 0; i < s.size(); i++) {
            sCount[s[i]]++;
            tCount[t[i]]++;
        }

        for (auto pair : sCount) {
            int tElement = tCount[pair.first];
            
            if (pair.second != tElement) return false;
        }

        return true;
    }
};
