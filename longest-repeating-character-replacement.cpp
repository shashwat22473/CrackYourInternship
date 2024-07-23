class Solution {
public:
    int characterReplacement(string s, int k) {
        string tt="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int n=s.size();
        int ans=0;
        for(int i=0;i<26;i++){
            int j=0;int p=0;
            int curr=0;
            while(p<n && j<n){
                if(s[p]==tt[i]){p++;}
                else{
                    if (curr<k){p++;curr++;}
                    else{
                        if (s[j]!=tt[i])curr--;
                        j++;
                        if (j>p){p=j;}
                    }
                }
                ans=max(ans,p-j);
            }
        }
        return ans;
    }
};
