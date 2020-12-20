class Solution {
public:
    string convert(string s, int numRows) {
        // numRows == 1 直接返回
        if (numRows == 1) return s;
        vector<string> temp(numRows);
        // 初始位置
        int loc = 0;
        // loc移动方向 down为真向loc++ down为假loc--
        bool down = true;
        for (auto ch : s) {
            temp[loc] += ch;
            loc += (down ? 1 : -1);
            //更新down
            if (loc == 0 || loc == numRows - 1) {
                down = !down;
            }
        }
        string ans;
        for (auto str : temp) {
            ans += str;
        }
        return ans;
    }
};
