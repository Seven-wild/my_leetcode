class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int current = 0, ans = 0;
        while (current < height.size()) {
            while (!s.empty() && height[current] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty()) break;
                ans += (min(height[current], height[s.top()]) - height[top]) * (current - s.top() - 1);
            }
            s.push(current++);
        }
        return ans;
    }
};
