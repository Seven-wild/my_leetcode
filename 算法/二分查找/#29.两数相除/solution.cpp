class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!dividend) return 0;
        if (divisor == 1) return dividend; 
        if (divisor == -1) return (dividend == INT_MIN)? INT_MAX : -dividend;
        
        int ans = 0;
        bool flag = (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0);
        if (divisor == INT_MIN) return (dividend == INT_MIN) ? 1 : 0;
        if (dividend == INT_MIN) {
            dividend = (flag) ? dividend - divisor : dividend + divisor;
            ans++;
        } 
        dividend = (dividend > 0) ? dividend : -dividend;
        divisor = (divisor > 0) ? divisor : -divisor;
        ans += my_divide(dividend,divisor);
        return flag ? ans : -ans; 
    }
    int my_divide(int dividend, int divisor) {
        if (dividend < divisor) return 0;
        int ans = 1;
        int original_divisor = divisor;
        while (dividend - divisor > divisor) {
            ans += ans;
            divisor += divisor;
        }
        return ans + my_divide(dividend - divisor, original_divisor);
    }
};
