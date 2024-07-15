class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> haha;
        for (int i=0;i<n;i++){
            haha.push_back({nums[i],i});
        }
        sort(haha.begin(),haha.end());
        int i=0;int j=n-1;
        while(i<j){
            if (haha[i].first+haha[j].first==target){
                return {haha[i].second,haha[j].second};
            }
            else if(haha[i].first+haha[j].first>target){
                j--;
            }
            else {
                i++;
            }
        }
        return {0,0};
    }
};
