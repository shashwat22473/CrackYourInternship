class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,(int)1e5);
        for (int x:nums){
            int gg=lower_bound(dp.begin(),dp.end(),x)-dp.begin();
            dp[gg]=x;
        }
        int ans=0;
        for (int i=n-1;i>=0;i--){
            if (dp[i]!=1e5){return i+1;}
        }
        return 0;
    }
};
