# LeetCode-TwoSum

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i])) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
--------------------- 
作者：Mark-Wang 
来源：CSDN 
原文：https://blog.csdn.net/wanghuan1990519wha/article/details/88981498 
版权声明：本文为博主原创文章，转载请附上博文链接！
