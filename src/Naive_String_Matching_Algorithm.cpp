#include <iostream>
#include <string>

using namespace std;
bool machStr(string &s, string &modle);

int main()
{
    string s = "abaabaabcabaabc";
    string modle = "abaabc";//模式串
    cout << machStr(s,modle);
} 

bool machStr(string &s, string &modle){
    int i = 0, j = 0;//双指针遍历
    while (i < s.size() && j < modle.size()){
        if (s[i] != modle[j]){//不匹配时
            i = i - j + 1;//i初始值为0 i = i - j + 1  如果下标从 1 开始，公式会变成 i = i - j + 2。
            j = 0;//j从头开始
        } else {
            i++;
            j++;
            if (j == modle.size()) return true;
        }
    }
    
    return false;
}
