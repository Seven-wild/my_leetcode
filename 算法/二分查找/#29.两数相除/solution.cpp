class Solution {
public:
    int divide(int dividend, int divisor) {
        // 边界判断
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return (dividend == INT_MIN) ? INT_MAX : -dividend;
        
        int ans = 0;
        // flag = 1结果为正 flag = 0结果为负
        bool flag = (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0);
        if (divisor == INT_MIN) return (dividend == INT_MIN) ? 1 : 0;
        // 如果被除数是INT_MIN 先除一次防止计算绝对值时溢出
        if (dividend == INT_MIN) {
            dividend = flag ? dividend - divisor : dividend + divisor;
            ans += 1;
        }
        //统一转变成整数处理
        dividend = dividend > 0 ? dividend : -dividend;
        divisor = divisor > 0 ? divisor : -divisor;
        ans += my_divide(dividend, divisor);
        return flag ? ans : -ans;
    }
    int my_divide(int dividend, int divisor) {
        if (dividend < divisor) return 0;
        int res = 1;
        int origin_divisor = divisor;
        // 成倍的除
        while (dividend - divisor > divisor) {
            res += res;
            divisor += divisor;
        }
        return res + my_divide(dividend - divisor, origin_divisor);
    }
};
