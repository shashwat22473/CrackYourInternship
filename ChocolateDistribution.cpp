class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=1e9;
        int ans=0;
        int n=prices.size();
        for (int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            ans=max(ans,prices[i]-mini);
        }
        return ans;
    }
};
