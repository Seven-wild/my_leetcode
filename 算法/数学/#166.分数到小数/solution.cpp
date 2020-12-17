class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";
        if (numerator == 0) return "0";
        string ans;
        long long num = static_cast<long long>(numerator);
        long long denom = static_cast<long long>(denominator);
        if ((num > 0) ^ (denom > 0)) ans.push_back('-');
        num = llabs(num), denom = llabs(denom);
        ans.append(to_string(num / denom));
        num %= denom;
        if (num == 0) return ans;
        ans.push_back('.');
        int index = ans.size() - 1;
        unordered_map<int, int> record;
        while (num && record.count(num) == 0) {
            record[num] = ++index;
            num *= 10;
            ans += to_string(num / denom);
            num %= denom;
        }
        if (record.count(num) == 1) {
            ans.insert(record[num], "(");
            ans.push_back(')');
        }
        return ans;
    }
};
