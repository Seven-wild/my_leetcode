class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.size() == 0) return 0;
        if (A.size() == 1) return 1;
        int left = 0, right = 0;
        bool lastcmp = ! (A[1] > A[0]) , nowcmp;
        int ans = 0;
        while (right < A.size() - 1) {
            right++;
            nowcmp = (A[right] > A[right - 1] );
            if (A[right] == A[right - 1]) left =right;
            else if (!(nowcmp - lastcmp)) {
                left = right - 1;
            }
            lastcmp = nowcmp;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
