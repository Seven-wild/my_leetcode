class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.size() == 0 || s.size() == 0) return ans;
        unordered_map<string, int> mmap;
        // 统计每个单词的数量
        for (auto word : words) {
            mmap[word]++;
        }
        // 每个单词长度
        int word_size = words[0].size();
        // 单词总数量
        int word_num = words.size();
        // 子串长度
        int len = word_size * word_num;
        unordered_map<string, int> tmp;
        for (int i = 0; i + len - 1 < s.size(); i++) {
            int j;
            // 统计s[i .. i+len-1]中每一个单词
            for (j = i; j < i + len; j += word_size) {
                string word = s.substr(j, word_size);
                // 没出现过 break
                if (mmap[word] == 0) {
                    break;
                } else {
                    tmp[word]++;
                    // 出现次数多了 break
                    if (tmp[word] > mmap[word]) {
                        break;
                    }
                }
            }
            // 遍历过整个子串 加入答案
            if (j == i + len) {
                ans.emplace_back(i);
            }
            tmp.clear();
        }
        return ans;
    }
};
