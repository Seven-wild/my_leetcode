class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int current = 0, ans = 0;
        while (current < heights.size()) {
            while (!s.empty() && heights[current] < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width = current;
                if (!s.empty()) {
                    width = current - s.top() - 1;
                }
                ans = max(ans, height * width);
            }
            s.push(current++);
        }
        while (!s.empty()) {
            int height = heights[s.top()];
            s.pop();
            int width = heights.size();
            if (!s.empty()) {
                width = heights.size() - s.top() - 1;
            }
            ans = max(ans, height * width);
        }
        return ans;
    }
};
