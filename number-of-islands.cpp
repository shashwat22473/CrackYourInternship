class Solution {
public:
    bool valid (int m,int n, pair<int,int> xx,int x,int y){
        if (x+xx.first<m && x+xx.first>=0 && y+xx.second<n && y+xx.second>=0){return true;}
        return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans=0;
        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]=='1' && !visited[i][j]){
                    cout<<i<<" "<<j<<endl;
                    stack<pair<int,int>> st;
                    st.push({i,j});
                    visited[i][j]=true;
                    while(!st.empty()){
                        pair<int,int> f=st.top();
                        st.pop();
                        for (auto x:dir){
                            if (valid (m,n,x,f.first,f.second) && !visited[f.first+x.first][f.second+x.second] && grid[f.first+x.first][f.second+x.second]=='1'){
                                visited[f.first+x.first][f.second+x.second]=true;
                                st.push({f.first+x.first,f.second+x.second});
                            }
                        }

                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};
