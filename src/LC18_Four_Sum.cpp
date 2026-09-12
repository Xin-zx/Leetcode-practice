class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());//排序否则双指针无效
        for (int i = 0;i < nums.size(); i++){
            //target 可能为负数
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1,right = nums.size() - 1;
                while (left < right){
                    //四数之和会溢出 要强制转换为long long 型(加括号)
                    //只对一个元素进行强转 后面元素会自动升阶
                    //不能先让四数相加 这样的话已经溢出了
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) right--;
                    else if (sum < target) left++;
                    else{
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1])left++;
                        while(left < right && nums[right] == nums[right - 1])right--;
                        left++,right--;
                    } 
                }
            }
        }
        return res;
    }
};