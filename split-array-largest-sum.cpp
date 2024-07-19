class Solution {
public:
    bool checker(vector<int> &nums,int k,int val){
        int count_=0;
        for (int i=0;i<nums.size();i++){
            count_+=nums[i];
            if (count_>val){k--;count_=nums[i];}
        }
        return k>0;
    }
    int splitArray(vector<int>& nums, int k) {
        int ans=1e9;
        int mid;
        int high=1e9;int low=*max_element(nums.begin(),nums.end());
        while(low<=high){
            mid=low+(high-low)/2;
            if (checker(nums,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
