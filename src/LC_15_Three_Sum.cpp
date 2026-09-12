class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());//为了方便双指针判断大小
        vector<vector <int> > res;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0) break;//倘如第一个值大于零就不会出现小于零的了
            if (i > 0 && nums[i] == nums[i - 1]) continue;//去重防止结果一致
            int left = i  + 1;//左指针从第一个值的右边判断
            int right = nums.size() - 1;//右指针
            while (left < right){//left != right 否则就变为两数之和了
            //sum 在循环内部缩小或增大才会变化
            int sum  = nums[i] + nums[left] + nums[right];//计算三数之和
                  if (sum > 0) right--;//缩小值(已排序)
                  else if (sum < 0) left++;//增大值(已排序)
                  else{
                    res.push_back({nums[i],nums[left],nums[right]});//二维数组可一次多个元素唯一组
                    //left去重防止重复三元组
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    //right去重防止重复三元组
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++,right--;
                  }
            }
        }
        return res;
    }
};