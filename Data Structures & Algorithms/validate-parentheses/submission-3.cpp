class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (pairs.count(c)) {
                if (!brackets.empty() && brackets.top() == pairs[c]) {
                    brackets.pop();
                }

                else {
                    return false;
                }
            } else {
                brackets.push(c);
            }
        }

        return brackets.empty();
    }
};
