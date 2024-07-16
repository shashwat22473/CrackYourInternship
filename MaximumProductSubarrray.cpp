class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long int p=1;
        long long int ans1=-1e9;
        for (int i=0;i<n;i++){
            p*=nums[i];
            ans1=max(ans1,p);
            if (p==0 || p<-1e9)p=1;
        }
        long long int ans2=-1e9;
        p=1;
        for (int i=n-1;i>=0;i--){
            p*=nums[i];
            ans2=max(ans2,p);
            if (p==0 || p<-1e9){p=1;}
        }
        return max((int)ans1,(int)ans2);
    }
};
