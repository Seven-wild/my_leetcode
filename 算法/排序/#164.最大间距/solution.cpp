class Solution {
public:
    int max_bit(int max_val) {
        int p = 10;
        int d = 1;
        while (max_val >= p) {
            p *= 10;
            d++;
        }
        return d;
    }
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        vector<int> temp(n);
        int max_val = *max_element(nums.begin(), nums.end());
        int time = max_bit(max_val);
        int dev = 1;
        for (int i = 0; i < time; i++) {
            vector<int> count(10);
            for (int j = 0; j < n; j++) {
                int digit = (nums[j] / dev) % 10;
                count[digit]++;
            }
            for (int j = 1; j < 10; j++) {
                count[j] += count[j - 1];
            }
            for (int j = n - 1; j >= 0; j--) {
                int digit = (nums[j] / dev) % 10;
                temp[count[digit] - 1] = nums[j];
                count[digit]--;
            }
            copy(temp.begin(), temp.end(), nums.begin());
            dev *= 10;
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
