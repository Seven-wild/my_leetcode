class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), num(26);
        //记录每个字符的数量
        for (auto ch : s) {
            num[ch - 'a']++;
        }
        string ans;
        for (auto ch : s) {
            //如果待插入字符不在栈中
            if (!vis[ch - 'a']) {
                //待插入待的字符比栈顶字符小
                while (!ans.empty() && ch < ans.back()) {
                    //如果栈顶字符在后面还有就弹出
                    if (num[ans.back() - 'a'] > 0) {
                        vis[ans.back() - 'a'] = 0;
                        ans.pop_back();
                    } else {
                        break;
                    }
                }
                ans.push_back(ch);
                vis[ch - 'a'] = 1;
            } 
            //数量减一
            num[ch - 'a'] -= 1;
        }
        return ans;
    }
};
