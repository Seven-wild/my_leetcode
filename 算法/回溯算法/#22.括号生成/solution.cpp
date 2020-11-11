class Solution {
public:
    vector<string> ans;
    string current;
    vector<string> generateParenthesis(int n) {
        int left = 0, right = 0;
        backtrack(left, right, n);
        return ans;
    }
    
    void backtrack(int left, int right, int n) {
        if (left == n && right == n) {
            ans.push_back(current);
            return ;
        }
        if (left < n) {
            current.push_back('(');
            backtrack(left + 1, right, n);
            current.pop_back();
        }
        if (right < left) {
            current.push_back(')');
            backtrack(left, right + 1, n);
            current.pop_back();
        }

    }
};
