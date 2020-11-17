class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int l_max = 0, r_max = 0;
        int ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] > l_max ? l_max = height[left] : ans += l_max - height[left];
                left++;
            } else {
                height[right] > r_max ? r_max = height[right] : ans += r_max - height[right];
                right--;
            }
        }
        return ans;
    }
};
