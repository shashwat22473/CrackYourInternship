class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;
        for (int x:nums){mapp[x]++;}
        priority_queue<pair<int,int>> pq;
        for (auto x:mapp){
            pq.push({x.second,x.first});
        }
        vector<int> ans;
        for (int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};
