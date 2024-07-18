class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        map<char,int> mapp;
        for (int i=0;i<n;i++){
            mapp[s[i]]++;
        }
        vector<int> haha(n+1,0);
        for (auto x:mapp){
            haha[x.second]++;
        }
        int ans=0;
        for (int i=n;i>=1;i--){
            if (haha[i]>1){ans+=haha[i]-1;haha[i-1]+=haha[i]-1;}
        }
        return ans;
    }
};
