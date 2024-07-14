class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        set<pair<int,int>> s;
        int i=0;int j=0;
        int n=points.size();
        int ans=-1e9;
        
        while(i<n-1){
            if (j==n){
                s.erase({points[i][0]+points[i][1],points[i][0]});
                pair<int,int> t=*s.rbegin();

                ans=max(ans,points[i][1]+t.first-points[i][0]);
                s.erase({points[i][0]+points[i][1],points[i][0]});
                i++;
                continue;
            }
            if (points[j][0]-points[i][0]>k){
                s.erase({points[i][0]+points[i][1],points[i][0]});
                if (s.size()==0){i++;continue;}
                pair<int,int> t=*s.rbegin();
                ans=max(ans,points[i][1]+t.first-points[i][0]);
                cout<<t.first<<" "<<t.second<<" "<<i<<endl;
                i++;
                cout<<ans<<endl;
            }
            else{
                s.insert({points[j][0]+points[j][1],points[j][0]});
                j++;
            }
        }
        return ans;
    }
};
