class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int lefttotal = (m + n + 1) / 2;
        int l = 0, r = m;
        while (l < r) {
            int i = (l + r + 1) >> 1;
            int j = lefttotal - i;
            if (nums1[i - 1] > nums2[j]) {
                r = i - 1;
            } else {
                l = i;
            }
        }
        int i = l;
        int j = lefttotal - i;

        int num1left = (i == 0 ? INT_MIN : nums1[i - 1]);
        int num2left = (j == 0 ? INT_MIN : nums2[j - 1]);
        int num1right = (i == m ? INT_MAX : nums1[i]);
        int num2right = (j == n ? INT_MAX : nums2[j]);
        return (m + n) % 2 == 1 ?  max(num1left, num2left) : (double) (max(num1left, num2left) + min(num1right, num2right)) / 2.0;
    }
};
