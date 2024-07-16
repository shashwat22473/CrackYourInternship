class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e9);
        dp[0]=0;
        for (int i=0;i<coins.size();i++){
            for (int j=0;j<=amount;j++){
                if (j+(long long)coins[i]<=(long long )amount){dp[j+coins[i]]=min(dp[j+coins[i]],dp[j]+1);}
            }
        }
        if (dp[amount]==1e9){return -1;}
        else{return dp[amount];}
    }
};
