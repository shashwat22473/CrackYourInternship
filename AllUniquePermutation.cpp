class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        bool ans=false;
        int x=0;
        for (int i=0;i<n;i++){
            if (i>x){break;}
            if (i==n-1)ans=true;
            x=max(x,i+nums[i]);
        }
        return ans;
    }
};
