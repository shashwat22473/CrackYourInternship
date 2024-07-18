class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        for (int i=0;i<n;i++){
            while(ans.size()>0 && ans.back()>nums[i] && ans.size()+n-i>k){ans.pop_back();}
            ans.push_back(nums[i]);
        }
        while(ans.size()>k){ans.pop_back();}
        return ans;
    }
};
