#define ff first
#define ss second
class Solution {
public:
    bool valid (int m,int n, pair<int,int> x,int i,int j){
        if ((i+x.ff) < m  && (j+x.ss)<n && (j+x.ss)>=0 && (i+x.ff)>=0){return true;}
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int og=image[sr][sc];
        visited[sr][sc]=true;
        stack<pair<int,int>> st;
        image[sr][sc]=color;
        st.push({sr,sc});
        vector<pair<int,int>> haha={{1,0},{-1,0},{0,1},{0,-1}};
        while(!st.empty()){
            pair<int,int> f=st.top();st.pop();
            cout<<f.ff<<" "<<f.ss<<endl;
            for (auto x:haha){
                if (valid (m,n,x,f.ff,f.ss) && !visited[f.ff+x.ff][f.ss+x.ss] && image[f.ff+x.ff][f.ss+x.ss]==og ){
                    st.push({f.ff+x.ff,f.ss+x.ss});
                    visited[x.ff+f.ff][x.ss+f.ss]=true;
                    image[x.ff+f.ff][x.ss+f.ss]=color;
                }
            }
        }
        return image;

    }
};
