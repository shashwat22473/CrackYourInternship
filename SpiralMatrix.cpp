class Solution {
public:
    bool valid(int x,int y,map<pair<int,int>,bool> &mapp,int m,int n,vector<vector<int>>& matrix){
        if (x<m && x>=0 && y<n && y>=0 && !mapp[{x,y}]){
            return true;
        }
        return false;
    }


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        map<pair<int,int>,bool> mapp;
        vector<int> ans;
        bool neighbour_exist=true;
        int curr_dir=0;
        int x,y;
        x=0;y=0;
        while(neighbour_exist){
            if (curr_dir==0){
                ans.push_back(matrix[x][y]);
                mapp[{x,y}]=true;
                if (valid(x,y+1,mapp,m,n,matrix)){
                    y++;
                }
                else{
                    if (valid(x+1,y,mapp,m,n,matrix)){
                        curr_dir=1;
                        x++;
                    }
                    else{
                        neighbour_exist=false;
                    }
                }
            }
            else if (curr_dir==1){
                ans.push_back(matrix[x][y]);
                mapp[{x,y}]=true;
                if (valid(x+1,y,mapp,m,n,matrix)){
                    x++;
                }
                else{
                    if (valid(x,y-1,mapp,m,n,matrix)){
                        curr_dir=2;
                        y--;
                    }
                    else{
                        neighbour_exist=false;
                    }
                }
            }  
            else if (curr_dir==2){
                ans.push_back(matrix[x][y]);
                mapp[{x,y}]=true;
                if (valid(x,y-1,mapp,m,n,matrix)){
                    y--;
                }
                else{
                    if (valid(x-1,y,mapp,m,n,matrix)){
                        curr_dir=3;
                        x--;
                    }
                    else{
                        neighbour_exist=false;
                    }
                }
            }
            
            else if (curr_dir==3){
                ans.push_back(matrix[x][y]);
                mapp[{x,y}]=true;
                if (valid(x-1,y,mapp,m,n,matrix)){
                    x--;
                }
                else{
                    if (valid(x,y+1,mapp,m,n,matrix)){
                        curr_dir=0;
                        y++;
                    }
                    else{
                        neighbour_exist=false;
                    }
                }
            }                      
        }
        return ans;


        
    }
};
