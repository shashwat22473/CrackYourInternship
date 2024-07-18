class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> mapp;
        for (vector<int> x:adjacentPairs){
            mapp[x[0]].push_back(x[1]);
            mapp[x[1]].push_back(x[0]);
        }
        map<int,bool> map1;
        int start=0;
        for (auto x:mapp){
            if (x.second.size()==1){start=x.first;break;}
        }
        queue<int> q;
        q.push(start);
        map1[start]=true;
        vector<int> ans;
        while(!q.empty()){
            int x=q.front();
            ans.push_back(x);
            q.pop();
            for (int y:mapp[x]){
                if (!map1[y]){q.push(y);map1[y]=true;}
            }
        }
        return ans;
    }
};
