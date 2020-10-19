class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> my_map;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            my_map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (my_map.count(target-nums[i]) != 0 && my_map[target-nums[i]] != i) {
                res.push_back(i);
                res.push_back(my_map[target-nums[i]]);
                break;
            }
        }
        return res;

    }
};
