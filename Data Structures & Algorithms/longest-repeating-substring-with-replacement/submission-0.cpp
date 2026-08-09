class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCount;

        int result = 0;
        int l = 0, maxF = 0;

        for (int r = 0; r < s.size(); r++) {
            charCount[s[r]]++;

            maxF = max(maxF, charCount[s[r]]);

            while((r - l + 1) - maxF > k) {
                charCount[s[l]]--;
                l++;
            }

            result = max(result, (r - l + 1));
        }

        return result;
    }
};
