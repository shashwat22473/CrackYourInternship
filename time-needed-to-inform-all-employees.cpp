class Solution {
public:
    void dfs(vector<vector<int>> &graph,vector<int> &informTime,int node,int parent,vector<int> &ans){
        for (int x:graph[node]){
            if (x==parent){continue;}
            ans[x]=ans[node]+informTime[node];
            cout<<ans[x]<<endl;
            dfs(graph,informTime,x,node,ans);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for (int i=0;i<n;i++){
            if (i!=headID){
                graph[i].push_back(manager[i]);
                graph[manager[i]].push_back(i);
            }
        }
        vector<int> ans(n,0);
        dfs(graph,informTime,headID,-1,ans);
        int haha=*max_element(ans.begin(),ans.end());
        return haha;

    }
};
