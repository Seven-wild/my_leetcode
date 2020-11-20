class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        word_set.erase(beginWord);
        queue<string> que;
        que.push(beginWord);
        int step = 1;
        while (!que.empty()) {
            int qsize = que.size();
            while (qsize--) {
               string temp = que.front();
               que.pop();
               for (int i = 0; i < temp.length(); i++) {
                   char now = temp[i];
                   for (int j = 0; j < 26; j++) {
                       if ((char)('a' + j) == now) continue;
                       temp[i] = char('a' + j);
                       if (word_set.find(temp) != word_set.end()) {
                           if (temp == endWord) return step + 1;
                           que.push(temp);
                           word_set.erase(temp);
                       }
                   }
                   temp[i] = now;
               }
            }
            step++;
        }
        return 0;
    }
};
/*********************双向BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto words = unordered_set<string>(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        auto visited = unordered_set<string>();
        auto begin_vis = unordered_set<string>();
        auto end_vis = unordered_set<string>();
        begin_vis.insert(beginWord);
        end_vis.insert(endWord);
        visited.insert(beginWord);
        visited.insert(endWord);
        int step = 1;
        while (!begin_vis.empty() && !end_vis.empty()) {
            if (begin_vis.size() > end_vis.size()) {
                swap(begin_vis, end_vis);
            }
            auto next_begin_vis = unordered_set<string>();
            for (auto word : begin_vis) {
                for (int i = 0; i < word.size(); i++) {
                    char now = word[i];
                    for (int j = 0; j < 26; j++) {
                        if (char('a' + j) == now) continue;
                        word[i] = char('a' + j);
                        if (words.count(word)) {
                            if (end_vis.count(word)) {
                                return step + 1;
                            }
                            if (!visited.count(word)) {
                                next_begin_vis.insert(word);
                                visited.insert(word);
                            }
                        }
                    }
                    word[i] = now;
                }
            }
            begin_vis = next_begin_vis;
            step++;
        }
        return 0;


    }
};
*/
