class Solution {
public:
    string convert(string s, int numRows) {
       int len = s.length();
       if (len < 2 || numRows == 1) return s;
        vector<string> temp(numRows);
       int loc = 0;
       bool down = false;
       for (int i = 0; i < len; i++) {
           temp[loc] += s[i];
           if (loc == 0 || loc == numRows - 1) {
               down = !down;
           }
           loc += down ? 1 : -1;
       }
       string ans = "";
       for (int i = 0; i < numRows;i++) {
           ans += temp[i];
       }
       return ans;
    }
};
