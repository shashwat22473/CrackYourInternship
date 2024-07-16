class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mapp;
        for (int i=0;i<strs.size();i++){
            vector<int> haha(26,0);
            for (char x:strs[i]){
                haha[x-'a']++;
            }
            mapp[haha].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto x:mapp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
