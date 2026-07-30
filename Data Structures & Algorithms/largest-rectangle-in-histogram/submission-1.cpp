class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> heightStack;

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!heightStack.empty() && heightStack.top().second > heights[i]) {
                pair<int, int> top = heightStack.top();

                int index = top.first;
                int height = top.second;

                maxArea = max(maxArea, (i - index) * height);

                start = index;
                heightStack.pop();
            }

            heightStack.push({ start, heights[i] });
        }

        while (!heightStack.empty()) {
            pair<int, int> top = heightStack.top();

            int index = top.first;
            int height = top.second;

            maxArea = max(maxArea, height * (static_cast<int>(heights.size() - index)));
            heightStack.pop();
        }

        return maxArea;
    }
};
