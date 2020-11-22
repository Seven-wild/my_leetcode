class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;
        queue<string> que;
        que.push("0000");
        visited.insert("0000");
        int step = 0;
        while (!que.empty()) {
            int qsize = que.size();
            while (qsize--) {
                string current = que.front();
                que.pop();
                for (int i = 0; i < 4; i++) {
                    string temp = current;
                    temp[i] += 1;
                    if (temp[i] > '9') temp[i] = '0';
                    if (temp == target) {
                        return step + 1;
                    }
                    if (!visited.count(temp)) {
                        que.push(temp);
                        visited.insert(temp);
                    }
                    temp = current;
                    temp[i] -= 1;
                    if (temp[i] < '0') temp[i] = '9';
                    if (temp == target) {
                        return step + 1;
                    }
                    if (!visited.count(temp)) {
                        que.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
