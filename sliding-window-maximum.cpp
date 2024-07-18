class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int,int>> s;
        for (int i=0;i<k;i++){
            s.insert({nums[i],i});
        }
        int n=nums.size();
        vector<int> ans;
        for (int i=k-1;i<n;i++){
            ans.push_back(s.rbegin()->first);
            s.erase({nums[i-k+1],i-k+1});
            if (i+1<n){s.insert({nums[i+1],i+1});}
        }
        return ans;
    }
};
