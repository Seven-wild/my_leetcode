class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (!n) return 0;
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (n - mid == citations[mid]) {
                right = mid;
            } else if (n - mid > citations[mid]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return n - left;
    }
};
