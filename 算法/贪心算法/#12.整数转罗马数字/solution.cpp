class Solution {
public:
    string intToRoman(int num) {
        string roma[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        for (int i = 0; num; i++) {
            while (num >= value[i]) {
                num -= value[i];
                ans += roma[i];
            }
        }
        return ans;
        
        string ans = "";
        char roma[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int cnt = 0;
        int div = 1000;
        for (int i = 0; num; i += 2) {
            cnt = num / div;
            switch (cnt) {
                case 1 :
                case 2 :
                case 3 : {
                    while (cnt--) ans += roma[i];
                    break;
                }
                case 4 : {
                    ans += roma[i];
                    ans += roma[i - 1];
                    break;
                }
                case 5 :
                case 6 :
                case 7 :
                case 8 : {
                    ans += roma[i - 1];
                    cnt -= 5;
                    while (cnt--) ans += roma[i];
                    break;
                }
                case 9 : {
                    ans += roma[i];
                    ans += roma[i - 2];
                }
            }
            num %= div;
            div /= 10;
        }
        return ans; 
        */
    }
};
