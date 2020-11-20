class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        word_set.erase(beginWord);
        queue<string> que;
        que.push(beginWord);
        int step = 1;
        visited.insert(beginWord);
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
                       if (word_set.find(temp) != word_set.end() && visited.find(temp) == visited.end()) {
                           if (temp == endWord) return step + 1;
                           que.push(temp);
                           visited.insert(temp);
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
