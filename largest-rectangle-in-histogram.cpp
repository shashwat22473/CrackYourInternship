class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int ans=0;
        for (int i=0;i<heights.size();i++){
            int start=i;
            while(!st.empty() && st.top().first>heights[i]){
                pair<int,int> p=st.top();st.pop();
                ans=max(ans,p.first*(i- p.second));
                start=p.second;
            }
            st.push({heights[i],start});
        }
        int n=heights.size();
        while(!st.empty() && st.top().first>0){
            pair<int,int>p=st.top();st.pop();
            ans=max(ans,p.first*(n-p.second));
        }
        return ans;
    }

};
