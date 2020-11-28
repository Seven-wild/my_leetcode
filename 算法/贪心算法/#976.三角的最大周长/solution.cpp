class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < A.size() - 2; i++) {
            if (A[i] - A[i + 1] < A[i + 2] && A[i + 1] + A[i + 2] > A[i]) {
                ans = A[i] + A[i + 1] + A[i + 2];
                break;
            }
        }    
        return ans;
    }
};
