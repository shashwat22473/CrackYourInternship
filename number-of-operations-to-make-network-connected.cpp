class Solution {
public:
    void dfs(int node,vector<vector<int>> &graph,vector<bool> &visited ){
        visited[node]=true;
        for (int x:graph[node]){
            if(visited[x])continue;
            dfs(x,graph,visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1){return -1;}
        vector<vector<int>> graph(n);
        for (vector<int> x:connections){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n,false);
        int ans=0;
        for (int i=0;i<n;i++){
            if (!visited[i]){
                dfs(i,graph,visited);
                ans++;
            }
        }
        return ans-1;

    }
};
