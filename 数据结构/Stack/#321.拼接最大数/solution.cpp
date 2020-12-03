class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int start = max(0, k - n), end = min(k , m);
        vector<int> maxSubseq(k);
        for (int i = start; i <= end; i++) {
            vector<int> subseq1 = Maxsubseq(nums1, i);
            vector<int> subseq2 = Maxsubseq(nums2, k - i);
            vector<int> curMaxsubseq = merge(subseq1, subseq2);
            if (compare(curMaxsubseq, maxSubseq, 0, 0) > 0) {
                maxSubseq.swap(curMaxsubseq);
            }
        }
        return maxSubseq;
    }
    vector<int> Maxsubseq(vector<int> &num, int k) {
        vector<int> stack(k);
        int top = -1;
        int remain = num.size() - k;
        for (int i = 0; i < num.size(); i++) {
            while (top >= 0 && num[i] > stack[top] && remain > 0) {
                top--;
                remain--;
            }
            if (top < k - 1) {
                stack[++top] = num[i];
            } else {
                remain--;
            }
        }
        return stack;
    }
    vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 == 0) return nums2;
        if (len2 == 0) return nums1;
        int n = len1 + len2;
        vector<int> temp(n);
        int ind1 = 0, ind2 = 0;
        for (int i = 0; i < n; i++) {
            if (compare(nums1, nums2, ind1, ind2) > 0) {
                temp[i] = nums1[ind1++];
            } else {
                temp[i] = nums2[ind2++];
            }
        }
        return temp;
    }
    int compare(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2) {
        int x = nums1.size(), y = nums2.size();
        while (ind1 < x && ind2 < y) {
            int dif = nums1[ind1] - nums2[ind2]; 
            if (dif != 0) return dif;
            ind1++;
            ind2++;
        }
        return (x - ind1) - (y - ind2);
    }
};
