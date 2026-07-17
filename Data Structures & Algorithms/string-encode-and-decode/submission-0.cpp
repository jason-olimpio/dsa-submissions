class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (string str : strs) {
            result.append(to_string(str.size()));
            result.push_back('#');
            result.append(str);
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < s.length()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = length + i;
            string newStr = s.substr(i, length);
            result.push_back(newStr);
            i = j;
        }

        return result;
    }
};
