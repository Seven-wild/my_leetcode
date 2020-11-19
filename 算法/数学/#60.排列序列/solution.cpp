class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] =  i * factorial[i - 1];
        }
        string ans;
        k--;
        vector<int> num;
        for (int i = 1; i <= n; i++) {
            num.push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            int order = k / factorial[n - i];
            ans.push_back(num[order] + '0');
            num.erase(num.begin() + order);
            k %= factorial[n - i];
        }
        return ans;
    }
};
