class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++){
            //注意数组中储存的是string类型的元素
            if (tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "*" && tokens[i] != "-"){
                st.push(stoi(tokens[i]));
            } else {
                //注意 string 来接
                int rnum = st.top();
                st.pop();
                int lnum = st.top();
                st.pop();
                int res = 0;
                string s = tokens[i];
            if(s == "+"){
                res = lnum + rnum;
            } else if(s == "-"){
                res = lnum - rnum;
            } else if(s == "*"){
                res = lnum * rnum;
            } else if(s == "/"){
                res = lnum / rnum;
            }
                st.push(res);
            }
        }
        int ans = st.top();
        return ans;
    }
};
