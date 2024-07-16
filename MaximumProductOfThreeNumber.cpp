class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans1=nums[n-1]*nums[n-2]*nums[n-3];
        int ans2=nums[0]*nums[1]*nums[2];
        int ans3=nums[0]*nums[1]*nums[n-1];
        int ans=max(ans1,max(ans2,ans3));
        return ans;
        
    }
};
