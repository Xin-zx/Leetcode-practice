class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //元素自动保证不重复，只关心元素 “有没有”，不关心出现多少次
        //想到用集合
        unordered_set<int>st(nums1.begin(), nums1.end());//构造函数
        //set集合会自动去重
        vector <int> ans;
        for (auto num : nums2){
            if (st.count(num)){//查找元素
                ans.push_back(num);
                st.erase(num);//去重
            } 
        }
        return ans;
    }
};