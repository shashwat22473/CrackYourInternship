class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mapp;
        mapp[0]=1;
        int ans=0;
        int summ=0;
        for(int i=0;i<n;i++){
            summ+=nums[i];
            ans+=mapp[summ-k];
            mapp[summ]++;
        }
        return ans;
    }
};
