class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int arr[k];
        for (int i=0;i<k;i++){
            arr[i]=0;
        }
        arr[0]=1;
        int ans=0;
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans+=arr[(k+(sum%k))%k];
            arr[(k+(sum%k))%k]++;
        }
        return ans;
    }
};
