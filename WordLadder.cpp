class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag=false;
        unordered_map<string,bool> mapp;
        for (string s:wordList){mapp[s]=true;}
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            pair<string,int> haha=q.front();
            q.pop();
            if (haha.first==endWord){return haha.second;}
            vector<string> ss;
            for (auto x:mapp){
                int diff=0;
                for (int j=0;j<haha.first.size();j++){
                    if (haha.first[j]!=x.first[j])diff++;
                }
                if (diff==1){q.push({x.first,haha.second+1});ss.push_back(x.first);}
            }
            for (string s:ss){
                mapp.erase(s);
            }
        }
        return 0;

        
    }
};
