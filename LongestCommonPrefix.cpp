class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int siz=200;
        for (string x:strs){
            siz=min(siz,(int)x.size());
        }
        string ans;

        for (int i=0;i<siz;i++){
            bool flag=true;
            for (int j=0;j<strs.size()-1;j++){
                if (strs[j][i]!=strs[j+1][i]){flag=false;}
            }
            if (!flag){return ans;}
            else{
                ans+=strs[0][i];
            }
        }
        return ans;
    }
};
