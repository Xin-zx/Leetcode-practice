class Solution {
public:
    string reverseWords(string s) {
        deletespace(s);
        reverse(s.begin(), s.end());
        int flag = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' ') continue;
            //每次遇到空格反转前面的单词
            reverse(s.begin() + flag, s.begin() + i);
            flag = ++i;
        }
        //最后一个单词没有空格
        reverse(s.begin() + flag, s.end());
        return s;
    }
    void deletespace(string &s){
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++){
            //当前的字符不为空我才进入判断
            if (s[fast] != ' '){
                //此时s[slow]已经记录完一个单词了 需要空格;
                if (slow != 0) s[slow++] = ' ';
                while (fast < s.size() && s[fast] != ' '){
                    s[slow++] = s[fast++];
                }
            }
        }
        //slow记录的是单词的长度 //去除无效的长度
        s.resize(slow);
    }
};
