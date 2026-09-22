class Solution {
public:
    bool isValid(string s) {
        stack <char> st;//定义一个栈
        for (auto p : s){//遍历栈中的元素
        //倘若为左括号就压入栈中
            if (p == '(' || p == '[' || p == '{') st.push(p);
            else{
                if (st.empty()) return false;//如果栈为空则 右括号 单身
                char cmp = st.top();//获取左括号（栈顶）
                st.pop();//栈顶出栈
                //倘如不匹配就返回false
                if (cmp == '(' && p != ')') return false;
                if (cmp == '{' && p != '}') return false;
                if (cmp == '[' && p != ']') return false;
            }
        }
        //所有匹配之后 倘如栈不为空则 左括号 单身
        return st.empty();
    }
};