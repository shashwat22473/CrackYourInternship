class Solution {
public:
    int getParent(int x,vector<int>&parent){
        if (parent[x]==x){return x;}
        return parent[x]=getParent(parent[x],parent);
    }
    void connect(int x,int y,vector<int> &size,vector<int> &parent){
        int parent_x=getParent(x,parent);
        int parent_y=getParent(y,parent);
        if (size[x]>size[y]){swap(parent_x,parent_y);}
        parent[parent_x]=parent_y;
        size[parent_y]+=parent[parent_x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> parent(n);
        vector<int> size(n);
        for (int i=0;i<n;i++){
            size[i]=1;
            parent[i]=i;
        }
        vector<int> ans;
        for (int i=0;i<edges.size();i++){
            if (getParent(edges[i][0],parent)==getParent(edges[i][1],parent)){ans=edges[i];}
            else {connect( edges[i][0], edges[i][1],size,parent);}
        }
        return ans;
    }
};
