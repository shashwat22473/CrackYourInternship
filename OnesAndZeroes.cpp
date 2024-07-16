class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        vector<vector<int>> haha(m+1,vector<int>(n+1,0));
        dp[0][0]=true;
        int siz=strs.size();
        for (int i=0;i<siz;i++){
            int count_1=0;int count_2=0;
            for (char x:strs[i]){
                if (x=='0')count_1++;
                else{count_2++;}
            }
            for (int j=m;j>=0;j--){
                for (int k=n;k>=0;k--){
                    if (dp[j][k] && j+count_1<=m && k+count_2<=n){
                        haha[j+count_1][k+count_2]=max(haha[j][k]+1,haha[j+count_1][k+count_2]);
                        dp[j+count_1][k+count_2]=true;
                    }
                }
            }
        }
        int ans=0;
        for (int i=0;i<=m;i++){
            for (int j=0;j<=n;j++){
                ans=max(ans,haha[i][j]);
            }
        }
        return ans;
    }
};
