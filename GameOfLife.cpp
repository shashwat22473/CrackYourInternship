class Solution {
public:
    bool valid(int i,int j,pair<int,int> x,int m,int n){
        if (i+x.first>=0 && i+x.first<m && j+x.second>=0 && j+x.second<n){
            return true;
        }
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        vector<pair<int,int>> dir;
        dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int count=0;
                for (auto x:dir){
                    if (valid(i,j,x,m,n) && board[i+x.first][j+x.second]==1){count++;}
                }
                cout<<i<<" "<<j<<" "<<count<<endl;
                if (count<2){ans[i][j]=0;}
                else if (count==3){ans[i][j]=1;}
                else if (count>3){ans[i][j]=0;}
                else if (count==2){
                    ans[i][j]=board[i][j];
                }
            }
        }
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=ans[i][j];
            }
        }
        
    }
};
