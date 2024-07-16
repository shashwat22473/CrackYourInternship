class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<pair<int,int>>> bakchodi(n,vector<pair<int,int>>(n,{0,0}));
        for (int i=0;i<n;i++){
            pair<int,int> haha;haha.first=prices[i];haha.second=prices[i];
            int curr_min=prices[i];int curr_max=prices[i];bool flag=true;
            for (int j=i;j<n;j++){
                if (flag){
                    if (curr_min>prices[j]){curr_min=prices[j];flag=false;}
                    if (curr_max<=prices[j]){curr_max=prices[j];haha.second=curr_max;}
                }
                else{
                    if (curr_min>prices[j]){curr_min=prices[j];}
                    if (haha.second-haha.first<=prices[j]-curr_min){curr_max=prices[j];flag=true;haha.first=curr_min;haha.second=curr_max;}
                    if (curr_max<=prices[j]){curr_max=prices[j];flag=true;haha.first=curr_min;haha.second=curr_max;}
                }
                bakchodi[i][j]=haha;
            }

        }
        // for (int i=0;i<n;i++){
        //     for (int j=i;j<n;j++){
        //         cout<<bakchodi[i][j].second-bakchodi[i][j].first<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>> dp(n,vector<int> (k,0));
        for (int i=0;i<n;i++){
            dp[i][0]=bakchodi[0][i].second-bakchodi[0][i].first;
        }
        for(int i=0;i<k-1;i++){
            for (int j=0;j<n;j++){
                for (int p=1;p<j;p++){
                    dp[j][i+1]=max(dp[j][i+1],dp[p-1][i]+bakchodi[p][j].second-bakchodi[p][j].first);
                }
            }
        }
        int ans=0;
        for (int i=0;i<k;i++){
            for (int j=0;j<n;j++){
                ans=max(ans,dp[j][i]);
                // cout<<dp[j][i]<<" ";
            }
            // cout<<endl;
        }
        return ans;
    }
};
