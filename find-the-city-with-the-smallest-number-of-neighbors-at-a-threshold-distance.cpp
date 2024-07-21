class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for (auto x:edges){
            dp[x[0]][x[1]]=x[2];
            dp[x[1]][x[0]]=x[2];
        }
        for (int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                for (int k=0;k<n;k++){
                    dp[j][k]=min(dp[j][i]+dp[i][k],dp[j][k]);
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                int ans=min(dp[i][j],dp[j][i]);
                dp[i][j]=ans;
                dp[j][i]=ans;
            }
        }
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=-1;
        int count_=n+1;
        for (int i=0;i<n;i++){
            int pp=0;
            for (int j=0;j<n;j++){
                if (dp[i][j]<=distanceThreshold){
                    pp++;
                }
            }
           
             if (pp<=count_){count_=pp;ans=i;}
            cout<< i<<" "<<pp<<endl;
        }
        return ans;
    }
};
