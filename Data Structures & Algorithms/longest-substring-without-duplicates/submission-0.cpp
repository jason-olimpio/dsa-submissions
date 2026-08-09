class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> charSet;

        int l = 0;
        int result = 0;

        for (int r = 0; r < s.size(); r++) {
            while (charSet.contains(s[r])) {
                charSet.erase(s[l]);
                l++;
            }

            charSet.insert(s[r]);
            result = max(result, r - l + 1);
        }

        return result;
    }
};
