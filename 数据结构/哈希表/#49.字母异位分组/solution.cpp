class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, int> my_map;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (my_map.count(temp) == 0) {
                ans.push_back({strs[i]});
                my_map[temp] = ans.size() - 1;
            } else {
                ans[my_map[temp]].push_back(strs[i]);
            }
        }
        return ans;
    }
};
