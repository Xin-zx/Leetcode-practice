class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector <int> next = getNext(s);//得到next数组
        int len = next[next.size() - 1];//如果s是由重复的字串构成那么最长相等前后缀不包含的长度就是子串
        if (next[s.size() - 1] != 0 && s.size() % (s.size() - len) == 0) return true;
        else return false;
    }
    vector<int> getNext(string &s){
        vector<int> next(s.size());
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++){
            while (j > 0 && s[j] != s[i]){
                j = next[j - 1];
            }
            if (s[i] == s[j]) j++;
            next[i] = j;
        }
        return next;
    }
};