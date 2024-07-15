class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<n){
            int a=-(nums[i]);
            int j=i+1;int k=n-1;
            while(j<k){
                int p=nums[j]+nums[k];
                if (p==a && j!=i && k!=i){
                    vector<int> g={nums[i],nums[j],nums[k]};
                    cout<<i<<" "<<j<<" "<<k<<endl; 
                    cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                    ans.push_back(g);
                    int left=nums[j];
                    int right=nums[k];
                    while(j<n && nums[j]==left){j++;}
                    while(k>j && nums[k]==right){k--;}
                }
                else if (p<a){j++;}
                else{k--;}
            }
            int y=nums[i];
            while(i<n && y==nums[i]){i++;}
        }
        return ans;
    }
};
