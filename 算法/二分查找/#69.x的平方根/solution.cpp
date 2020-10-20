class Solution {
public:
    int mySqrt(int x) {
        int left = 0 , right = x/2 + 2;
        while (left < right) {
            int mid = (left + right) >> 1;
            if ((long long)mid*mid <= x ) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1 ;
    }
};
