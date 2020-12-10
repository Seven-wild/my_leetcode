1. 两数之和

难度简单

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

示例:

    给定 nums = [2, 7, 11, 15], target = 9
    
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]



思路：

1.哈希表

创建一个哈希表，每次插入x前先判断target - x在不在表中，然后再将x插入，即可保证x不和自己匹配。

代码：

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> hash;
            for (int i = 0; i < nums.size(); i++) {
                if (hash.count(target - nums[i]) != 0) {
                    return {hash[target - nums[i]], i};//注意返回的顺序
                }
                hash[nums[i]] = i;
            }
            return  {};
        }
    };


