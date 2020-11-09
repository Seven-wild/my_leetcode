class Solution {
public:
    vector<string> ans;
    string temp;
    const string letter_map[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return ans;
        dfs(0, digits);
        return ans;
    }
    void dfs(int idx, string digits) {
        if (idx == digits.length()) {
            ans.push_back(temp);
            return;
        }
        int digit = digits[idx] - '0';
        string letters = letter_map[digit];
        for (int i = 0; i < letters.length(); i++) {
            temp.push_back(letters[i]);
            dfs(idx + 1, digits);
            temp.pop_back();
        }
    }


};
