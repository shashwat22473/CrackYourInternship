#define ff first
#define ss second

class Solution {
public:
    bool valid(pair<int,int> f, pair<int,int> x ,int n){
        if (f.ff+x.ff<n && f.ff+x.ff>=0 && f.ss+x.ss<n && f.ss+x.ss>=0){return true;}
        return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;

        vector<vector<int>> dis(n,vector<int> (n,1e9));
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1){dis[i][j]=0;q.push({i,j});}
            }
        }
        if (q.size()==n*n || q.size()==0)return -1;
        vector<pair<int,int>> haha={{-1,0},{0,-1},{1,0},{0,1}};
        int ans=0;
        while(!q.empty()){
            pair<int,int> f=q.front();q.pop();
            for (pair<int,int> x:haha){
                if (valid(f,x,n) && grid[f.ff+x.ff][f.ss+x.ss]==0 && dis[f.ff+x.ff][f.ss+x.ss]==1e9){
                    dis[x.ff+f.ff][x.ss+f.ss]=dis[f.ff][f.ss]+1;
                    ans=max(dis[x.ff+f.ff][x.ss+f.ss],ans);
                    q.push({x.ff+f.ff,x.ss+f.ss});
                }
            }
        } 
        return ans;

    }
};
