class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        map<int,pair<int,int>> mapp;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                mapp[grid[i][j]]={i,j};
            }
        }
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        priority_queue<int,vector<int>,greater<int>> pq;
        visited[0][0]=true;
        pq.push(grid[0][0]);
        while(!pq.empty()){
            int p=pq.top();pq.pop();
            if (mapp[p].first>0 && !visited[mapp[p].first-1][mapp[p].second]){
                visited[mapp[p].first-1][mapp[p].second]=true;
                pq.push(grid[mapp[p].first-1][mapp[p].second]);
                grid[mapp[p].first-1][mapp[p].second]=max(grid[mapp[p].first-1][mapp[p].second],grid[mapp[p].first][mapp[p].second]);
            }
            if (mapp[p].first<n-1 && !visited[mapp[p].first+1][mapp[p].second]){
                visited[mapp[p].first+1][mapp[p].second]=true;
                pq.push(grid[mapp[p].first+1][mapp[p].second]);
                grid[mapp[p].first+1][mapp[p].second]=max(grid[mapp[p].first+1][mapp[p].second],grid[mapp[p].first][mapp[p].second]);
            }
            if (mapp[p].second>0 && !visited[mapp[p].first][mapp[p].second-1]){
                visited[mapp[p].first][mapp[p].second-1]=true;
                pq.push(grid[mapp[p].first][mapp[p].second-1]);
                grid[mapp[p].first][mapp[p].second-1]=max(grid[mapp[p].first][mapp[p].second-1],grid[mapp[p].first][mapp[p].second]);
            }
            if (mapp[p].second<n-1 && !visited[mapp[p].first][mapp[p].second+1]){
                visited[mapp[p].first][mapp[p].second+1]=true;
                pq.push(grid[mapp[p].first][mapp[p].second+1]);
                grid[mapp[p].first][mapp[p].second+1]=max(grid[mapp[p].first][mapp[p].second+1],grid[mapp[p].first][mapp[p].second]);
            }
        }
        return grid[n-1][n-1];

    }
};
