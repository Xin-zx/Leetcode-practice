#include <iostream>
#include <cctype>

using namespace std;

int main(){
    string s;
    string result;
    cin >> s;

    for (auto &c : s){
        if (isdigit(c)){
            result += "number";
        } else {
            result +=c;
        }
        
    }
        cout << result;
    return 0;
}