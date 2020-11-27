class Solution {
public:
    int merge(vector<int> &nums, int left, int right) {
        if (left == right) return 0;
        int mid = (left + right) >> 1;
        int n1 = merge(nums, left, mid);
        int n2 = merge(nums, mid + 1, right);
        int ret = n1 + n2;
        int l = left, r = mid + 1;
        while (l <= mid) {
            while (r <= right && (long long)nums[l] > 2 * (long long)nums[r]) r++;
            ret += (r - mid - 1);
            l++; 
        }
        vector<int> temp(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right) {
            if (p2 > right || (p1 <= mid && nums[p1] < nums[p2])) {
                temp[p++] = nums[p1++];
            } else {
                temp[p++] = nums[p2++];
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            nums[left + i] = temp[i];
        }
        return ret;
    }
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = merge(nums, 0, nums.size() - 1);
        return ans;
    }
};
