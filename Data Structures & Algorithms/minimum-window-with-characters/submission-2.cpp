class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char, int> tCount, window;

        for (char c : t) {
            tCount[c]++;
        }

        int have = 0, need = tCount.size();
        int l = 0;

        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (tCount.contains(c) && window[c] == tCount[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = { l, r };
                }

                window[s[l]]--;

                if (tCount.count(s[l]) && window[s[l]] < tCount[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
