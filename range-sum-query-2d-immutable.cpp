class NumMatrix {
public:
    vector<vector<int>> haha;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        haha.resize(m+1);
        for (int i=0;i<=m;i++){
            haha[i].resize(n+1);
        }
        for (int i=0;i<=m;i++){
            for (int j=0;j<=n;j++){
                haha[i][j]=0;
            }
        }
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                haha[i][j]=haha[i-1][j]+haha[i][j-1]-haha[i-1][j-1]+matrix[i-1][j-1];
                cout<<haha[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return haha[row2+1][col2+1]-haha[row2+1][col1]-haha[row1][col2+1]+haha[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
