class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> haha;
        map<int,int> mapp;
        sort(nums.begin(),nums.end());
        haha.push_back(nums[0]);
        mapp[nums[0]]++;
        for (int i=1;i<nums.size();i++){
            mapp[nums[i]]++;
            if (haha.back()!=nums[i]){haha.push_back(nums[i]);}
        }

        for (int x:haha){cout<<x<<" "<<mapp[x]<<endl;}
        int n=haha.size();
        vector<int> dp(n+1,0);
        vector<int> dp1(n+1,0);
        dp[1]=haha[0]*mapp[haha[0]];
        int ans=dp[1];
        dp1[1]=ans;
        for (int i=1;i<n;i++){
            if (haha[i]-haha[i-1]>1){dp[i+1]=max(dp1[i]+haha[i]*mapp[haha[i]],dp[i+1]);}
            if (i>0){dp[i+1]=max(dp1[i-1]+haha[i]*mapp[haha[i]],dp[i+1]);}
            dp1[i+1]=max(dp1[i],dp[i+1]);
        }
        return dp1[n];
        
    }
};
