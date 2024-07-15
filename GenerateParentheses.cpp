class Solution {
public:
    bool valid(string s){
        int counter=0;
        for (char x:s){
            if (x=='(')counter++;
            else{counter--;}
            if (counter<0)return false;
        }
        if (counter==0)return true;
        return false;
    }
    void sol(vector<string> &ans,int open,int close,string s){
        if (open==0 && close==0){
            cout<<s<<endl;
            if (valid(s))ans.push_back(s);
            return;
        }
        if (open>0){
            sol(ans,open-1,close,s+'(');
        }
        if (close>0){
            sol(ans,open,close-1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        sol(ans,n,n,s);
        return ans;
    }
};
