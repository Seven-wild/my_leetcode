class Solution {
public:
    double pow_(double x , long long n) {
        if (n == 1) return x;
        double t = pow_(x, n / 2);
        if (n % 2 == 0) return t * t;
        else return t * t * x;
    }
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long long N = n;
        if (N < 0) N = -N;
        double ans = pow_(x, N);
        return n < 0 ? 1 / ans : ans;
    }
};
