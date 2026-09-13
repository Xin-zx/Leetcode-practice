class Solution {
public:
    string reverseStr(string s, int k) {
        int count = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i += 2 * k){//2k每次向后移动
            if (i + k <= s.size()){ //新的开头的后两个不能超出范围
                reverse(s.begin() + i, s.begin() + i + k);//每次的开头 和开头的后两个
                continue;
            }
            reverse(s.begin() + i, s.end());
        }
        return s;
    }
};