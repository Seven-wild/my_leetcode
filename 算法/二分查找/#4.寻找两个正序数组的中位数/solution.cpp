class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //选取较短的数组二分搜索
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size(), n = nums2.size();
        //中位数左边元素总个数 （假设中位数总被分到左边）
        int total_left = (m + n + 1) / 2;
        //搜索区间[0, m]
        int left = 0, right = m;
        while (left < right) {
            // 前半部分包括 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后半部分包括 nums1[i .. m-1] 和 nums2[j .. n-1]
            // nums1[i-1] < nums2[j] && nums2[m-1] < nums1[i]
            int i = (left + right + 1) >> 1;
            int j = total_left - i;
            if (nums1[i - 1] > nums2[j]) {
                right = i - 1;
            } else {
                left = i;
            }
        }
        int i = left, j = total_left - i;
        //注意特殊情况的处理
        int nums1_left = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums1_right = (i == m ? INT_MAX : nums1[i]);
        int nums2_left = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums2_right = (j == n ? INT_MAX : nums2[j]);
        // m+n为奇数和偶数需判断
        return (m + n) % 2 == 1 ? max(nums1_left, nums2_left) : (double)(max(nums1_left, nums2_left) + min(nums1_right, nums2_right)) / 2.0;
    }
};
