class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,int> mapp;
        int n=stones.size();
        for (int i=0;i<stones.size();i++){
            mapp[stones[i]]=i+1;
        }
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        dp[1][1]=true;
        bool ans=false;
        for (int i=1;i<n;i++){
            for (int j=1;j<n;j++){
                if (dp[i][j] && mapp[stones[i-1]+j]!=0){
                    if (mapp[stones[i-1]+j]==n){ans=true;}
                    dp[mapp[stones[i-1]+j]][j]=true;
                    dp[mapp[stones[i-1]+j]][j+1]=true;
                    if (j-1>0)dp[mapp[stones[i-1]+j]][j-1]=true;
                }
            }

        }
        return ans;
        
    }
};
