class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int j=n-1;
        int i=0;
        while(i<j){
            ans=max(ans,(j-i)*(min(height[i],height[j])));
            cout<<i<<" "<<j<<" "<<ans<<endl;
            if (height[j]>=height[i]){
                i++;
            }
            else{j--;}
        }
        return ans;
        
    }
};
