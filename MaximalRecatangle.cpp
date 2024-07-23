class Solution {
public:
    int ans(vector<int> &haha){
        int n=haha.size();
        stack<pair<int,int>> st;
        int ans=0;
        for (int i=0;i<haha.size();i++){
            int start=i;
            while(!st.empty() && st.top().first>haha[i]){
                start=st.top().second;
                ans=max(ans,st.top().first*(i-st.top().second));
                st.pop();
            }
            st.push({haha[i],start});

        }
        while(!st.empty() && st.top().first>0){
                ans=max(ans,st.top().first*(n-st.top().second));
                st.pop();
            }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> haha(col,0);
        int huha=0;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (matrix[i][j]=='1'){
                    haha[j]++;
                }
                else{haha[j]=0;}
            }
            huha=max(ans(haha),huha);

        }
        return huha;
    }
};
