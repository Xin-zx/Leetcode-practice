class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> s;
        vector <string> res;
        for (auto k : words[0]){
            s[k]++;//记录第一个单词的出现次数  为样本
        }
        for (int i = 1; i < words.size(); i++){
            unordered_map<char, int> cur;
            for (char k : words[i]){
                cur[k]++;//记录余下单词的最小出现次数
            }
            for (auto &p : s){//auto 自动匹配要存放的类型
                p.second = min(p.second, cur[p.first]);//更新样本数量的最小值;
            }
        }
            for (auto k : s){
                while (k.second--){//可能有多个重复的字符
                res.push_back(string(1,k.first));//构造函数1个长度
                }
                
            }
        return res;
        
    }
};