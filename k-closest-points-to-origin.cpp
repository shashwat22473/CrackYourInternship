class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> haha;
        int n=points.size();
        for (int i=0;i<n;i++){
            haha.push_back({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
        }
        sort(haha.begin(),haha.end());
        vector<vector<int>> ans;
        for (int i=0;i<k;i++){
            ans.push_back(points[haha[i][1]]);
        }
        return ans;
    }
};
