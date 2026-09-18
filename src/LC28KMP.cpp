class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;//空字符是任何字符的起点
        vector <int> next = getNext(needle);//next 数组存储的是当前最长相等前后缀的长度
        int j = 0;//前缀末尾
        for (int i = 0; i < haystack.size(); i++){
            while (j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
                //前面已经匹配过的后缀和模式串的前缀相同，所以直接从前缀的后面继续比，不需要从头再来
                //跳跃到的位置是相等前后缀的下一个位置 因为前面和后面相等就不需要再重新匹配了
            }
            if (haystack[i] == needle[j]) j++;//匹配成功j向后移动
            if (j == needle.size()){  //匹配完成
                return i - j + 1;// i 为下标 （j - 1） 为下标
                //所以 i - j + 1为下标
            } 
        }
        return -1;

    }
    vector<int> getNext(string &needle){
        vector<int> next(needle.size());
        int j = 0;//j代表前缀末尾 也是最长相等前后缀的长度
        next[0] = 0;//初始化next数组
        for (int i = 1; i < needle.size(); i++){//i代表后缀末尾
            while (j > 0 && needle[j] != needle[i]){//j是一个不断跳跃匹配的过程
                j = next[j - 1];//j回跳到前一个数记录的值（当前为最长相等前后缀的值）
            }
            if (needle[i] == needle[j]) j++;
            next[i] = j;
        }
        return next;
    }
        
};