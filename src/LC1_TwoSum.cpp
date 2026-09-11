class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 哈希表：key=数组里的数值，value=该数值对应的下标
        unordered_map<int, int>s;
        // 存放答案两个下标
        vector <int> ans;
        for (int i = 0; i < nums.size(); i++){
            // 我们需要找的另一半数字：target - 当前nums[i]
            int num = target - nums[i];
            // 如果哈希表里面存在这个另一半数字
            if (s.count(num)){
                // 存入之前找到的数字下标
                ans.push_back(s[num]);
                // 存入当前数字下标
                ans.push_back(i);
            }
            // 把当前数字和下标放进哈希表，供后面元素查找
            s[nums[i]] = i;
        }
        return ans;
    }
};
