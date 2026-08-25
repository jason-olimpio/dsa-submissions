class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {

            // Odd-length palindromes
            int l = i, r = i;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }

            // Even-length palindromes
            l = i;
            r = i + 1;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }

        return res;
    }
};