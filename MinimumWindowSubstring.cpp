class Solution {
public:
    bool valid(vector<int> a,vector<int> b){
        for (int i=0;i<52;i++){
            if (a[i]<b[i])return false;
        }
        return true;
    }
    int index(char x){
        if (x-'a'>=0){return x-'a';}
        else{return 26+x-'A';}
    }
    string minWindow(string s, string t) {
        vector<int> aim(52,0);
        for (char x:t){
            aim[index(x)]++;
        }   
        pair<int,int> ans={0,s.size()+1};
        int i=0;int j=0;
        vector<int> a(52,0);
        while(j<s.size() && i<s.size()){
            if (valid(a,aim)){
                if (ans.second-ans.first>j-i){
                    ans={i,j};
                }
                a[index(s[i])]--;
                i++;
            }
            else{
                a[index(s[j])]++;
                j++;
            }
        }
        while (valid(a,aim)){
            if (ans.second-ans.first>j-i){
                ans={i,j};
            }
            a[index(s[i])]--;
            i++;
        }
        if (ans.second-ans.first==s.size()+1){return "";}
        return s.substr(ans.first,ans.second-ans.first);
    }
};
