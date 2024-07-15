class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char x:s){
            if (x=='(' || x=='{' || x=='['){st.push(x);}
            else{
                if (st.size()==0){return false;}
                if (st.top()=='(' && x!=')'){return false;}
                if (st.top()=='{' && x!='}'){return false;}
                if (st.top()=='[' && x!=']'){return false;}
                st.pop();
            }
        }
        if (st.size()>0){return false;}
        return true;
    }
};
