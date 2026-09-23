class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (auto ch : s){//遍历字符串
            if (!ans.empty() && ans.back() == ch){//ans非空且尾部元素与添加的元素相等
                ans.pop_back();//尾部元素出栈
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
