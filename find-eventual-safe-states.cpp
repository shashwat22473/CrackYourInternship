class Solution {
public:
    vector<int> in_degree;
    queue<int> q;
    vector<int> ans;
    void kahn(vector<vector<int>> &rev){
        while(q.size()>0){
            int f=q.front();q.pop();
            ans.push_back(f);
            for (int x:rev[f]){
                in_degree[x]--;
                if (in_degree[x]==0){q.push(x);}
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        in_degree.assign(n,0);
        vector<vector<int>> rev(n);
        for(int i=0;i<n;i++){
            for (int x:graph[i]){
                rev[x].push_back(i);
            }
        }
        for (int i=0;i<n;i++){
            in_degree[i]=graph[i].size();
            if (in_degree[i]==0){q.push(i);}

        }
        kahn(rev);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
