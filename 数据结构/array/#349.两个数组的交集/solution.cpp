class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1_set(nums1.begin(),nums1.end());
        unordered_set<int> res;
        for (int i = 0; i < nums2.size(); ++i) {
            if (num1_set.count(nums2[i]) == 1) {
                res.insert(nums2[i]);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
