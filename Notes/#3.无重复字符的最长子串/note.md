3. 无重复字符的最长子串

难度中等

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

    输入: s = "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

    输入: s = "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

    输入: s = "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

示例 4:

    输入: s = ""
    输出: 0

 

提示：

- 0 <= s.length <= 5 * 104
- s 由英文字母、数字、符号和空格组成



思路：

1.滑动窗口

用两个指针表示窗口大小，每次将左指针往右移动一格，然后开始往右枚举右指针。用unordered_set来判断重复字符。每次左指针向右移动，删除最右边的字符。

    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> sset;
            int n = s.length();
            int ans = 0, right = -1;
            for (int left = 0; left < n; left++) {
                if (left) {
                    sset.erase(s[left - 1]);
                }
                while (right + 1 < n && sset.count(s[right + 1]) == 0) {
                    sset.insert(s[right + 1]);
                    right++;
                }
                ans = max(ans, right - left + 1);
            } 
            return ans;
        }
    };
