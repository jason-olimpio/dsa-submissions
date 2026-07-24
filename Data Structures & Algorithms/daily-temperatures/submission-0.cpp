#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<std::pair<int, int>> stack;
        std::vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            int temperature = temperatures[i];

            while (!stack.empty() && stack.top().first < temperature) {
                auto p = stack.top();
                stack.pop();
                
                int length = i - p.second;
                result[p.second] = length;
            }

            stack.push({temperature, i});
        }

        return result;
    }
};