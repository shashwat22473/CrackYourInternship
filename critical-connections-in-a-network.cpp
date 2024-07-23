class Solution {
public:
    vector<int> low;
    vector<int> dp;
    int count_=0;
    vector<bool> visited;
    vector<vector<int>> ans;
    void dfs(int node,int parent,vector<vector<int>> &graph){
        count_++;
        low[node]=count_;
        dp[node]=count_;
        visited[node]=true;
        for (int x:graph[node]){
            if (x==parent)continue;
            if (visited[x]){
                dp[node]=min(dp[node],low[x]);
            }
            else{
                dfs(x,node,graph);
                dp[node]=min(dp[node],dp[x]);
                if (low[node]<dp[x]){ans.push_back({node,x});}
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low.resize(n);
        dp.resize(n);
        vector<vector<int>> graph(n);
        visited.assign(n,false);
        for (int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        for (int i=0;i<n;i++){
            if (!visited[i]){
                dfs(i,-1,graph);
            }
        }
        return ans;
        
    }
};
