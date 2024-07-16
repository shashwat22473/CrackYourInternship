class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        dp[0][0]=grid[0][0];
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (i+1<m){dp[i+1][j]=min(dp[i][j]+grid[i+1][j],dp[i+1][j]);}
                if (j+1<n){dp[i][j+1]=min(dp[i][j]+grid[i][j+1],dp[i][j+1]);}
            }
        }
        return dp[m-1][n-1];
    }
};
