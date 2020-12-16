class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.size() == 0 || s.size() == 0) return ans;
        unordered_map<string, int> mmap;
        for (auto word : words) {
            mmap[word]++;
        }
        int word_size = words[0].size();
        int word_num = words.size();
        int len = word_size * word_num;
        unordered_map<string, int> tmp;
        for (int i = 0; i + len - 1 < s.size(); i++) {
            int j = 0;
            for (j = i; j < i + len; j += word_size) {
                string word = s.substr(j, word_size);
                if (mmap[word] == 0) {
                    break;
                } else {
                    tmp[word]++;
                    if (tmp[word] > mmap[word]) {
                        break;
                    }
                }
            }
            if (j == i + len) {
                ans.emplace_back(i);
            }
            tmp.clear();
        }
        return ans;
    }
};
